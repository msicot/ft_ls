/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:41:05 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 16:23:42 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_null_c(char *s, t_arg *l)
{
	l->flen += ((int)ft_strlen(l->str) + (int)ft_strlen(s)) + 1;
	if (l->minus == 1)
	{
		write(1, l->str, ft_strlen(l->str) + 1);
		write(1, s, ft_strlen(s));
	}
	else if (l->minus == 0)
	{
		write(1, l->str, ft_strlen(l->str));
		write(1, s, ft_strlen(s) + 1);
	}
	ft_strdel(&l->str);
	ft_strdel(&s);
	if (!(l->str = ft_strnew(0)))
		return ;
	LEN++;
}

void	ft_null_unic(t_arg *l)
{
	l->flen += ((int)ft_strlen(l->str)) + 1;
	write(1, l->str, ft_strlen(l->str) + 1);
	ft_strdel(&l->str);
	if (!(l->str = ft_strnew(0)))
		return ;
}
