/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:44:22 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/31 12:04:31 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	builtin_env(t_ms *shell)
{
	int	i;

	i = 0;
	if (!shell || !shell->envs)
	{
		shell->last_status = 1;
		return ;
	}
	while (shell->envs[i])
	{
		write(1, shell->envs[i], ft_strlen(shell->envs[i]));
		write(1, "\n", 1);
		i++;
	}
	shell->last_status = 0;
}

void	builtin_unset(t_ms *shell, char **args)
{
	char	**new_envs;

	if (!args[1] || !shell->envs)
		return ;
	new_envs = build_new_envs(shell, args);
	if (!new_envs)
		return ;
	free(shell->envs);
	shell->envs = new_envs;
	shell->last_status = 0;
}
