#include "../minishell.h"

int	skip_quotes(char *s, int *i)
{
	char	quote;

	quote = s[*i];
	(*i)++;
	while (s[*i] && s[*i] != quote)
		(*i)++;
	if (s[*i] == quote)
	{
		(*i)++;
		return (1);
	}
	return (0);
}

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

int check_quotes(char *s)
{
  int i;
  
  i = 0;
  while (s[i])
  {
    if (input[i] == '"' || s[i] == '\'')
    {
       if (!skip_quotes((s, &i))
       {
          write(2, "minishell: syntax error: unclosed\n", 41);
          return (0);
       }
    }
  else
      i++;
  return (1);
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
