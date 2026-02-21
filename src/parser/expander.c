#include "../minishell.h"

void store_envs(t_ms *shell, char **envs)
{
  int i;
  i = 0;
  while (envs[i++]);
  shell->envs = ft_calloc(sizeof(char *), i + 1);
  i = 0;
  while (envs[i])
  {
    shell->envs[i] = ft_strdup(envs[i]);
    i++;
  }
}

void expand_variables(t_cmd *parser_head_node, char **envs)
{
  t_ms *shell = ft_calloc(sizeof(t_ms *), 2);
  store_envs(shell, envs);
  shell->cmd_list = parser_head_node;
  shell->last_status = 0;
}