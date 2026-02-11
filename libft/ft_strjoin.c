/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:23:11 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/23 17:17:16 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_string;
	int		c1;
	int		c2;

	result_string = malloc(sizeof(char) * ft_strlen(s1)
			+ sizeof(char) * ft_strlen(s2) + 1);
	if (result_string == NULL)
		return (NULL);
	c1 = 0;
	while (s1[c1])
	{
		result_string[c1] = s1[c1];
		c1++;
	}
	c2 = 0;
	while (s2[c2])
	{
		result_string[c1 + c2] = s2[c2];
		c2++;
	}
	result_string[c1 + c2] = '\0';
	return (result_string);
}
