#include "../minishell.h"

void lexit(char *input)
{
  char **words;
  words = ft_split(input, ' ');

  for (int x = 0; x < array_length(words); x++)
  {
    printf("%d, %d: %s\n", array_length(words), x, words[x]);
  }
}