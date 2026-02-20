#include "../minishell.h"

// 1-contar quantidade de args até pipe ou null
// 2-alocar e preencher array de args da struct t_cmd
// 3-parsear (cria a lista de comandos, conta, aloca em quantos * precisar)

// **IMAGINAR COM EXEMPLO 'ls -l'

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
void debug_shell(t_cmd *head)
{
    t_cmd *c = head;
    int i = 0;

    while (c)
    {
        printf("\n=== COMANDO [%d] ===\n", i++);
        // Print de Argumentos
        for (int j = 0; c->args && c->args[j]; j++)
            printf("  arg[%d]: %s\n", j, c->args[j]);
        
        // Print de Redirecionamentos
        t_redir *r = c->redirs;
        while (r)
        {
            printf("  REDIR: [Tipo %d] -> [Alvo: %s]\n", r->type, r->target);
            r = r->next;
        }
        c = c->next;
    }
    printf("====================\n");
}

t_cmd *parser(t_token *token_list)
{
    t_cmd   *head = NULL;  // O primeiro comando (o que você retorna)
    t_cmd   *last = NULL;  // O ajudante para conectar os nós
    int     i = 0;
    int     total_args;

    if (!token_list)
        return (NULL);

    while (token_list[i].value != NULL)
    {
        // 1. Cria o novo nó
        t_cmd *new = ft_calloc(sizeof(t_cmd), 1);
        if (!new)
            return (NULL); // Idealmente, aqui você daria free na lista já criada

        // 2. LOGICA DE CONEXÃO (O "Engate")
        if (head == NULL)   // Se é o primeiro comando da linha
            head = new;
        else                // Se já temos comandos antes, conecta o anterior a este
            last->next = new;
        last = new;         // O novo agora passa a ser o último

        // 3. Preenchimento dos dados (como você já fez)
        total_args = count_args(token_list, i);
        new->args = ft_calloc(sizeof(char *), total_args + 1);
        if (!new->args)
            return (NULL);
        
        parse_token_to_cmd(token_list, new, &i);

        // 4. O Pulo do Pipe:
        // Se paramos em um PIPE, precisamos saltar ele para o 
        // próximo loop criar o próximo comando.
        if (token_list[i].value != NULL && token_list[i].type == PIPE)
            i++;

        printf("command: %s\n", (new->args)[0]);
        int j = 1;
        while ((new->args)[j] != NULL)
        {
            printf("args: %s\n", (new->args)[j]);
            j++;
        }

    }
    return (head); // Retorna a cabeça da lista para o executor
}

//fiquei em duvida do porque tá sempre usando o i como indice, 
//e iterando pelo proprio ponteiro em si
//precisa tratar casos com | e redir