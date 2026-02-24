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
      {
        free(name);
        return (shell->envs[i] + len + 1);
      }
      i++;
    }
    free(name);
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

char *remove_quotes(char *input)
{
  int len;
  len = ft_strlen(input);
  char *no_quotes;
  no_quotes = ft_calloc(sizeof(char), ((len - 2) + 1));
  if (!no_quotes)
    return NULL;
  no_quotes = ft_substr(input, 1, len - 2);
  return (no_quotes);
}

void free_matrix(char **m)
{
    int i = 0;
    while (m && m[i])
      free(m[i++]);
    free(m);
}
