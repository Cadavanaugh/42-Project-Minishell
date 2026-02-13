#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "libs/libft/libft.h"
//# include <signal.h>
//# include <unistd.h>
//# include <sys/types.h>
//# include <dirent.h>
//# include <string.h>
//# include <termios.h>
//# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
//# include "builtins.h"

typedef enum e_token_type
{
  WORD,           // Palavras comuns (ls, -la, arquivo.txt)
  PIPE,           // |
  REDIRECT_IN,    // <
  REDIRECT_OUT,   // >
  REDIRECT_APPEND,// >>
  HEREDOC,        // <<
}   t_token_type;

typedef struct s_token
{
  char            *value; // O conteúdo (ex: "ls")
  t_token_type    type;   // O tipo (ex: WORD)
}   t_token;

void lexit(char *input);
int array_length(char **array);
t_token_type get_token_type(char *word);
char	**word_splitter(char const *s);
char	is_whitechar(char c);
char	is_metachar(char c);
void    skip_quotes(char *s, int *i);
char boolean_invert(char bool);

#endif