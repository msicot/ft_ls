/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:45:43 by msicot            #+#    #+#             */
/*   Updated: 2018/03/01 18:41:50 by msicot           ###   ########.fr       */
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

static void	ft_size_padd(t_lstat *s)
{
	int i;
	
	i = ft_strlen(s->user);
	s->u_pad = (s->u_pad > i) ? s->u_pad : i;
	i = ft_strlen(s->group);
	s->gr_pad = (s->gr_pad > i) ? s->gr_pad : i;
	i = ft_num_len(s->size);
	s->sz_pad = (s->sz_pad > i) ? s->sz_pad : i;
	i = ft_num_len(s->nb_l);
	s->ln_pad = (s->ln_pad > i) ? s->ln_pad : i;
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
int i;

i = d->nb_path;
	node = *head;
	ft_printf("loool\n");
	while (node != NULL)
	{
		ft_retrieve_l(node->path, &node->info);
		ft_size_padd(&node->info);
		node = node->next;
	}
	node = *head;
	ft_printf("loool\n");
	while (node != NULL)
	{
	printf("%s%s  %*d %*s  %*s  %*d %s %s\n", node->info.type, node->info.perm, node->info.ln_pad, node->info.nb_l, node->info.u_pad, node->info.user, node->info.gr_pad, node->info.group, node->info.sz_pad, node->info.size, node->info.date, node->d_name);
	node = node->next;
	}
}
