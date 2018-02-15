/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wipre_unis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:30:57 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 17:38:38 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printable(char s)
{
	if ((int)s < 255 && MB_CUR_MAX == 1)
		return (1);
	s = s >> 3;
	if (s == 30)
		return (4);
	s = (s >> 1) & 14;
	if (s == 14)
		return (3);
	s = (s >> 1) & 6;
	if (s == 6)
		return (2);
	return (1);
}

void		ft_surplus(char **s, int i)
{
	int len;

	len = (int)ft_strlen(*s);
	while (i < len)
		(*s)[i++] = '\0';
}

void		ft_preci_s(char **s, t_arg *l)
{
	int		i;
	int		len;
	char	*tmp;

	tmp = *s;
	i = 0;
	if (l->point == 1 && (*s) != NULL)
	{
		if (l->preci == 0)
			ft_bzero(*s, ft_strlen(*s));
		else
		{
			while (i < l->preci)
			{
				len = ft_printable(tmp[i]);
				if (len == 1 && i < l->preci)
					++i;
				else if ((len > 1 && MB_CUR_MAX == 1) || i + len > l->preci)
					break ;
				else if (i + len <= l->preci)
					i += len;
			}
			ft_surplus(s, i);
		}
	}
}

char		*ft_width_s(char *s, t_arg *l)
{
	char	*tmp;
	int		len;
	char	*pad;
	int		i;

	i = 0;
	len = (int)ft_strlen(s);
	tmp = s;
	if (l->width > len)
	{
		if (!(pad = ft_strnew(l->width - len)))
			return (NULL);
		while (i < (l->width - len))
			pad[i++] = (l->zero == 1) ? '0' : ' ';
		if (!(s = (l->minus == 0) ? ft_strjoin(pad, s) : ft_strjoin(s, pad)))
			return (NULL);
		ft_strdel(&pad);
		ft_strdel(&tmp);
	}
	return (s);
}
