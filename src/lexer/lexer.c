#include "../minishell.h"

static t_token *create_token_list(char **str_tokens)
{
  size_t x;
  size_t length;
  t_token *token_list;
  length = array_length(str_tokens);
  token_list = malloc(length * sizeof(t_token));
  if (!token_list)
    return 0;
  x = 0;
  while (x < length)
  {
    t_token new_token;
    new_token.value = str_tokens[x];
    new_token.type = get_token_type(str_tokens[x]);
    token_list[x] = new_token;
    x++;
  }
  return token_list;
}

void lexit(char *input)
{
  char **words;
  words = word_splitter(input);
  (void)words;
  t_token *token_list;
  token_list = create_token_list(words);
  (void)token_list;
}
