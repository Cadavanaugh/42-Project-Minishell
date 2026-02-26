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

void builtin_unset(char ***envs, char *name)
{
  int i = 0;
  int j = 0;
  int max = 0;
  char **new_envs;
  if (!name || !*envs)
    return;
  while((*envs)[max])
    max++;
  new_envs = ft_calloc(max, sizeof(char *));
  if (!new_envs || !does_env_exist(*envs, name))
    return;
  i = 0;
  while((*envs)[i])
  {
    if (ft_strncmp((*envs)[i], name, ft_strlen(name)) == 0 && (*envs)[i][ft_strlen(name)] == '=')
      i++;
    if (i == max)
      break;
    new_envs[j] = (*envs)[i];
    i++;
    j++;
  }
  free(*envs);
  *envs = new_envs;
}
