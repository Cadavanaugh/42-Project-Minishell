/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:37:58 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 01:25:30 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*new_s;

	new_s = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		new_s[counter] = c;
		counter++;
	}
	return (new_s);
}
