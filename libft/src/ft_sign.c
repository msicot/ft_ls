/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:00:28 by msicot            #+#    #+#             */
/*   Updated: 2018/02/14 15:41:56 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_signin(char **s, t_arg *l, int k, int lim)
{
	int i;

	i = 0;
	if (l->sign == 1)
	{
		if (l->zero == 1)
			(*s)[0] = (l->neg == 1) ? '-' : '+';
		else
			(*s)[k - lim - 1] = (l->neg == 1) ? '-' : '+';
	}
}

void	ft_wp_zero(char **s, char *val, t_arg *l, int k)
{
	int i;
	int j;
	int	len;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->blank == 1)
		(*s)[i++] = ' ';
	else if (l->sign == 1)
		(*s)[i++] = (l->neg == 1) ? val[j++] : '+';
	while (i < k && j < len)
		(*s)[i++] = val[j++];
}

void	ft_wp_zero_o(char **s, char *val, t_arg *l, int k)
{
	int i;
	int j;
	int	len;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->sharp == 2)
	{
		(*s)[i++] = '0';
		(*s)[i++] = 'X';
	}
	while (i < k && j < len)
		(*s)[i++] = val[j++];
}
