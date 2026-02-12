#include "../minishell.h"

int array_length(char **array)
{
  int counter;
  counter = 0;
  while (array[counter])
  {
    counter++;
    if (array[counter] == NULL)
      break;
  }
  return counter;
}

t_token_type define_token_type(char *word)
{
  if (ft_strncmp(word, "|", 1) == 0)
    return PIPE;
  else if (ft_strncmp(word, ">>", 2) == 0)
    return REDIRECT_APPEND;
  else if (ft_strncmp(word, ">", 1) == 0)
    return REDIRECT_OUT;
  else if (ft_strncmp(word, "<<", 2) == 0)
    return HEREDOC;
  else if (ft_strncmp(word, "<", 1) == 0)
    return REDIRECT_IN;
  else
    return WORD;
}
