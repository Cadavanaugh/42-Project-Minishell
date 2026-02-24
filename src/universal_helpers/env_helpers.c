#include "../minishell.h"

char *get_env_val(const char *name, t_ms *shell)
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

static char *create_env_string(const char *key, char *value)
{
    char *temp;
    char *full;
    temp = ft_strjoin(key, "=");
    full = ft_strjoin(temp, value);
    free(temp);
    return (full);
}

static char **reallocate_env(char **old_envs, char *new_entry)
{
    int     i;
    char    **new_envs;

    i = 0;
    while (old_envs[i])
        i++;
    new_envs = malloc(sizeof(char *) * (i + 2)); // +1 para a nova, +1 para o NULL
    if (!new_envs)
        return (old_envs);
    i = 0;
    while (old_envs[i])
    {
        new_envs[i] = old_envs[i];
        i++;
    }
    new_envs[i] = ft_strdup(new_entry); // <--- AQUI ADICIONAMOS A NOVA (ex: OLDPWD)
    new_envs[i + 1] = NULL;
    free(old_envs); // Limpa apenas o "envelope" antigo
    return (new_envs);
}

void update_env_val(const char *key, char *value, t_ms *shell)
{
    int     i;
    int     len;
    char    *new_entry;
    if (!key || !value)
        return ;
    i = 0;
    len = ft_strlen(key);
    new_entry = create_env_string(key, value);
    while (shell->envs[i])
    {
        if (ft_strncmp(shell->envs[i], key, len) == 0 && shell->envs[i][len] == '=')
        {
            free(shell->envs[i]);
            shell->envs[i] = new_entry;
            return ;
        }
        i++;
    }
    shell->envs = reallocate_env(shell->envs, new_entry);
    free(new_entry);
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
