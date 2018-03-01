/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:19:05 by msicot            #+#    #+#             */
/*   Updated: 2018/03/01 14:44:05 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
static int	ft_count_lst(t_name *head)
{
	t_name *tmp;
	int		i;

	if (head == NULL)
		return (0);
	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}
void	print_list_basic(t_name *head, int hidden)
{
	t_name	*tmp;
	int		i;

	i = ft_count_lst(head);
	tmp = head;
	while (tmp != NULL)
	{
		--i;
		if (hidden == 1)
		{
			ft_printf("%s", tmp->d_name);
			if (i > 0)
				ft_printf("\n");
		}
		else if (tmp->d_name[0] != '.')
		{
			ft_printf("%s", tmp->d_name);
			if (i > 0)
				ft_printf("\n");
		}
		tmp = tmp->next;
	}
}

void	ft_printl(t_name **head, t_dir *d)
{
	if (d->l == 0)
		print_list_basic(*head, d->a);
	else
		ft_option_l(head, d);
}
