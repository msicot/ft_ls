/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:27:27 by msicot            #+#    #+#             */
/*   Updated: 2018/03/13 17:38:50 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_file(t_dir *d, t_name **tmp2)
{
	struct s_padding	pad;
	t_name				*tmp;
	struct stat			sb;

	tmp = *tmp2;
	ft_padd_0(&pad);
	if (ft_retrieve_l(tmp->d_name, &tmp->info, &pad) == 0)
		return ;
	ft_size_padd(&pad, tmp->info, d, tmp->d_name);
	if (lstat(tmp->d_name, &sb) != -1 && S_ISLNK(sb.st_mode))
		ft_linked(&tmp);
	print_it(pad, tmp);
	ft_del_info(&tmp->info);
}

static void	ft_rm_files(t_dir *d, struct stat *sb)
{
	t_name		*tmp;
	int			i;

	i = 0;
	tmp = d->path;
	while (tmp != NULL)
	{
		if (lstat(tmp->d_name, sb) != -1)
		{
			if (S_ISREG(sb->st_mode))
			{
				i = ft_pis_reg(d, &tmp);
				tmp = d->path;
			}
			else if (S_ISLNK(sb->st_mode))
			{
				i = ft_pis_lnk(d, &tmp, sb);
				tmp = (d->l == 1) ? d->path : tmp->next;
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

	if (ft_strcmp(d->path->d_name, "--") == 0)
	{
		d->path = rm_node(d->path, d->path->d_name);
		--d->nb_path;
	}
	if ((dir = opendir(name)) != NULL)
	{
		closedir(dir);
		return ;
	}
	else if (lstat(name, &sb) != -1)
		return ;
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
			if (d->t == 1)
				tmp->ts = time_stamp(tmp->d_name);
			tmp = tmp->next;
		}
		else
		{
			ft_err_path(tmp->d_name);
			d->path = rm_node(d->path, tmp->d_name);
			tmp = d->path;
		}
	}
	ft_path_order(d);
	ft_rm_files(d, &sb);
}
