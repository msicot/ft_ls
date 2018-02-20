/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:04:10 by msicot            #+#    #+#             */
/*   Updated: 2018/02/20 16:32:03 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_no_op(t_dir *d)
{
	int	i;
	int	j;

	j = 0;	
	i = 0;
	while (i < d->nb_path)
	{
		d->head = get_names(d->p[i]);
		ft_printf("%s:\n", d->p[i++]);
		print_list_basic(d->head);
		if (++j < d->nb_path)	
			ft_printf("\n\n");
		else 
			ft_printf("\n");
		ft_del_list(&d->head);
	}
}

int	main(int argc, char **argv)
{
	t_dir d;

	d.nb_argc = argc;
	d.p = NULL;
	if (argc == 1)
	{
		ft_ls_0(&d);
		return (0);
	}
	else
	{
		ft_flags(argv, &d);
		if (d.options == 0)
			ft_ls_no_op(&d);
		else if (d.R == 1)
			ft_ls_gr(&d);
	}
	ft_freeing(d.p, &d);
	return (0);
}
