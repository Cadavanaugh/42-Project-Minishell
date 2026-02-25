#include "../../minishell.h"

void builtin_cd(char **args, t_ms *shell)
{
    char    cwd[1024];
    char    *oldpwd;
    char    *dest;
    oldpwd = getcwd(cwd, sizeof(cwd));
    if (!args[1])
        dest = get_env_val("HOME", shell);
    else if (ft_strcmp(args[1], "-") == 0 )
        dest = get_env_val("OLDPWD", shell);
    else
        dest = args[1];
	if (!dest)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		shell->last_status = 1;
		return ;
	}
    if (chdir(dest) != 0)
    {
        perror("minishell: cd");
        shell->last_status = 1;
        return ;
    }
    update_env_val("OLDPWD", oldpwd, shell);
    update_env_val("PWD", getcwd(cwd, sizeof(cwd)), shell);
    shell->last_status = 0;
}
