#include "../../minishell.h"

static int is_n_flag(char *arg)
{
  int i;
  if (!arg || arg[0] != '-' || arg[1] != 'n')
    return (0);
  i = 2;
  while (arg[i])
  {
    if (arg[i] != 'n')
      return (0);
    i++;
  }
  return (1);
}

void builtin_echo(char **args)
{
  int i;
  int n_flag;
  i = 1;
  n_flag = 0;
  while (args[i] && is_n_flag(args[i]))
  {
    n_flag = 1;
    i++;
  }
  while (args[i])
  {
    ft_putstr_fd(args[i], 1);
    if (args[i + 1])
      write(1, " ", 1);
    i++;
  }
  if (!n_flag)
    write(1, "\n", 1);
}
