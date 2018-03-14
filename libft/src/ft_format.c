/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:23:13 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:16:42 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_else(const char *f, t_arg *l)
{
	if (f[LEN] == 's' || f[LEN] == 'D' || f[LEN] == 'd' || f[LEN] == 'X')
		return (1);
	if (f[LEN] == 'i' || f[LEN] == 'D' || f[LEN] == 'x')
		return (1);
	if (f[LEN] == 'p' || f[LEN] == 'o' || f[LEN] == 'O')
		return (2);
	if (f[LEN] == 'U' || f[LEN] == 'u' || f[LEN] == '%')
		return (2);
	return (0);
}

static void	ft_format_delim3(char **s, const char *f, t_arg *l, va_list ap)
{
	if (f[LEN] == 'p')
		(*s) = ft_is_p(ap, l);
	else if (f[LEN] == 'o' || f[LEN] == 'O')
	{
		l->l = (f[LEN] == 'O') ? 2 : l->l;
		if (!((*s) = (ft_is_octal(ap, l))))
			return ;
	}
	else if (f[LEN] == 'u' || f[LEN] == 'U')
	{
		l->l = (f[LEN] == 'U') ? 1 : l->l;
		if (!((*s) = ft_is_u(ap, l)))
			return ;
	}
	else if (f[LEN] == '%')
		(*s) = ft_pourc(l);
}

static void	ft_format_delim2(char **s, const char *f, t_arg *l, va_list ap)
{
	if (f[LEN] == 's')
	{
		if (l->l == 1)
		{
			if (!((*s) = ft_is_unis(ap, l)))
				return ;
		}
		else
		{
			if (!((*s) = ft_string(l, ap)))
				return ;
		}
	}
	else if (f[LEN] == 'd' || f[LEN] == 'i' || f[LEN] == 'D')
	{
		l->l = (f[LEN] == 'D') ? 1 : l->l;
		if (!((*s) = ft_is_d(ap, l)))
			return ;
	}
	else if (f[LEN] == 'x' || f[LEN] == 'X')
	{
		l->x = (f[LEN] == 'X') ? 1 : 0;
		if (!((*s) = ft_is_x(ap, l)))
			return ;
	}
}

void		ft_format_delim(const char *f, t_arg *l, va_list ap)
{
	char	*s;

	s = NULL;
	l->zero = (l->point == 1 && f[LEN] != 'c') ? 0 : l->zero;
	if (f[LEN] == '\0' && l->loop == 0)
		return ;
	else if (f[LEN] == 'c')
	{
		if (!(s = ft_is_c(ap, l)))
			return ;
	}
	else if (f[LEN] == 'C')
		s = ft_is_unic(ap, l);
	else if (f[LEN] == 'S')
		s = ft_is_unis(ap, l);
	else if (ft_else(f, l) == 1)
		ft_format_delim2(&s, f, l, ap);
	else if (ft_else(f, l) == 2)
		ft_format_delim3(&s, f, l, ap);
	else
		s = ft_char_c(f[LEN], l);
	if (s != NULL)
		ft_mna(s, l);
	ft_strdel(&s);
	++LEN;
}
