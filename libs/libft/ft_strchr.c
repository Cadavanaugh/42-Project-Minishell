/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:22:59 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 02:55:05 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *string, int wanted_char)
{
	while (*string)
	{
		if (*string == (char)wanted_char)
			return ((char *)string);
		string++;
	}
	if ((char)wanted_char == '\0')
		return ((char *)string);
	return (0);
}
