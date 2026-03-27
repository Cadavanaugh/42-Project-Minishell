/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universal_helpers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:15:37 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/27 15:05:56 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	array_length(char **array)
{
	int	counter;

	counter = 0;
	while (array[counter])
	{
		counter++;
		if (array[counter] == NULL)
			break ;
	}
	return (counter);
}

void	display_error(char *str, const char *error_msg)
{
	char	*result;

	result = ft_strjoin(str, error_msg);
	ft_putstr_fd(result, 2);
	free(result);
}

char	is_dir(const char *path, t_ms *shell)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
	{
		if (errno == ENOENT)
			shell->last_status = 127;
		else if (errno == EACCES)
			shell->last_status = 126;
		return (0);
	}
	if (S_ISDIR(path_stat.st_mode))
	{
		return (1);
	}
	else
		return (0);
}
