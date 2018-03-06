/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:27:50 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:24:12 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_surplus(char **s, t_arg *l, int i)
{
	(*s)[i++] = '0';
	(*s)[i++] = 'X';
	l->sharp = 0;
	return (i);
}

static void	ft_else_width(char **s, char *val, t_arg *l, int k)
{
	int i;
	int j;
	int	lenf;
	int	lim;

	l->preci += l->sharp;
	lenf = (int)ft_strlen(val);
	lim = (l->preci > lenf + l->sharp) ? l->preci : lenf + l->sharp;
	j = 0;
	i = 0;
	if (l->point == 0 && l->sharp == 2 && l->zero == 1)
		i = ft_surplus(s, l, i);
	while (i < (k - (lim)))
		(*s)[i++] = (l->zero == 1) ? '0' : ' ';
	if (l->sharp == 2)
		i = ft_surplus(s, l, i);
	if (l->preci != 0)
	{
		while (i < (k - lenf))
			(*s)[i++] = '0';
	}
	while (i < (k))
		(*s)[i++] = val[j++];
}

static void	ft_minus_d(char **s, char *val, t_arg *l, int k)
{
	int	lenf;
	int	i;
	int j;

	j = 0;
	i = 0;
	lenf = ft_strlen(val) - l->neg;
	l->preci = (lenf >= l->preci) ? 0 : l->preci;
	if (l->sharp == 2)
	{
		(*s)[i++] = '0';
		(*s)[i++] = 'X';
	}
	if (l->preci != 0)
		while (i < (l->preci - (lenf) + l->sharp))
			(*s)[i++] = '0';
	while (j < lenf)
		(*s)[i++] = val[j++];
	while (i < k)
		(*s)[i++] = ' ';
}

void		ft_width_x(char **s, char *val, t_arg *l, int k)
{
	int i;
	int	len;
	int j;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->width == 0 && l->preci == 0)
		ft_wp_zero_o(s, val, l, k);
	else if (l->minus == 0)
		ft_else_width(s, val, l, k);
	else if (l->minus == 1)
		ft_minus_d(s, val, l, k);
}
