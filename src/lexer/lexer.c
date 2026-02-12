#include "../minishell.h"

void lexit(char *input)
{
  char **words;
  words = word_splitter(input);

  for (int x = 0; x < array_length(words); x++)
  {
    t_token new_token;
    new_token.value = words[x];
    new_token.type = get_token_type(words[x]);
    printf("TYPE %d: %s\n", new_token.type, new_token.value);
  }
}
