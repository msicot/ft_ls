/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:25:00 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:47:11 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_check_0o(char **val, t_arg *l)
{
	if (ft_strlen((*val)) == 1 && l->point == 1 && l->preci == 0)
	{
		if (l->width != 0)
		{
			if ((*val)[0] == '0')
				(*val)[0] = ' ';
		}
		else if ((*val)[0] == '0')
		{
			if (l->sharp == 1)
				l->sharp = 0;
			else if (l->sharp == 0)
				(*val)[0] = '\0';
		}
	}
	else if (ft_strlen((*val)) == 1 && l->point == 1 && l->preci <= 1 &&
			(*val)[0] == '0')
		l->sharp = 0;
	else if (l->sharp == 1 && (*val)[0] == '0')
		l->sharp = 0;
}

static void	ft_fill_it(char **s, char *val, t_arg *l, int k)
{
	int		j;
	int		i;
	int		len;

	j = 0;
	i = 0;
	if (l->sharp == 1 && val[0] != '0')
	{
		len = (int)ft_strlen(val);
		if (l->preci <= len)
			l->preci = len + l->sharp;
	}
	if (l->preci >= l->width && l->preci != 0)
		ft_preci_d(s, val, l, k);
	else
		ft_width_o(s, val, l, k);
}

static int	ft_champs_o(char **s, t_arg *l)
{
	int len;
	int lenf;

	len = (int)ft_strlen(*s);
	ft_check_0o(s, l);
	lenf = len + l->sharp;
	if (l->preci > lenf)
		lenf = lenf + (l->preci - lenf);
	if (l->width > lenf)
		lenf = lenf + (l->width - lenf);
	return (lenf);
}

char		*ft_integer_o(uintmax_t val, t_arg *l)
{
	char	*s;
	char	*num;
	int		k;

	if (!(num = ft_itoa_base(val, 8, l->neg)))
		return (NULL);
	k = ft_champs_o(&num, l);
	if (!(s = ft_strnew(k)))
		return (NULL);
	ft_fill_it(&s, num, l, k);
	ft_strdel(&num);
	return (s);
}
