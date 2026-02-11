/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:01:33 by jode-cas          #+#    #+#             */
/*   Updated: 2025/07/27 17:53:03 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*str_nbr;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		str_nbr = ft_itoa(n);
		ft_putstr_fd(str_nbr, fd);
		free(str_nbr);
	}
}
