/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:43:48 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:33:25 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_nul(char *s)
{
	int i;

	i = 0;
	if (!(s = ft_strnew(6)))
		return (NULL);
	s[i++] = '(';
	s[i++] = 'n';
	s[i++] = 'u';
	s[i++] = 'l';
	s[i++] = 'l';
	s[i++] = ')';
	return (s);
}

static void	ft_fill(char **s, char *val, t_arg *l, int k)
{
	int	i;
	int	len;
	int	lim;

	len = (int)ft_strlen(val);
	l->preci = (l->preci >= len) ? len : l->preci;
	lim = (l->point == 0) ? len : l->preci;
	i = 0;
	if (l->minus == 0)
	{
		while (i < (k - lim))
			(*s)[i++] = (l->zero == 1) ? '0' : ' ';
		while (i < k)
			(*s)[i++] = *val++;
	}
	else
	{
		while (i < (lim))
			(*s)[i++] = *val++;
		while (i < k)
			(*s)[i++] = (l->zero == 1) ? '0' : ' ';
	}
}

static int	ft_champs_s(char *s, t_arg *l)
{
	int len;

	len = (s == NULL) ? 6 : (int)ft_strlen(s);
	if (l->point == 1 && l->preci < len)
		len = l->preci;
	len = (l->width > len) ? l->width : len;
	return (len);
}

char		*ft_string_p(char *s, t_arg *l)
{
	char	*tmp;
	int		k;

	tmp = s;
	k = ft_champs_s(s, l);
	if (!(s = ft_strnew(k)))
		return (NULL);
	ft_fill(&s, tmp, l, k);
	ft_strdel(&tmp);
	return (s);
}

char		*ft_string(t_arg *l, va_list ap)
{
	char	*s;
	char	*val;
	int		k;

	val = va_arg(ap, char*);
	if (val == NULL)
	{
		if (!(val = ft_nul(val)))
			return (NULL);
		l->x = 1;
	}
	k = ft_champs_s(val, l);
	if (!(s = ft_strnew(k)))
		return (NULL);
	ft_fill(&s, val, l, k);
	if (l->x == 1)
		ft_strdel(&val);
	return (s);
}
