#include "../minishell.h"

static int handle_heredoc(char *delimiter)
{
    int     fd[2];
    char    *line;
    if (pipe(fd) < 0)
    {
        perror("pipe");
        return (-1);
    }
    while (1)
    {
        line = readline("> ");
        if (!line)
            break ;
        if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
            && ft_strlen(line) == ft_strlen(delimiter))
        {
            free(line);
            break ;
        }
        write(fd[1], line, ft_strlen(line));
        write(fd[1], "\n", 1);
        free(line);
    }
    close(fd[1]);
    return (fd[0]);
}

int redirect_heredoc(char *delimiter)
{
    int fd_in;
    fd_in = handle_heredoc(delimiter);
    if (fd_in < 0)
        return (-1);
    dup2(fd_in, STDIN_FILENO);
    close(fd_in);
    return (0);
}
