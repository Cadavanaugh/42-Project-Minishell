/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:40:57 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 17:43:52 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static void	free_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	fill_array(char **split, size_t word_count, char *start, char c)
{
	size_t	i;
	char	*end;

	i = 0;
	while (i < word_count)
	{		
		while (*start == c)
			start++;
		end = start;
		while (*end && *end != c)
			end++;
		split[i] = ft_calloc(end - start + 1, sizeof(char));
		if (!split[i])
		{
			free_array(split);
			return (0);
		}
		ft_memcpy(split[i], start, end - start);
		start = end;
		i++;
	}
	return (1);
}

static size_t	count_words(char const *s, char delimiter)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		if (*s != delimiter && (*(s + 1) == delimiter || *(s + 1) == '\0'))
			counter++;
		s++;
	}
	return (counter);
}

char	**ft_split(char const *s, char delimiter)
{
	size_t	word_count;
	char	**split_array;

	if (!s)
		return (0);
	word_count = count_words(s, delimiter);
	split_array = ft_calloc(word_count + 1, sizeof(char *));
	if (!split_array)
		return (0);
	if (!fill_array(split_array, word_count, (char *)s, delimiter))
		return (0);
	return (split_array);
}
