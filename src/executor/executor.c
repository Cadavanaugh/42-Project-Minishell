#include "../minishell.h"

static char **get_path_dirs(t_ms *shell)
{
  char *path;
  char **splitted_path;
  path = get_env_val("PATH", shell);
  splitted_path = ft_split(path, ':');
  if (!splitted_path)
    return NULL;
  return splitted_path;
}

static char *get_full_command_path(char *cmd, char  **path_dirs)
{
    char    *full_path;
    char    *temp;
    int     i;
    if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
    {
      if (access(cmd, F_OK | X_OK) == 0)
          return (ft_strdup(cmd));
      return (NULL);
    }
    i = 0;
    while (path_dirs[i])
    {
      temp = ft_strjoin(path_dirs[i], "/");
      full_path = ft_strjoin(temp, cmd);
      free(temp);
      if (access(full_path, F_OK | X_OK) == 0)
        return (full_path);
      free(full_path);
      i++;
    }
    return (NULL);
}

void call_builtins(t_ms *shell)
{
  char cwd[PATH_MAX];
  if (ft_strncmp(shell->cmd_list->args[0], "pwd", 3) == 0)
    printf("%s\n", getcwd(cwd, sizeof(cwd)));
  else if (ft_strncmp(shell->cmd_list->args[0], "echo", 4) == 0)
    builtin_echo(shell->cmd_list->args);
  else if (ft_strncmp(shell->cmd_list->args[0], "env", 3) == 0)
    builtin_env(shell->envs);
  else if (ft_strncmp(shell->cmd_list->args[0], "cd", 2) == 0)
    builtin_cd(shell->cmd_list->args, shell);
  // else if (ft_strncmp(args[0], "export", 6) == 0)
  //   // builtin_export();
  // else if (ft_strncmp(args[0], "unset", 5) == 0)
  //   // builtin_unset();
  else if (ft_strncmp(args[0], "exit", 4) == 0)
    exit(0);
}

void executor(t_ms *shell)
{
  char **path_dirs;
  char *command_path;
  if (is_builtin(shell->cmd_list->args[0]))
    call_builtins(shell);
  else {
    path_dirs = get_path_dirs(shell);
    command_path = get_full_command_path(shell->cmd_list->args[0], path_dirs);
    free_matrix(path_dirs);
    (void)command_path;
  }
}

