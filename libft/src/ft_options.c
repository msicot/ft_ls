/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:33:02 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 12:04:12 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_mna(char *s, t_arg *l)
{
	char	*tmp;

	if (!(s) || !(l->str))
		return ;
	tmp = l->str;
	l->str = ft_strjoin(l->str, s);
	ft_strdel(&tmp);
}

static void	ft_wildcard(t_arg *l, va_list ap, int p)
{
	int val;

	val = va_arg(ap, int);
	if (val < 0)
	{
		l->minus = 1;
		ft_flag_override(l);
		val *= 0;
	}
	if (p == 0)
		l->width = val;
	else
		l->preci = val;
}

void		ft_is_preci(const char *f, t_arg *l, va_list ap)
{
	int offset;

	offset = 1;
	if (f[LEN] == '.')
	{
		l->point = 0;
		l->point = 1;
		++LEN;
		if (f[LEN] && f[LEN] == 42)
		{
			ft_wildcard(l, ap, 1);
			LEN += offset;
		}
		else if (f[LEN] && f[LEN] <= '9' && f[LEN] >= '0')
		{
			l->preci = ft_atoi(&f[LEN]);
			while (l->preci / 10 != 0)
			{
				++offset;
				l->preci /= 10;
			}
			l->preci = ft_atoi(&f[LEN]);
			LEN += offset;
		}
	}
}

void		ft_is_width(const char *f, t_arg *l, va_list ap)
{
	int off;

	off = 1;
	if (f[LEN] && (((f[LEN] <= '9' && f[LEN] >= '0')) || f[LEN] == 42))
	{
		if (f[LEN] && f[LEN] == 42)
		{
			ft_wildcard(l, ap, 0);
			LEN += off;
		}
		else
		{
			l->width = ft_atoi(&f[LEN]);
			while (l->width / 10 != 0)
			{
				++off;
				l->width /= 10;
			}
			l->width = ft_atoi(&f[LEN]);
			LEN += off;
		}
	}
}
