/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:33:09 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 17:42:54 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_is_hexa2(va_list ap, t_arg *l)
{
	if (l->j == 1)
		return (ft_integer_x(va_arg(ap, uintmax_t), l));
	if (l->ll == 1)
		return (ft_integer_x((va_arg(ap, unsigned long long)), l));
	if (l->l == 1)
		return (ft_integer_x((va_arg(ap, long unsigned int)), l));
	if (l->z == 1)
		return (ft_integer_x((va_arg(ap, size_t)), l));
	if (l->hh == 1)
		return (ft_integer_x(((unsigned char)(va_arg(ap, unsigned int))), l));
	if (l->h == 1)
	{
		return (ft_integer_x(((short unsigned int)
						(va_arg(ap, unsigned int))), l));
	}
	return (ft_integer_x(va_arg(ap, unsigned int), l));
}

char		*ft_is_x(va_list ap, t_arg *l)
{
	char	*s;

	l->sign = 0;
	l->plus = 0;
	l->neg = 0;
	l->blank = 0;
	if (l->sharp == 1)
		++l->sharp;
	if (!(s = ft_is_hexa2(ap, l)))
		return (NULL);
	if (l->x == 0)
	{
		if (!(s = ft_strlowcase(s)))
			return (NULL);
	}
	return (s);
}
