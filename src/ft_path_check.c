/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:27:27 by msicot            #+#    #+#             */
/*   Updated: 2018/03/12 13:32:58 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void ft_print_file(t_dir *d, t_name **tmp2)
{
	struct s_padding	pad;
//	int					i;
	t_name	*tmp;

	tmp = *tmp2;
	ft_padd_0(&pad);
//	tmp->next = NULL;
	if (ft_retrieve_l(tmp->d_name, &tmp->info, &pad) == 0)
		return;
	ft_size_padd(&pad, tmp->info, d, tmp->d_name);
	print_it(pad, tmp);
	ft_del_info(&tmp->info);
}

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
				if (d->l == 1)
					ft_print_file(d, &tmp);
				else
					ft_printf("%s", tmp->d_name);
				ft_strdel(&tmp->info.date);
				d->path = rm_node(d->path, tmp->d_name);
				tmp = d->path;
				if (d->path != NULL)
					ft_printf("\n");
				i = 1;
			}
			else
				tmp = tmp->next;
		}
	}
	if (i != 0 && d->path != NULL)
		ft_printf("\n");
}

static void	ft_check_dash1(t_dir *d, char *name)
{
	DIR			*dir;
	struct stat	sb;

	if ((dir = opendir(name)) != NULL)
	{
		closedir(dir);
		return ;
	}
	else if (lstat(name, &sb) != -1)
		return ;
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

void		ft_path_check(t_dir *d, t_name **head)
{
	struct stat	sb;
	t_name		*tmp;

	if (d->path == NULL)
		return ;
	ft_check_dash1(d, d->path->d_name);
	tmp = *head;
	while (tmp != NULL)
	{
		if (lstat(tmp->d_name, &sb) != -1)
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
