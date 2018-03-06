/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:09:26 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 17:22:11 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_width_uni(char **s, char *tmp, t_arg *l, int c)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = (int)ft_strlen(tmp);
	if (l->minus == 0)
	{
		while (i < (c - len))
			(*s)[i++] = ' ';
		while (i < c)
			(*s)[i++] = tmp[j++];
	}
	else
	{
		while (i < len)
			(*s)[i++] = tmp[j++];
		while (i < (c))
			(*s)[i++] = ' ';
	}
}

static char	*ft_conv(int *tab, t_arg *l)
{
	char	*s;
	int		c;
	int		k;
	int		i;
	char	*tmp;

	k = 0;
	i = 0;
	if (!(tmp = ft_strnew(5)))
		return (NULL);
	while (tab[i] != 0)
		tmp[k++] = (char)tab[i++];
	tmp[k] = '\0';
	if (l->x == 0)
	{
		c = ft_champs(tmp, l);
		if (!(s = ft_strnew(c)))
			return (NULL);
		ft_width_uni(&s, tmp, l, c);
		ft_strdel(&tmp);
		return (s);
	}
	return (tmp);
}

static void	ft_surplus(wchar_t u, int *i)
{
	i[2] = 128 + (u & 63);
	u = u >> 6;
	i[1] = 128 + (u & 63);
	u = u >> 6;
	i[0] = 224 + u;
}

char		*ft_unicode2(wchar_t u, t_arg *l)
{
	int i[5];
	int z;

	z = 0;
	while (z < 5)
		i[z++] = 0;
	if (u >= 128 && u <= 2047)
	{
		i[1] = 128 + (u & 63);
		i[0] = 192 + (u >> 6);
	}
	else if (u > 2047 && u <= 65535)
		ft_surplus(u, i);
	else if (u > 65535 && u <= 2097151)
	{
		i[3] = 128 + (u & 63);
		u = u >> 6;
		i[2] = 128 + (u & 63);
		u = u >> 6;
		i[1] = 128 + (u & 63);
		u = u >> 6;
		i[0] = 240 + u;
	}
	return (ft_conv(i, l));
}

char		*ft_is_unic(va_list ap, t_arg *l)
{
	wchar_t	u;
	char	*s;

	s = NULL;
	l->sign = 0;
	l->neg = 0;
	l->zero = 0;
	l->point = 0;
	l->preci = 0;
	u = va_arg(ap, wchar_t);
	if (ft_error_uni(l, u) == 1)
		return (s);
	if (u == 0)
		ft_null_unic(l);
	if (u < 128 || (u <= 255 && MB_CUR_MAX == 1))
		s = ft_char_c((char)u, l);
	else if (u >= 128)
		s = ft_unicode2(u, l);
	return (s);
}
