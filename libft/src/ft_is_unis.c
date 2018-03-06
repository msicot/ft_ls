/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:14:38 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 17:41:47 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_is_unic_s(wchar_t u, t_arg *l)
{
	char	*s;
	char	*s2;

	s = NULL;
	l->sign = 0;
	l->neg = 0;
	if (ft_error_uni_s(l, u) == 1)
		return (s);
	if (u < 128 || (u <= 255 && MB_CUR_MAX == 1))
	{
		if (!(s2 = ft_strnew(1)))
			return (NULL);
		s2[0] = (char)u;
		ft_strdel(&s);
		return (s2);
	}
	else if (u >= 128)
		if (!(s = ft_unicode2(u, l)))
			return (NULL);
	return (s);
}

char		*ft_is_unis(va_list ap, t_arg *l)
{
	char	*s;
	wchar_t *u;
	char	*tmp;
	char	*tmp2;
	int		i;

	l->x = 1;
	i = 0;
	if (!(u = va_arg(ap, wchar_t*)))
		return (ft_strdup("(null)"));
	if (!(s = ft_strnew(0)))
		return (NULL);
	while (u[i])
	{
		tmp2 = s;
		tmp = ft_is_unic_s(u[i++], l);
		if (!(s = ft_strjoin(s, tmp)))
			return (NULL);
		ft_strdel(&tmp2);
		ft_strdel(&tmp);
	}
	ft_preci_s(&s, l);
	if (!(s = ft_width_s(s, l)))
		return (NULL);
	return (s);
}
