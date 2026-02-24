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

void builtin_unset(char ***envs, char *name)
{
  int i = 0;
  int j = 0;
  char **new_envs;
  if (!name || !*envs)
    return;
  while((*envs)[i])
    i++;
  new_envs = ft_calloc(i, sizeof(char *));
  i = 0;
  while((*envs)[i])
  {
    if (ft_strncmp((*envs)[i], name, ft_strlen(name)) == 0)
    {
      i++;
      continue;
    }
    new_envs[j] = (*envs)[i];
    i++;
    j++;
  }
  free(*envs);
  *envs = new_envs;
}
