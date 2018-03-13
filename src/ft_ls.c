/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:04:10 by msicot            #+#    #+#             */
/*   Updated: 2018/03/13 17:39:05 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_else(t_dir *d)
{
	int		j;
	t_name	*tmp;

	if (d->path == NULL && d->nb_path == 0)
		d->path = ft_create_node(".");
	j = ft_count_lst(d->path);
	tmp = d->path;
	while (d->path != NULL && d->path->d_name != NULL)
	{
		d->head = get_names2(d->path->d_name, d, d->path->d_name);
		if (d->nb_path > 1)
			ft_printf("%s:\n", d->path->d_name);
		ft_print_opt(&d->head, d);
		if (j > 1)
			ft_printf("\n");
		d->path = d->path->next;
		if (d->head != NULL)
			ft_del_listp(&d->head);
		--j;
	}
	if (tmp != NULL)
		ft_del_list(&tmp);
}

static void	ft_clear_info(t_name **path)
{
	t_name *tmp;

	tmp = *path;
	while (tmp != NULL)
	{
		ft_strdel(&tmp->info.date);
		tmp = tmp->next;
	}
}

void		ft_path_order(t_dir *d)
{
	if (d->path == NULL)
		return ;
	if (d->r == 0)
		ft_merge_sort(&d->path, d);
	else
		ft_merge_sort_r(&d->path, d);
	if (d->t == 1)
	{
		ft_merge_sort_t(&d->path, d);
	}
}

int			main(int argc, char **argv)
{
	t_dir	d;

	d.nb_argc = argc;
	if (argc == 1)
	{
		ft_ls_0(&d);
		return (0);
	}
	else
	{
		ft_flags(argv, &d);
		ft_path_check(&d, &d.path);
		ft_path_order(&d);
		ft_clear_info(&d.path);
		if (d.R == 1)
			ft_ls_gr(&d);
		else
			ft_ls_else(&d);
	}
	return (0);
}
