/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:20:45 by msicot            #+#    #+#             */
/*   Updated: 2018/02/19 15:58:22 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_width_ws(void)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	return (ws.ws_col);
}

void			ft_print_nf(t_dir *d)
{
	t_name	*head;
	t_name	*n;

	head = NULL;
	d->col = ft_width_ws();
	d->dp = opendir(".");
	if (d->dp != NULL)
	{
		head = ft_list_crea(d);
		n = head;
		ft_order_list(&head);
		ft_print_list(head);
		ft_del_list(&head);
	}
	closedir(d->dp);
}
