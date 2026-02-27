#include "../minishell.h"

static int count_args(t_token *token_list, int i)
{
    int arg_count;

    arg_count = 0;
    while (token_list[i].value != NULL && token_list[i].type != PIPE)
    {
        if (token_list[i].type == WORD)
            arg_count++;
        else // >, <, >>, <<
		{
			if (token_list[i + 1].value != NULL)
				i += 1;
        }
        i += 1;
    }
    return (arg_count);
}

static void add_new_redir(t_token *token_list, t_cmd *cmd, int *i)
{
    t_redir *novo;
    t_redir *ultimo;

    novo = ft_calloc(sizeof(t_redir), 2);
    if (!novo)
        return;
    novo->type = token_list[*i].type;
    novo->target = ft_strdup(token_list[*i + 1].value);
    novo->next = NULL;

    if (cmd->redirs == NULL)
        cmd->redirs = novo;
    else 
    {
        ultimo = cmd->redirs;
        while (ultimo->next != NULL)
            ultimo = ultimo->next;
        ultimo->next = novo;
    }
}

static void parse_token_to_cmd(t_token *token_list, t_cmd *cmd, int *i)
{
  int   args_id;

  args_id = 0;
  while (token_list[*i].value != NULL && token_list[*i].type != PIPE)
  {
    if (token_list[*i].type == WORD)
    {
      cmd->args[args_id++] = ft_strdup(token_list[*i].value);
      *i += 1;
    }
    else
    {
        add_new_redir(token_list, cmd, i);
        *i += 2;
    }
  }
  cmd->args[args_id] = NULL; //coloca o fim da array
}

t_cmd *parser(t_token *token_list)
{
    t_cmd   *head = NULL;
    t_cmd   *last = NULL;
    int     i = 0;
    int     total_args;
    if (!token_list)
        return (NULL);
    while (token_list[i].value != NULL)
    {
        t_cmd *new = ft_calloc(sizeof(t_cmd), 1);
        if (!new)
            return (NULL);
        if (head == NULL)
            head = new;
        else
            last->next = new;
        last = new;
        total_args = count_args(token_list, i);
        new->args = ft_calloc(sizeof(char *), total_args + 1);
        if (!new->args)
            return (NULL);
        parse_token_to_cmd(token_list, new, &i);
        if (token_list[i].value != NULL && token_list[i].type == PIPE)
            i++;
    }
    return (head);
}
