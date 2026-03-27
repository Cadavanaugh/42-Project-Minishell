/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universal_helpers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:15:37 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/27 14:54:15 by victde-s         ###   ########.fr       */
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
