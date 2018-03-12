/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pcheck2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:07:07 by msicot            #+#    #+#             */
/*   Updated: 2018/03/12 19:03:27 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_lnk(t_dir *d, t_name **tmp2, struct stat *sb)
{
	struct s_padding	pad;
	t_name				*tmp;
	char				buf[1024];
	char				*temp;
	int					len;

	tmp = *tmp2;
	ft_padd_0(&pad);
	if (ft_retrieve_l(tmp->d_name, &tmp->info, &pad) == 0)
		return ;
	ft_size_padd(&pad, tmp->info, d, tmp->d_name);
	if (S_ISLNK(sb->st_mode))
	{
		len = readlink(tmp->d_name, buf, sizeof(buf) - 1);
		if (len != -1)
			buf[len] = '\0';
		temp = tmp->d_name;
		tmp->d_name = ft_strjoin(tmp->d_name, " -> ");
		ft_strdel(&temp);
		temp = tmp->d_name;
		tmp->d_name = ft_strjoin(tmp->d_name, buf);
		ft_strdel(&temp);
	}
	print_it(pad, tmp);
	ft_del_info(&tmp->info);
}

int			ft_pis_reg(t_dir *d, t_name **node)
{
	t_name	*tmp;

	tmp = *node;
	if (d->l == 1)
		ft_print_file(d, &tmp);
	else
		ft_printf("%s\n", tmp->d_name);
	ft_strdel(&tmp->info.date);
	d->path = rm_node(d->path, tmp->d_name);
	return (1);
}

int			ft_pis_lnk(t_dir *d, t_name **node, struct stat *sb)
{
	t_name		*tmp;
	struct stat	sv;

	tmp = *node;
	if (d->l == 1)
		ft_print_lnk(d, &tmp, sb);
	else
	{
		if (stat(tmp->d_name, &sv) != -1 && S_ISDIR(sv.st_mode))
			return (0);
		ft_printf("%s\n", tmp->d_name);
		d->path = rm_node(d->path, tmp->d_name);
		return (0);
	}
	ft_strdel(&tmp->info.date);
	d->path = rm_node(d->path, tmp->d_name);
	return (1);
}
