/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:26:18 by msicot            #+#    #+#             */
/*   Updated: 2018/03/05 14:51:15 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_list_0(t_name *head)
{
	t_name *tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->d_name[0] != '.')
			ft_printf("%s\n", tmp->d_name);
		tmp = tmp->next;
	}
}

void		ft_ls_0(t_dir *d)
{
	t_name	*head;
	int		i;

	i = d->nb_argc;
	head = get_names(".", d);
	print_list_0(head);
	ft_del_list(&head);
}
