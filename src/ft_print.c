/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:19:05 by msicot            #+#    #+#             */
/*   Updated: 2018/03/05 17:04:22 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_it(struct s_padding pad, t_name *node)
{
	ft_printf("%s%s  %*d %*s  %*s  %*d %s %s", node->info.type,
			node->info.perm, pad.ln_pad, node->info.nb_l, pad.u_pad,
			node->info.user, pad.gr_pad, node->info.group, pad.sz_pad,
			node->info.size, node->info.date, node->d_name);
}

void		ft_print_l(struct s_padding pad, t_name **head, t_dir *d, int i)
{
	t_name	*node;

	node = *head;
	if (i == 2 && d->a == 0)
		return ;
	ft_printf("total %d\n", pad.nb_block);
	while (node != NULL)
	{
		--i;
		if (d->a == 1)
		{
			print_it(pad, node);
			if (i > 0)
				ft_printf("\n");
		}
		else if (node->d_name[0] != '.')
		{
			print_it(pad, node);
			if (i > 0)
				ft_printf("\n");
		}
		ft_del_info(&node->info);
		node = node->next;
	}
}

int			ft_count_lst(t_name *head)
{
	t_name	*tmp;
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

void		print_list_basic(t_name *head, int hidden, t_dir *d)
{
	t_name	*tmp;
	int		i;

//	i = (d->r == 0 ) ? ft_count_lst(head) : ft_count_lst(head) - 2;
	i = ft_count_lst(head);
	tmp = head;
	while (tmp != NULL)
	{
		--i;
		if (hidden == 1)
		{
			ft_printf("%s i=%d", tmp->d_name,i);
			if ((i > 0))
				ft_printf("\n");
		}
		else if (tmp->d_name[0] != '.')
		{
			ft_printf("%s", tmp->d_name, i);
			if ((i > 0 && d->r == 0) || (i >3 && d->r == 1))
				ft_printf("\n");
		}
		tmp = tmp->next;
	}
}

void		ft_printl(t_name **head, t_dir *d)
{
	if (d->l == 0)
		print_list_basic(*head, d->a, d);
	else
		ft_option_l(head, d);
}
