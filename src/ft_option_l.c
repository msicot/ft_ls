/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:45:43 by msicot            #+#    #+#             */
/*   Updated: 2018/03/02 13:39:19 by msicot           ###   ########.fr       */
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

static void	ft_size_padd(struct s_padding *s, t_lstat l)
{
	int i;

	i = ft_strlen(l.user);
	s->u_pad = (s->u_pad > i) ? s->u_pad : i;
	i = ft_strlen(l.group);
	s->gr_pad = (s->gr_pad > i) ? s->gr_pad : i;
	i = ft_num_len(l.size);
	s->sz_pad = (s->sz_pad > i) ? s->sz_pad : i;
	i = ft_num_len(l.nb_l);
	s->ln_pad = (s->ln_pad > i) ? s->ln_pad : i;
}

static void	ft_retrieve_l(char *path, t_lstat *info, struct s_padding *pad)
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
		info->date = ft_strdup(time_info(&sb));
		pad->nb_block += sb.st_blocks;
	}
}

void		ft_option_l(t_name **head, t_dir *d)
{
	t_name				*node;
	struct s_padding	pad;
	int					i;

	ft_padd_0(&pad);
	node = *head;
	while (node != NULL)
	{
		ft_retrieve_l(node->path, &node->info, &pad);
		ft_size_padd(&pad, node->info);
		node = node->next;
	}
	node = *head;
	i = ft_count_lst(node);
	ft_print_l(pad, &node, d, i);
}
