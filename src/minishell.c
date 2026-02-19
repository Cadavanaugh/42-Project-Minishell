#include "minishell.h"

int main(int argc, char *argv[], char *env[])
{
  char  *input;
  t_token *token_list;
  (void)argc;
  (void)argv;
  (void)env;
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
    parsit(token_list);
    free(input);
    free(token_list);
  }
  return (0);
}
