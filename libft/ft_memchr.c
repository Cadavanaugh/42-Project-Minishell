/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:32:21 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 06:02:36 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*new_s;

	new_s = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (new_s[counter] == (unsigned char)c)
			return (&new_s[counter]);
		counter++;
	}
	return (NULL);
}
