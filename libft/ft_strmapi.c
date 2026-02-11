/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:23:44 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 05:48:16 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	c;

	c = 0;
	new_s = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (new_s == NULL)
		return (NULL);
	while (s[c])
	{
		new_s[c] = f(c, s[c]);
		c++;
	}
	new_s[c] = '\0';
	return (new_s);
}
