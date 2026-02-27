#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
//# include <signal.h>
# include <unistd.h>
//# include <sys/types.h>
//# include <dirent.h>
# include <fcntl.h>
//# include <termios.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>

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

typedef struct s_redir
{
	t_token_type			 	type;	   // Tipo (REDIR_IN, REDIR_OUT, etc.)
	char			*target;	  // Nome do arquivo ou delimitador (se for heredoc)
	struct s_redir  *next;
}   t_redir;

typedef struct s_cmd
{
	char			**args;// O comando e argumentos para execve (ex: "ls", "-la", NULL)
	t_redir			*redirs;// Lista de entradas/saídas deste comando
	struct s_cmd	*next;// Próximo comando (se houver PIPE)
}   t_cmd;

typedef struct s_minishell
{
  char    **envs; //a memória do sistema
  int     last_status; //guarda os códigos de saída, útil para o $?
  struct  s_cmd *cmd_list; //retorno do parser
} t_ms;

t_token *lexit(char *input);
int array_length(char **array);
t_token_type get_token_type(char *word);
char	**word_splitter(char const *s);
char	is_whitechar(char c);
char	is_metachar(char c);
void    skip_until_next_quote(char *s, int *i);
char boolean_invert(char value);
t_cmd *parser(t_token *token_list);
char is_builtin(char *input);
t_ms *create_shell_instance(char **envs);
void expander(t_ms *shell);
char *get_env_val(const char *name, t_ms *shell);
void update_env_val(const char *key, char *value, t_ms *shell);
void clean_ms(t_ms *shell);
char *remove_quotes(char *input);
void executor(t_ms *shell);
void free_matrix(char **m);
void builtin_echo(t_ms *shell);
void builtin_env(t_ms *shell);
void builtin_cd(char **args, t_ms *shell);
void builtin_export(char **args, t_ms *shell);
void builtin_unset(t_ms *shell, char *name);

#endif