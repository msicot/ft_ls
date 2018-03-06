/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 09:38:47 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:42:40 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_pourc(t_arg *l)
{
	char	*s;
	int		k;
	char	*tmp;

	l->preci = 0;
	l->point = 0;
	l->plus = 0;
	l->sign = 0;
	l->blank = 0;
	l->zero = l->bkzero;
	if (!(s = ft_strnew(1)))
		return (NULL);
	s[0] = '%';
	k = ft_champs(s, l);
	if (!(tmp = ft_strnew(k)))
		return (NULL);
	ft_fill_it_d(&tmp, s, l, k);
	ft_strdel(&s);
	return (tmp);
}
