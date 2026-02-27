#include "../../minishell.h"

void builtin_env(char **envs)
{
  int i = 0;
  if (!envs)
    return;
  while(envs[i])
  {
    write(1, envs[i], ft_strlen(envs[i]));
    write(1, "\n", 1);
    i++;
  }
}

static char does_env_exist(char **envs, char *name)
{
  int i = 0;
  int len = ft_strlen(name);
  while(envs[i])
  {
    if (ft_strncmp(envs[i], name, len) == 0 && envs[i][len] == '=')
      return 1;
    i++;
  }
  return 0;
}

void builtin_unset(t_ms *shell, char *name)
{
  int i = 0;
  int j = 0;
  int max = 0;
  char **new_envs;
  if (!name || !shell->envs || !does_env_exist(shell->envs, name))
    return;
  while(shell->envs[max])
    max++;
  new_envs = ft_calloc(max, sizeof(char *));
  if (!new_envs)
    return;
  i = 0;
  while(shell->envs[i])
  {
    if (ft_strncmp(shell->envs[i], name, ft_strlen(name)) == 0 && shell->envs[i][ft_strlen(name)] == '=')
      i++;
    if (i == max)
      break;
    new_envs[j] = shell->envs[i];
    i++;
    j++;
  }
  free(shell->envs);
  shell->envs = new_envs;
  shell->last_status = 0;
}
