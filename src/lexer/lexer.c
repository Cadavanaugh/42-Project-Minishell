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

static char were_quotes_closed(char *input)
{
  int i;
  int double_quote_count;
  i = 0;
  double_quote_count = 0;
  while (input[i])
  {
    if (input[i] == '"')
      double_quote_count++;
    i++;
  }
  return (double_quote_count % 2 == 0);
}

void lexit(char *input)
{
  if (!were_quotes_closed(input))
    printf("Aspas não fechadas\n");
  else {
    char **words;
    words = word_splitter(input);
    (void)words;
    t_token *token_list;
    token_list = create_token_list(words);
    (void)token_list;
  }
}
