/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:43:31 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/31 12:04:31 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	is_numeric_input(char *input)
{
	int	i;

	i = 0;
	if (!input)
		return (0);
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (!input[i])
		return (0);
	while (input[i])
	{
		if (!ft_isdigit(input[i++]))
			return (0);
	}
	if (ft_strlen(input) > 19)
		return (0);
	return (1);
}

static char	should_skip_env_var(char *env_var, char **args)
{
	int	k;
	int	name_len;

	k = 1;
	while (args[k])
	{
		name_len = ft_strlen(args[k]);
		if (ft_strncmp(env_var, args[k], name_len) == 0
			&& env_var[name_len] == '=')
			return (1);
		k++;
	}
	return (0);
}

char	**build_new_envs(t_ms *shell, char **args)
{
	int		max;
	int		i;
	int		j;
	char	**new_envs;

	max = 0;
	while (shell->envs[max])
		max++;
	new_envs = ft_calloc(max, sizeof(char *));
	if (!new_envs)
		return (NULL);
	i = 0;
	j = 0;
	while (shell->envs[i])
	{
		if (!should_skip_env_var(shell->envs[i], args))
		{
			new_envs[j] = shell->envs[i];
			j++;
		}
		else
			free(shell->envs[i]);
		i++;
	}
	return (new_envs);
}

static void	clean_memory_on_exit(t_ms *shell)
{
	close(shell->initial_stdout);
	close(shell->initial_stdin);
	free_matrix(shell->envs);
	free_cmd_list(shell->cmd_list);
	free(shell);
}

void	builtin_exit(t_ms *shell)
{
	int	exit_status;

	if (shell->cmd_list->args[1] && !is_numeric_input(shell->cmd_list->args[1]))
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		clean_memory_on_exit(shell);
		exit(2);
	}
	if (array_length(shell->cmd_list->args) > 2)
	{
		shell->last_status = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return ;
	}
	exit_status = shell->last_status;
	if (shell->cmd_list->args[1])
		exit_status = ft_atoi(shell->cmd_list->args[1]);
	clean_memory_on_exit(shell);
	exit((unsigned char)exit_status);
}
