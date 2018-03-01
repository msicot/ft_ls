/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:45:43 by msicot            #+#    #+#             */
/*   Updated: 2018/03/01 17:40:51 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_num_len(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	if (i == 0)
		i = 1;
	return (i);
}

static void	ft_size_padd(t_dir *d, t_lstat *info)
{
	
}

static void	ft_retrieve_l(char *path, t_lstat *info)
{
	struct stat sb;

	if (lstat(path, &sb) == 0)
	{
		info->type = ft_strdup(filetype(&sb));
		info->user = ft_strdup(u_name(&sb));
		info->group = ft_strdup(gr_name(&sb));
		info->perm = perm(&sb);
		info->nb_l = sb.st_nlink;
		info->size = sb.st_size;
		info->date = time_info(&sb);
	}
}

void		ft_option_l(t_name **head, t_dir *d)
{
	t_name	*node;

	node = *head;
	while (node != NULL)
	{
		ft_retrieve_l(node->path, &node->info);
		ft_size_padd(d, node->info);
		printf("%s%s %2d %s %s %10d %s %s\n", node->info.type, node->info.perm, node->info.nb_l, node->info.user, node->info.group, node->info.size, node->info.date, node->d_name);

		node = node->next;
	}
}
