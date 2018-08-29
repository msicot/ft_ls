/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:51:45 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:51:51 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	ft_num_len(intmax_t n, int base)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		++i;
	}
	return (i);
}

static char	*ft_create_str(int base, int len, intmax_t n, int sign)
{
	char	*str;
	char	letter;

	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		if (n % base >= 10)
			letter = 'A' - 10;
		else
			letter = '0';
		str[len] = n % base + letter;
		n /= base;
	}
	if (base == 10 && sign != 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_base_u(intmax_t n, int base, int sign)
{
	char		*str;
	int			len;

	len = ft_num_len(n, base);
	if (n == 0)
	{
		if ((str = (char*)malloc(sizeof(char) * (2))) == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (base == 10 && sign != 0)
		len++;
	if ((str = ft_create_str(base, len, n, sign)) == NULL)
		return (NULL);
	return (str);
}
