/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:23:52 by msicot            #+#    #+#             */
/*   Updated: 2018/02/20 14:52:24 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_flag_reset_ls(t_dir *d)
{
	d->l = 0;
	d->R = 0;
	d->a = 0;
	d->r = 0;
	d->t2 = 0;
	d->minus = 1;
	d->options = 0;
	d->un = 0;
	d->flags = 0;
}

static void	ft_retrieve_flags(t_dir *d, char **tab, int i)
{
	int	j;

	j = 1;
	if (tab[i][j] == '\0')
		return ;
	while (tab[i][j] != '\0')
	{
		if (tab[i][j] == 'l')
			d->l = 1;
		else if (tab[i][j] == 'R')
			d->R = 1;
		else if (tab[i][j] == 'a')
			d->a = 1;
		else if (tab[i][j] == 'r')
			d->r = 1;
		else if (tab[i][j] == 't')
			d->t2 = 1;
		else if (tab[i][j] == '0')
			d->un = 1;
		else
		{
			ft_error_flag(tab[i][j]);
			break ;
		}
		++j;
	}
	d->options++;
}

static int	ft_path_retrieve(char **tab, t_dir *d, int i)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	if (!(d->p = (char**)malloc(sizeof(char*) * (d->nb_argc - i + 1))))
		return (-1);
	if (d->options == d->nb_argc - 1)
	{
		if (!(d->p[j++] = ft_strdup(".")))
			return (-1);
		++count;
	}
	else
	{
		while (i < d->nb_argc)
		{
			if (!(d->p[j++] = ft_strdup(tab[i++])))
				return (-1);
			++count;
		}
	}
	if (!(d->p[j] = ft_strnew(0)))
		return (-1);
	return (count);
}

void		ft_flags(char **tab, t_dir *d)
{
	int	i;

	ft_flag_reset_ls(d);
	i = 1;
	if (i < d->nb_argc)
	{
		while (i < d->nb_argc && tab[i][0] == '-' && tab[i][1] != '\0')
		{
			ft_retrieve_flags(d, tab, i);
			++i;
		}
		d->nb_path = ft_path_retrieve(tab, d, i);
		d->nb_path = (d->nb_path > 0) ? d->nb_path : 0;
	}
}
