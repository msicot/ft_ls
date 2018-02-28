/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:27:27 by msicot            #+#    #+#             */
/*   Updated: 2018/02/28 18:07:04 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rm_files(t_dir *d)
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

void	ft_path_check(t_dir *d)
{
	struct stat	sb;
	t_name		*tmp;

	if (d->path == NULL)
		return ;
	if (ft_strcmp(d->path->d_name, "--") == 0)
	{
			d->path = rm_node(d->path, d->path->d_name);
			--d->nb_path;
	}
	tmp = d->path;
	while (tmp != NULL)
	{
		if (stat(tmp->d_name, &sb) == 0)
		{
			tmp = tmp->next;
		}
		else
		{
			if (ft_strcmp(tmp->d_name, "--") == 0)
				--d->nb_path;
			ft_printf("ls: ");
			perror(tmp->d_name);
			d->path = rm_node(d->path, tmp->d_name);
			tmp = d->path;
		}
	}
	ft_merge_sort(&d->path);
	ft_rm_files(d);
}
