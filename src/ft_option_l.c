/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:45:43 by msicot            #+#    #+#             */
/*   Updated: 2018/03/12 11:06:45 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_padd_0(struct s_padding *info)
{
	info->u_pad = 0;
	info->gr_pad = 0;
	info->sz_pad = 0;
	info->ln_pad = 0;
	info->nb_block = 0;
	info->maj_pad = 0;
}

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

void	ft_size_padd(struct s_padding *s, t_lstat l, t_dir *d, char *str)
{
	int			i;

	i = ft_strlen(l.user);
	s->u_pad = (s->u_pad > i) ? s->u_pad : i;
	i = ft_strlen(l.group);
	s->gr_pad = (s->gr_pad > i) ? s->gr_pad : i;
	if (d->a == 0 && str[0] == '.')
		i = 1;
	else
		i = ft_num_len(l.nb_l);
	s->ln_pad = (s->ln_pad > i) ? s->ln_pad : i;
	if (d->a == 0 && str[0] == '.')
		i = 1;
	else
		i = ft_num_len(l.size);
	s->sz_pad = (s->sz_pad > i) ? s->sz_pad : i;
	if (l.maj_min == 1)
	{
		i = ft_num_len(l.maj);
		s->maj_pad = (s->maj_pad > i) ? s->maj_pad : i;
	}
}

int	ft_retrieve_l(char *path, t_lstat *info, struct s_padding *pad)
{
	struct stat sb;

	info->size = 0;
	info->maj = 0;
	if (lstat(path, &sb) != -1)
	{
		if (!(info->type = ft_strdup(filetype(&sb))))
			return (0);
		info->user = ft_strdup(u_name(&sb));
		info->group = ft_strdup(gr_name(&sb));
		info->perm = perm(&sb);
		info->nb_l = sb.st_nlink;
		if (ft_strcmp("b", info->type) != 0 && ft_strcmp("c", info->type) != 0)
			info->size = sb.st_size;
		else
			get_majmin(&sb, &info);
		info->date = time_info(&sb);
		pad->nb_block += sb.st_blocks;
		info->acl = acl_type(path, info->type);
		return (1);
	}
	else
		perror(path);
	return (0);
}

void		ft_option_l(t_name **head, t_dir *d)
{
	t_name				*node;
	struct s_padding	pad;
	int					i;

	ft_padd_0(&pad);
	node = *head;
	i = 0;
	while (node != NULL)
	{
		i = pad.nb_block;
		if (ft_retrieve_l(node->path, &node->info, &pad) == 0)
		{
			node = node->next;
			continue ;
		}
		ft_linked(&node);
		ft_size_padd(&pad, node->info, d, node->d_name);
		if (d->a == 0 && node->d_name[0] == '.')
			pad.nb_block = i;
		node = node->next;
	}
	node = *head;
	i = ft_count_lst(node);
	ft_print_l(pad, &node, d, i);
}
