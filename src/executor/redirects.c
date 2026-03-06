/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:41:11 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/02 17:41:11 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	redirect_output(char *target, int flags)
{
	int	file;

	file = open(target, flags, 0644);
	if (file < 0)
	{
		perror("open");
		return (-1);
	}
	dup2(file, STDOUT_FILENO);
	close(file);
	return (0);
}

static int	redirect_input(char *target)
{
	int	file;

	file = open(target, O_RDONLY);
	if (file < 0)
	{
		perror("open");
		return (-1);
	}
	dup2(file, STDIN_FILENO);
	close(file);
	return (0);
}

static int	apply_single_redirect(t_redir *redir, t_ms *shell)
{
	int return_val;

	return_val = 0;
	if (redir->type == REDIRECT_OUT)
		return_val = redirect_output(redir->target, O_CREAT | O_WRONLY | O_TRUNC);
	else if (redir->type == REDIRECT_APPEND)
		return_val = redirect_output(redir->target, O_CREAT | O_WRONLY | O_APPEND);
	else if (redir->type == REDIRECT_IN)
		return_val = redirect_input(redir->target);
	else if (redir->type == HEREDOC)
		return_val = redirect_heredoc(redir->target, shell);
	return (return_val);
}

int	apply_redirects(t_ms *shell)
{
	t_redir	*redir;

	redir = shell->cmd_list->redirs;
	while (redir)
	{
		if (apply_single_redirect(redir, shell) < 0)
			return (-1);
		redir = redir->next;
	}
	return (0);
}
