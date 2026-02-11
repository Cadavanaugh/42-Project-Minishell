/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:45:54 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 13:49:21 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t after_size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	counter;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (after_size <= dst_len)
		return (after_size + src_len);
	counter = 0;
	while ((counter < (after_size - 1 - dst_len)) && src[counter])
	{
		dst[dst_len + counter] = src[counter];
		counter++;
	}
	dst[dst_len + counter] = 0;
	return (dst_len + src_len);
}
