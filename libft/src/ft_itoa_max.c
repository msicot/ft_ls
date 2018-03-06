/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:52:39 by msicot            #+#    #+#             */
/*   Updated: 2018/01/19 17:55:24 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_testneg(intmax_t n)
{
	int		k;

	k = 0;
	if (n < 0)
		k = 1;
	return (k);
}

static int		ft_count(intmax_t n)
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

static char		*ft_exception1(intmax_t n)
{
	char	*nbr;
	int		i;

	i = 19;
	if (!(nbr = (char *)malloc(sizeof(char) * (21))))
		exit(0);
	nbr[0] = '-';
	nbr[1] = '9';
	nbr[20] = '\0';
	n = 223372036854775808;
	while (i > 1)
	{
		nbr[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (nbr);
}

static char		*ft_exception2(intmax_t n)
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

char			*ft_itoa_max(intmax_t n)
{
	char	*nbr;
	int		i;
	int		k;

	i = 1;
	if (n == LLONG_MIN)
		return (ft_exception1(n));
	if (n == 9223372036854775807)
		return (ft_exception2(n));
	if ((k = ft_testneg(n)) == 1)
		n = n * -1;
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
