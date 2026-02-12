#include "../minishell.h"

static void	free_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char *find_token_end(char *s)
{
  if (is_metachar(*s))
  {
      if ((*s == '>' && *(s + 1) == '>') || (*s == '<' && *(s + 1) == '<'))
          return (s + 2);
      return (s + 1);
  }

  while (*s && !is_whitechar(*s) && !is_metachar(*s))
  {
      if (*s == '"' || *s == '\'')
          s++;
      else
          s++;
  }

  return (s);
}

static int	fill_array(char **split, size_t word_count, char *start)
{
	size_t	i;
	char	*end;

	i = 0;
	while (i < word_count)
	{
		while (is_whitechar(*start))
			start++;
		end = find_token_end(start);
		split[i] = ft_calloc(end - start + 1, sizeof(char));
		if (!split[i])
		{
			free_array(split);
			return (0);
		}
		  ft_memcpy(split[i], start, end - start);
		start = end;
		i++;
	}
	return (1);
}

static size_t	count_words(char *input)
{
	size_t	count;
	char	*end;

	count = 0;
	while (*input)
	{
		while (*input && is_whitechar(*input))
			input++;
		if (*input)
		{
			count++;
			end = find_token_end(input);
			input = end;
		}
	}
	return (count);
}

char	**word_splitter(char const *str)
{
	size_t	word_count;
	char	**split_array;

	if (!str)
		return (0);
	word_count = count_words((char *)str);
	split_array = ft_calloc(word_count + 1, sizeof(char *));
	if (!split_array)
		return (0);
	if (!fill_array(split_array, word_count, (char *)str))
		return (0);
	return (split_array);
}
