/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:04:10 by msicot            #+#    #+#             */
/*   Updated: 2018/03/05 16:24:46 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_no_op(t_dir *d)
{
	int		j;
	t_name	*tmp;

	if (d->path == NULL && d->nb_path == 0)
		d->path = ft_create_node(".");
	j = (d->a == 1) ? ft_count_lst(d->path) : ft_count_lst(d->path) - 2;
	tmp = d->path;
	while (d->path != NULL && d->path->d_name != NULL)
	{
		j--;
		if (!(d->head = get_names2(d->path->d_name, d)))
			return ;
		if (d->nb_path > 1)
			ft_printf("%s:\n", d->path->d_name);
		ft_printl(&d->head, d);
		if (j > 0)
			ft_printf("\n\n");
		else
			ft_printf("\n");
		d->path = d->path->next;
		if (d->head != NULL)
			ft_del_listp(&d->head);
	}
	if (tmp != NULL)
		ft_del_list(&tmp);
}

int		main(int argc, char **argv)
{
	t_dir	d;

	d.nb_argc = argc;
	if (argc == 1)
	{
		ft_ls_0(&d);
		return (0);
	}
	else
	{
		ft_flags(argv, &d);
		ft_path_check(&d);
		if (d.R == 1)
			ft_ls_gr(&d);
		else
			ft_ls_no_op(&d);
	}
	return (0);
}
