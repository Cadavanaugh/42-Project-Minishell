#include "../minishell.h"

static void mount_string(t_ms *shell, int i, int j, int inicio, int breakpoint)
{
  char *before_chunk;
  char *after_chunk;
  char *var_value;
  char *temp;
  char *result;
  before_chunk = ft_substr(shell->cmd_list->args[j], 0, inicio);
  if (shell->cmd_list->args[j][inicio + 1] == '?')
    var_value = ft_itoa(shell->last_status);
  else
    var_value = get_env_val(ft_substr(shell->cmd_list->args[j], inicio + 1, breakpoint - inicio), shell);
  if (!var_value)
    var_value = ft_strdup("");
  after_chunk = ft_substr(shell->cmd_list->args[j], breakpoint + 1, i - breakpoint + 1);
  temp = ft_strjoin(before_chunk, var_value);
  result = ft_strjoin(temp, after_chunk);
  shell->cmd_list->args[j] = result;
  free(temp);
  free(var_value);
  free(before_chunk);
  free(after_chunk);
} // echo "hello $USER que usa TERMINAL $SHELL COLOR $TERM e ARQ $HOSTTYPE aaaaa"

static void rebuild_string(t_ms *shell, int i, int j)
{
  int inicio;
  int breakpoint;
  inicio = i;
  while (shell->cmd_list->args[j][i + 1] && shell->cmd_list->args[j][i + 1] != ' ' && shell->cmd_list->args[j][i + 1] != '"')
    i++;
  breakpoint = i;
  while (shell->cmd_list->args[j][i])
    i++;
  mount_string(shell, i, j, inicio, breakpoint);
}

void expander(t_ms *shell)
{
  int i;
  int j;
  i = 0;
  j = 0;
  char inside_simple_quote;
  inside_simple_quote = 0;
  while (shell->cmd_list->args[j])
  {
    i = 0;
    while (shell->cmd_list->args[j][i])
    {
      if (shell->cmd_list->args[j][i] == '\'')
        inside_simple_quote = boolean_invert(inside_simple_quote);
      else if (shell->cmd_list->args[j][i] == '$' && !inside_simple_quote)
        rebuild_string(shell, i, j);
      // TO-DO tratar $? pra expandir pra o último valor de retorno (do que foi executado antes)
      i++;
    }
    if (ft_strchr(shell->cmd_list->args[j], '"') || ft_strchr(shell->cmd_list->args[j], '\''))
      shell->cmd_list->args[j] = remove_quotes(shell->cmd_list->args[j]);
    j++;
  }
}

