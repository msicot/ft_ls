/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_println.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:31:52 by msicot            #+#    #+#             */
/*   Updated: 2018/02/19 11:07:11 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**ft_tab(t_dir *d, t_name *head)
{
	int		i;
	t_name	*tmp;

	i = 0;
	tmp = head;
	if (!(d->t = (char**)malloc(sizeof(char*) * (d->nb_w + 1))))
		return (NULL);
	while (i < d->nb_w && tmp != NULL)
	{
		if (!(d->t[i] = ft_strdup(tmp->d_name)))
			return (NULL);
		tmp = tmp->next;
		++i;
	}
	if (!(d->t[i] = (char*)malloc(sizeof(char))))
		return (NULL);
	d->t[i][0] = '\0';
	i = 0;
	return (d->t);
}

static void	print(t_dir *d)
{
	int		starter;
	int		i;

	starter = 0;
	i = 0;
	while (starter < d->nb_l)
	{
		i = starter;
		while (i < d->nb_w)
		{
			ft_printf("%-*s", d->width, d->t[i]);
			ft_strdel(&d->t[i]);
			i += d->nb_l;
		}
		++starter;
	}
}

void		ft_print_line(t_name *head, t_dir *d)
{
	int		i;
	int		nb_l;
	t_name	*tmp;
	int		len;

	nb_l = 0;
	i = 0;
	tmp = head;
	d->nb_c = 0;
	d->len_m = 0;
	while (tmp != NULL)
	{
		len = (int)ft_strlen(tmp->d_name);
		d->len_m = (len > d->len_m) ? len : d->len_m;
		d->nb_c += (int)ft_strlen(tmp->d_name);
		tmp = tmp->next;
	}
	d->t = ft_tab(d, head);
	d->nb_c += (d->nb_w - 1);
	while (d->nb_c * nb_l < d->col)
		nb_l++;
	d->width = d->len_m + 1;
	d->nb_l = nb_l;
	print(d);
}
