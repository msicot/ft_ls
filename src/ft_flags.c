/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:23:52 by msicot            #+#    #+#             */
/*   Updated: 2018/02/22 13:54:27 by msicot           ###   ########.fr       */
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
}

static void		ft_retrieve_flags(t_dir *d, char **tab, int i, int j)
{
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

static t_name	*ft_path_retrieve(char **tab, t_dir *d, int i)
{
	t_name	*tmp;
	t_name	*node;
	t_name	*head;

	head = NULL;
	if (d->nb_argc > i)
	{
		if (!(head = ft_create_node()))
			return (NULL);
		node = head;
		node->d_name = tab[i++];
		d->nb_path++;
		while (i < d->nb_argc)
		{
			if ((tmp = ft_create_node()) == NULL)
				return (NULL);
			node->next = tmp;
			tmp->next = NULL;
			tmp->d_name = tab[i++];
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
		while (i < d->nb_argc && tab[i][0] == '-' && ft_strlen(tab[i]) != 1)
		{
			ft_retrieve_flags(d, tab, i, j);
			++i;
		}
		d->path = ft_path_retrieve(tab, d, i);
		order_list(&d->path);
	//	ft_printf("SEGF BAL ft_flags 2\n");
	}
}
