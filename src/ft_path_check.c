/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:27:27 by msicot            #+#    #+#             */
/*   Updated: 2018/02/22 11:27:28 by msicot           ###   ########.fr       */
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

	tmp = d->path;
	while (tmp != NULL)
	{
		if (stat(tmp->d_name, &sb) == 0)
			tmp = tmp->next;
		else
		{
			ft_printf("ls: ");
			perror(tmp->d_name);
			d->path = rm_node(d->path, tmp->d_name);
			tmp = d->path;
		}
	}
	ft_rm_files(d);
}
