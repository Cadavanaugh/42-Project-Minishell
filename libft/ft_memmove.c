/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 21:51:36 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 01:25:19 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*new_dest;
	char	*new_src;
	size_t	c;

	new_dest = (char *)dest;
	new_src = (char *)src;
	if (new_dest < new_src)
	{
		c = 0;
		while (c < n)
		{
			new_dest[c] = new_src[c];
			c++;
		}
	}
	else
	{
		c = n;
		while (c > 0)
		{
			new_dest[c - 1] = new_src[c - 1];
			c--;
		}
	}
	return (new_dest);
}
