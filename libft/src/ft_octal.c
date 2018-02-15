/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:09:01 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:44:11 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_is_octal2(va_list ap, t_arg *l)
{
	if (l->j == 1)
		return (ft_integer_o(va_arg(ap, uintmax_t), l));
	if (l->ll == 1)
		return (ft_integer_o((va_arg(ap, long long)), l));
	if (l->l == 1)
		return (ft_integer_o((va_arg(ap, long int)), l));
	if (l->z == 1)
		return (ft_integer_o((va_arg(ap, size_t)), l));
	if (l->hh == 1)
		return (ft_integer_o(((unsigned char)(va_arg(ap, int))), l));
	if (l->h == 1)
		return (ft_integer_o(((short unsigned int)(va_arg(ap, int))), l));
	return (ft_integer_o((va_arg(ap, unsigned int)), l));
}

char		*ft_is_octal(va_list ap, t_arg *l)
{
	char	*s;

	if (l->l == 2)
	{
		l->l = 1;
		l->j = 0;
		l->ll = 0;
	}
	l->sign = 0;
	l->plus = 0;
	l->neg = 0;
	l->blank = 0;
	l->o = 1;
	if (!(s = ft_is_octal2(ap, l)))
		return (NULL);
	return (s);
}
