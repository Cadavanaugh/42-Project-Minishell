#include "../minishell.h"

void clean_ms(t_ms *shell)
{
  int i;
  i = 0;
  if (shell->envs)
  {
    while (shell->envs[i])
    {
      free(shell->envs[i]);
      i++;
    }
    free(shell->envs);
  }
}


void free_matrix(char **m)
{
    int i = 0;
    while (m && m[i])
      free(m[i++]);
    free(m);
}