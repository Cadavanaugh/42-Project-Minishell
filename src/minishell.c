#include "minishell.h"

int main(int argc, char *argv[], char *envs[])
{
  char  *input;
  t_token *token_list;
  t_ms *shell;
  (void)argc;
  (void)argv;
  shell = create_shell_instance(envs);
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
    free(input);
    shell->cmd_list = parser(token_list);
    free(token_list);
    // if (node)
    // {
    //   printf("\n--- DEBUGZINHO DO PARSER ---\n");
    //   debug_shell(node);
    // }
    expander(shell);
    executor(shell);
  }
  return (0);
}
// ls -la >> a.txt > grep