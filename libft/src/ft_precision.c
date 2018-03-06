/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:27:56 by msicot            #+#    #+#             */
/*   Updated: 2018/02/13 16:01:42 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_preci_d(char **s, char *val, t_arg *l, int k)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->blank == 1)
		(*s)[i++] = ' ';
	else if (l->sign == 1)
		(*s)[i++] = (l->neg == 1) ? val[j++] : '+';
	while (i < (k - (len - l->neg)))
		(*s)[i++] = '0';
	while (i < k && j < len)
		(*s)[i++] = val[j++];
}

void	ft_preci_x(char **s, char *val, t_arg *l, int k)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->sharp == 2)
	{
		(*s)[i++] = '0';
		(*s)[i++] = 'X';
	}
	while (i < (k - (len)))
		(*s)[i++] = '0';
	while (i < k && j < len)
		(*s)[i++] = val[j++];
}
