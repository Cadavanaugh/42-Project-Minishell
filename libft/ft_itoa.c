/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:14:01 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 12:08:11 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_digits(int n)
{
	int	counter;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (10);
	counter = 0;
	while (n != 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	unsigned int	new_n;
	char			*str;
	int				digits;

	digits = count_digits(n) + (n < 0);
	str = ft_calloc(digits + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		new_n = 2147483648;
	else
		new_n = n;
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		new_n = -n;
	while (new_n > 0)
	{
		str[--digits] = (new_n % 10) + '0';
		new_n /= 10;
	}
	return (str);
}
