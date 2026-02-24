#include "minishell.h"

int main(int argc, char *argv[], char *envs[])
{
  char  *input;
  t_token *token_list;
  t_ms *shell;
  (void)argc;
  (void)argv;
  while (1)
  {
    input = readline("minishell$ ");
    if (!input) //tratar CTRL + D pra == NULL
    {
      printf("exit\n");
      break;
    }
    if (*input)
      add_history(input);
    token_list = lexit(input);
    t_cmd   *node;
    node = parser(token_list);
    shell = expander(node, envs);
    // if (node)
    // {
    //   printf("\n--- DEBUGZINHO DO PARSER ---\n");
    //   debug_shell(node);
    // }
    executor(shell);
    envs = shell->envs;
    free(input);
    free(token_list);
  }
  return (0);
}
// ls -la >> a.txt > grep