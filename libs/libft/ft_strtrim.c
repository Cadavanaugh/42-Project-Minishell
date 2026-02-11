/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:40:49 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 17:12:18 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char const *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*dst;
	char	*dst_start;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (*start && is_in(set, *start))
		start++;
	while (end >= start && is_in(set, *end))
		end--;
	dst = ft_calloc(end - start + 2, sizeof(char));
	if (!dst)
		return (0);
	dst_start = dst;
	while (start <= end)
	{
		*dst = *start;
		dst++;
		start++;
	}
	*dst = '\0';
	return (dst_start);
}
