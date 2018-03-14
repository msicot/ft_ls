/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:50:49 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 16:14:20 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_surplus(void)
{
	char	*s;

	if (!(s = ft_strnew(3)))
		return (NULL);
	s[0] = '0';
	s[1] = 'x';
	s[2] = '0';
	return (s);
}

static int	ft_champs_p(char *s, t_arg *l)
{
	int	len;
	int	lenf;

	len = (int)ft_strlen(s);
	lenf = len + 2;
	if (l->preci > (lenf - 2))
		lenf = lenf + (l->preci - (lenf - 2));
	if (l->width > lenf)
		lenf = lenf + (l->width - lenf);
	return (lenf);
}

char		*ft_is_p(va_list ap, t_arg *l)
{
	char	*s;
	char	*val;
	int		i;
	int		k;

	l->preci = 0;
	l->point = 0;
	i = 0;
	l->sharp = 2;
	if (!(val = ft_itoa_base(va_arg(ap, uintptr_t), 16, 0)))
		return (NULL);
	k = ft_champs_p(val, l);
	if (val[0] == 0 && l->width == 0 && (l->point == 0 || l->preci == 1))
		s = ft_surplus();
	else
	{
		if (!(s = ft_strnew(k)))
			return (NULL);
		ft_width_p(&s, val, l, k);
	}
	ft_strdel(&val);
	s = ft_strlowcase(s);
	return (s);
}
