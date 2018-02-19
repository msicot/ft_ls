/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:23:52 by msicot            #+#    #+#             */
/*   Updated: 2018/02/19 13:18:57 by msicot           ###   ########.fr       */
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
}

static void	ft_retrieve_ls(t_dir *d, char **tab, int i)
{
	int	j;

	j = 1;
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
		else
		{
			ft_error_flag(tab[i][j]);
			break ;
		}
		++j;
	}
	d->options++;

}

static void	ft_path_retrieve(char **tab, t_dir *d, int i)
{
	int j;

	j = 0;
	if (d->options == d->nb_argc - 1)
	{
		if (!(d->p[j++] = ft_strdup(".")))
			return ;
	}
	else
	{
		while (i < d->nb_argc)
		{
			if (!(d->p[j++] = ft_strdup(tab[i++])))
				return ;
		}
	}
	if (!(d->p[j] = ft_strnew(0)))
			return ;
}

void	ft_flags(char **tab, t_dir *d)
{
	int	i;
	int	j;

	ft_flag_reset_ls(d);
	i = 1;
	j = 0;
	while (i < d->nb_argc)
	{
		while (i < d->nb_argc && tab[i][j] == '-')
		{
			ft_retrieve_ls(d, tab, i);
			++i;
		}
		if (!(d->p = (char**)malloc(sizeof(char*) *
						(d->nb_argc - i + 1))))
			return ;
		ft_path_retrieve(tab, d, i);
		break ;
	}
}
