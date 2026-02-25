#include "../../minishell.h"

//verifica se o nome é um identificador válido (começa com letra ou _ e só tem letras, números ou _)
static int	is_valid_identifier(char *name)
{
	int	i;

	if (!name || (!ft_isalpha((unsigned char)name[0]) && name[0] != '_'))
		return (0);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum((unsigned char)name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

// Imprime uma variável no formato "declare -x VAR="value"" pra ficar igual ao export sem argumentos do bash
static void	print_declared(char *env)
{
	char	*eq;

	ft_putstr_fd("declare -x ", 1);
	eq = ft_strchr(env, '=');
	if (!eq)
	{
		ft_putstr_fd(env, 1);
		ft_putchar_fd('\n', 1);
		return ;
	}
	write(1, env, eq - env);
	ft_putstr_fd("=\"", 1);
	ft_putstr_fd(eq + 1, 1);
	ft_putstr_fd("\"\n", 1);
}

// Processa cada arg do export, verificando se é válido e atualizando envs
static int	process_arg(char *arg, t_ms *shell)
{
	char	*eq;
	char	*key;

	eq = ft_strchr(arg, '=');
	//se tiver = a key (variavel) é a parte anterior à isso
	if (eq)
		key = ft_substr(arg, 0, eq - arg);
	//se nao tiver =, a key é a string toda
	else
		key = ft_strdup(arg);
	//se nao tiver nao ha o que analisar
	if (!key)
		return (1);
	//se nao for valido, imprimi em STDERR e retorna 1 para erro 
	if (!is_valid_identifier(key))
	{
		ft_putstr_fd("minishell: export: '", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		free(key);
		return (1);
	}
	//se for valido e tiver =, atualiza o valor da variavel
	if (eq)
		update_env_val(key, eq + 1, shell);
	free(key);
	return (0);
}

// Implementação
void	builtin_export(char **args, t_ms *shell)
{
	int	i;
	int	status;

//Se for só export sem arg
	if (!args[1])
	{
		i = 0;
		while (shell->envs[i])
			print_declared(shell->envs[i++]);
		shell->last_status = 0;
		return ;
	}
	i = 1;
	status = 0;
	//assumindo que já é export com arg, processa cada um
	while (args[i])
	{
		//se der erro, salva o erro em exit_code
		if (process_arg(args[i], shell) == 1)
			status = 1;
		i++;
	}
	//salva o exit_code do ultimo processo 0 
	shell->last_status = status;
}
