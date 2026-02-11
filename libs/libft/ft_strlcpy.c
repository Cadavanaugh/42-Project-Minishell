/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:45:54 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 14:26:31 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// src = "45678"
// dst = "123"
// size = 9

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	counter;

	src_len = ft_strlen(src);
	if (!src || !dst || !size)
		return (src_len);
	counter = 0;
	while (src[counter] && counter < size - 1)
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = 0;
	return (src_len);
}
