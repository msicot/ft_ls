/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:33:42 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:56:12 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_typehl(const char *f, t_arg *l)
{
	size_t	off;

	off = 1;
	if (f[LEN] == 'h')
	{
		if (f[LEN + off] == 'h')
		{
			l->hh = 1;
			++off;
		}
		else
			l->h = 1;
	}
	else if (f[LEN] == 'l')
	{
		if (f[LEN + off] == 'l')
		{
			l->ll = 1;
			++off;
		}
		else
			l->l = 1;
	}
	LEN += off;
}

void		ft_reset_type(t_arg *l)
{
	l->hh = 0;
	l->l = 0;
	l->h = 0;
	l->hh = 0;
	l->z = 0;
	l->j = 0;
}

void		ft_is_type(const char *f, t_arg *l)
{
	ft_reset_type(l);
	while (f[LEN] && (f[LEN] == 'h' || f[LEN] == 'l' || f[LEN] == 'z'\
				|| f[LEN] == 'j'))
	{
		if (f[LEN] == 'h' || f[LEN] == 'l')
			ft_typehl(f, l);
		else if (f[LEN] == 'j')
		{
			l->j = 1;
			++LEN;
		}
		else if (f[LEN] == 'z')
		{
			l->z = 1;
			++LEN;
		}
		else
			break ;
	}
}
