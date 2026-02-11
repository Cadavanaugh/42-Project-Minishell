/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:22:59 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 16:51:42 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int wanted_char)
{
	char	*last_found;

	last_found = 0;
	while (*string)
	{
		if (*string == (char)wanted_char)
			last_found = (char *)string;
		string++;
	}
	if ((char)wanted_char == 0)
		return ((char *)string);
	return (last_found);
}
