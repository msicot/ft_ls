/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:04:10 by msicot            #+#    #+#             */
/*   Updated: 2018/02/22 16:33:28 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_no_op(t_dir *d)
{
	int		j;
	t_name	*tmp;

	j = 0;
	ft_path_check(d);
	tmp = d->path;
	while (tmp != NULL && tmp->d_name != NULL)
	{
		d->head = get_names(tmp->d_name);
		if (d->nb_path > 1)
			ft_printf("%s:\n", tmp->d_name);
		print_list_basic(d->head);
		if (++j < d->nb_path)	
			ft_printf("\n\n");
		else 
			ft_printf("\n");
		ft_del_list(&d->head);
		tmp = tmp->next;
	}
	if (d->path != NULL)
		ft_del_list(&d->path);
}

int	main(int argc, char **argv)
{
	t_dir d;

	d.nb_argc = argc;
	if (argc == 1)
	{
		ft_ls_0(&d);
		return (0);
	}
	else
	{
	//	ft_printf("SEGF BALISE Main 1\n");
		ft_flags(argv, &d);
	//	ft_printf("SEGF BALISE Main 2\n");
		if (d.options == 0)
			ft_ls_no_op(&d);
		else if (d.R == 1)
			ft_ls_gr(&d);
	}
	return (0);
}
