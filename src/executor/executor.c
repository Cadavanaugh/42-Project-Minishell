/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:53:07 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/02 17:53:07 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void multi_execution(t_ms *shell)
{

}

static void single_execution(t_ms *shell)
{
	char	**path_dirs;
	char	*command_path;

	if (is_builtin(shell->cmd_list->args[0]))
		call_builtins(shell);
	else
	{
		path_dirs = get_path_dirs(shell);
		command_path = get_full_command_path(shell->cmd_list->args[0],
				path_dirs);
		free_matrix(path_dirs);
		call_path(shell, command_path);
		free(command_path);
	}
}

void	executor(t_ms *shell)
{
	int		initial_stdout;
	int		initial_stdin;

	initial_stdout = dup(STDOUT_FILENO);
	initial_stdin = dup(STDIN_FILENO);
	if (shell->cmd_list->redirs && apply_redirects(shell) < 0)
		exit(EXIT_FAILURE);
	if (shell->cmd_list->next)
		multi_execution(shell);
	else
		single_execution(shell);
	dup2(initial_stdout, STDOUT_FILENO);
	close(initial_stdout);
	dup2(initial_stdin, STDIN_FILENO);
	close(initial_stdin);
}
