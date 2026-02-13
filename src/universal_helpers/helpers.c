#include "../minishell.h"

char boolean_invert(char bool)
{
  if (bool == 0) return 1;
  else if (bool == 1) return 0;
  return 2;
}

inline char	is_whitechar(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

inline char  is_metachar(char c)
{
	return (c == '|' || c == '<' || c == '>');
}
