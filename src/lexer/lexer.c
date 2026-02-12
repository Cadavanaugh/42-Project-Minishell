#include "../minishell.h"

void lexit(char *input)
{
  char **words;
  words = ft_split(input, ' ');

  for (int x = 0; x < array_length(words); x++)
  {
    t_token new_token;
    new_token.value = words[x];
    new_token.type = define_token_type(words[x]);
    printf("%d: %s\n", new_token.type, new_token.value);
  }
}