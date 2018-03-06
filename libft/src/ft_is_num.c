/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:24:23 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:54:58 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_isnum2(va_list ap, t_arg *l)
{
	if (l->j == 1)
		return (ft_integer(va_arg(ap, intmax_t), l));
	if (l->ll == 1)
		return (ft_integer((intmax_t)(va_arg(ap, long long int)), l));
	if (l->l == 1)
		return (ft_integer((intmax_t)(va_arg(ap, long int)), l));
	if (l->z == 1)
		return (ft_integer((intmax_t)(va_arg(ap, size_t)), l));
	if (l->hh == 1)
		return (ft_integer((intmax_t)((char)(va_arg(ap, int))), l));
	if (l->h == 1)
		return (ft_integer((intmax_t)((short int)(va_arg(ap, int))), l));
	return (ft_integer((intmax_t)(va_arg(ap, int)), l));
}

char		*ft_is_d(va_list ap, t_arg *l)
{
	char	*s;

	s = ft_isnum2(ap, l);
	return (s);
}
