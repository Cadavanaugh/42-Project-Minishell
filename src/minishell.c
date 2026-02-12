#include "minishell.h"

int main(int argc, char *argv[], char *env[])
{
  char  *input;
  
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
    lexit(input);
    free(input);
  }
  return (0);
}
