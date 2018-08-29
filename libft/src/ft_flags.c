/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:09:05 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 13:41:17 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_flag_reset(t_arg *arg)
{
	arg->zero = 0;
	arg->plus = 0;
	arg->minus = 0;
	arg->blank = 0;
	arg->sharp = 0;
	arg->preci = 0;
	arg->wild = 0;
	arg->width = 0;
	arg->neg = 0;
	arg->sign = 0;
	arg->hh = 0;
	arg->h = 0;
	arg->l = 0;
	arg->ll = 0;
	arg->j = 0;
	arg->z = 0;
	arg->point = 0;
	arg->us = 0;
	arg->o = 0;
	arg->x = 0;
	arg->bkzero = 0;
}

void		ft_flag_override(t_arg *l)
{
	if (l->minus == 1)
		l->zero = 0;
	if (l->plus == 1)
		l->blank = 0;
	if (l->point == 1)
		l->zero = 0;
}

static int	ft_raise_flag(const char *format, t_arg *l)
{
	if (format[LEN] == '-')
		l->minus = 1;
	else if (format[LEN] == '+')
	{
		l->sign = 1;
		l->plus = 1;
	}
	else if (format[LEN] == '0')
	{
		l->zero = 1;
		l->bkzero = 1;
	}
	else if (format[LEN] == ' ')
		l->blank = 1;
	else if (format[LEN] == '#')
		l->sharp = 1;
	else
		return (0);
	return (1);
}

void		ft_is_flag(const char *format, t_arg *l)
{
	while (format[LEN] && ft_raise_flag(format, l))
		++LEN;
	ft_flag_override(l);
}
