#include "minishell.h"

int main(int argc, char *argv[], char *env[])
{
  (void)argc;
  (void)argv;
  (void)env;
  char a = ft_toupper('a');
  printf("%c", a);
}