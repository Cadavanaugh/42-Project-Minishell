#include "../minishell.h"

char *get_env_val(char *name, t_ms *shell)
{
    int i;
    int len;
    if (!name || !shell || !shell->envs)
      return (NULL);
    i = 0;
    len = ft_strlen(name);
    while (shell->envs[i])
    {
      if (ft_strncmp(shell->envs[i], name, len) == 0 && shell->envs[i][len] == '=')
        return (shell->envs[i] + len + 1);
      i++;
    }
    return (NULL);
}

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
