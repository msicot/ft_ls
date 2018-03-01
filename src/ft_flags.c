/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:23:52 by msicot            #+#    #+#             */
/*   Updated: 2018/03/01 17:34:28 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_flag_reset_ls(t_dir *d)
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
	d->u_pad = 0;
	d->gr_pad = 0;
	d->sz_pad = 0;
	d->ln_pad = 0;
}

static int		ft_ret_flags(t_dir *d, char c)
{
	if (c == 'l')
		d->l = 1;
	else if (c == 'R')
		d->R = 1;
	else if (c == 'a')
		d->a = 1;
	else if (c == 'r')
		d->r = 1;
	else if (c == 't')
		d->t2 = 1;
	else if (c == '0')
		d->un = 1;
	else
		return (0);
	return (1);
}

static void		ft_retrieve_flags(t_dir *d, char **tab, int i, int j)
{
	while (tab[i][j] != '\0')
	{
		if (ft_ret_flags(d, tab[i][j]) == 0)
		{
			ft_error_flag(tab[i][j]);
			break ;
		}
		++j;
		d->options++;
	}
}

static t_name	*ft_path_retrieve(char **tab, t_dir *d, int i)
{
	t_name	*tmp;
	t_name	*node;
	t_name	*head;

	head = NULL;
	if (d->nb_argc > i)
	{
		if (!(head = ft_create_node(tab[i++])))
			return (NULL);
		node = head;
		d->nb_path++;
		while (i < d->nb_argc)
		{
			if ((tmp = ft_create_node(tab[i++])) == NULL)
				return (NULL);
			node->next = tmp;
			node = node->next;
			d->nb_path++;
		}
		node->next = NULL;
	}
	return (head);
}

void			ft_flags(char **tab, t_dir *d)
{
	int		i;
	int		j;

	j = 1;
	ft_flag_reset_ls(d);
	i = 1;
	if (i < d->nb_argc)
	{
		while (i < d->nb_argc && tab[i][0] == '-' && ft_strlen(tab[i]) != 1
				&& ft_strcmp("--", tab[i]) != 0)
		{
			ft_retrieve_flags(d, tab, i, j);
			++i;
		}
		d->path = ft_path_retrieve(tab, d, i);
	}
}
