/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:23:20 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/17 19:57:30 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_minishell_memory(t_ms *shell)
{
	if (shell->cmd_list)
		free_matrix(shell->cmd_list->args);
	if (shell->envs)
		free_matrix(shell->envs);
	free(shell);
}

void	free_matrix(char **m)
{
	int	i;

	i = 0;
	while (m && m[i])
		free(m[i++]);
	free(m);
}
