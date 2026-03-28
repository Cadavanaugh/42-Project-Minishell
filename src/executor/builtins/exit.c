/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:43:31 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/28 16:55:55 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	is_numeric_input(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
		{
			i++;
			continue ;
		}
		else if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	clean_memory_on_exit(t_ms *shell)
{
	close(shell->initial_stdout);
	close(shell->initial_stdin);
	free_matrix(shell->envs);
	free_cmd_list(shell->cmd_list);
	free(shell);
}

void	builtin_exit(t_ms *shell)
{
	int	exit_status;

	printf("exit\n");
	if (array_length(shell->cmd_list->args) > 2)
	{
		shell->last_status = 1;
		ft_putstr_fd("exit: too many arguments\n", 2);
		return ;
	}
	else if (shell->cmd_list->args[1]
		&& !is_numeric_input(shell->cmd_list->args[1]))
	{
		shell->last_status = 2;
		ft_putstr_fd("exit: numeric argument required\n", 2);
		return ;
	}
	exit_status = 0;
	if (shell->cmd_list->args[1])
		exit_status = ft_atoi(shell->cmd_list->args[1]);
	shell->last_status = exit_status;
	clean_memory_on_exit(shell);
	exit(exit_status);
}
