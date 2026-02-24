#include "../../minishell.h"

void builtin_env(char **envs)
{
  int i = 0;
  while(envs[i])
  {
    write(1, envs[i], ft_strlen(envs[i]));
    write(1, "\n", 1);
    i++;
  }
}