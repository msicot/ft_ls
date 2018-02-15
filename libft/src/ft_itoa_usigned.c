/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_usigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:52:20 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:52:47 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count(uintmax_t n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_exception2(uintmax_t n)
{
	char	*nbr;
	int		i;

	i = 18;
	if (!(nbr = (char *)malloc(sizeof(char) * (20))))
		exit(0);
	nbr[0] = '9';
	nbr[19] = '\0';
	n = 223372036854775807;
	while (i > 0)
	{
		nbr[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (nbr);
}

char		*ft_itoa_unsigned(uintmax_t n)
{
	char	*nbr;
	int		i;
	int		k;

	k = 0;
	i = 1;
	if (n == 9223372036854775807)
		return (ft_exception2(n));
	i = ft_count(n);
	if (!(nbr = (char *)malloc(sizeof(char) * (i + 1 + k))))
		exit(0);
	nbr[i + k] = '\0';
	if (k == 0)
		i--;
	while (i > 0)
	{
		nbr[i--] = n % 10 + 48;
		n = n / 10;
	}
	nbr[0] = (k == 1 ? '-' : (n % 10 + 48));
	return (nbr);
}
