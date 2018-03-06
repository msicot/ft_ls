/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:27:27 by msicot            #+#    #+#             */
/*   Updated: 2018/03/06 17:11:25 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_rm_files(t_dir *d)
{
	t_name		*tmp;
	struct stat	sb;
	int			i;

	i = 0;
	tmp = d->path;
	while (tmp != NULL)
	{
		if (stat(tmp->d_name, &sb) == 0)
		{
			if (S_ISREG(sb.st_mode))
			{
				ft_printf("%s\n", tmp->d_name);
				d->path = rm_node(d->path, tmp->d_name);
				tmp = d->path;
				i = 1;
			}
			else
				tmp = tmp->next;
		}
	}
	if (i != 0)
		ft_printf("\n");
}

static void	ft_check_dash1(t_dir *d)
{
	if (ft_strcmp(d->path->d_name, "--") == 0)
	{
		d->path = rm_node(d->path, d->path->d_name);
		--d->nb_path;
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

void		ft_path_check(t_dir *d)
{
	struct stat	sb;
	t_name		*tmp;

	if (d->path == NULL)
		return ;
	ft_check_dash1(d);
	tmp = d->path;
	while (tmp != NULL)
	{
		if (lstat(tmp->d_name, &sb) == 0)
		{
			tmp->info.date = time_info(&sb);
			tmp = tmp->next;
		}
		else
		{
			ft_err_path(tmp->d_name);
			d->path = rm_node(d->path, tmp->d_name);
			tmp = d->path;
		}
	}
	ft_merge_sort(&d->path, d);
	ft_rm_files(d);
}
