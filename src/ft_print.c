/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:19:05 by msicot            #+#    #+#             */
/*   Updated: 2018/03/20 10:23:18 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_it(struct s_padding pad, t_name *node)
{
	if (node && node->info.type != NULL)
	{
	ft_printf("%s%s%s ", node->info.type, node->info.perm, node->info.acl);
	ft_printf("%*d %-*s  %-*s  ", pad.ln_pad, node->info.nb_l, pad.u_pad,
			node->info.user, pad.gr_pad, node->info.group);
	if (node->info.maj_min == 1)
	{
		ft_printf("%*d, ", pad.maj_pad, node->info.maj);
	}
	else if (pad.maj_pad > 0)
		ft_printf(" %*s ", pad.maj_pad, "  ");
	ft_printf("%*d %s %s\n", pad.sz_pad, node->info.size, node->info.date,
			node->d_name);
	}
}

void		ft_print_l(struct s_padding pad, t_name **head, t_dir *d, int i)
{
	t_name	*node;

	node = *head;
	if (ft_total(node) == 1 && d->a == 0)
		return ;
	ft_printf("total %d\n", pad.nb_block);
	while (node != NULL)
	{
		--i;
		if (node->d_name[0] == '.' && d->a == 0)
		{
			ft_del_info(&node->info);
			node = node->next;
			continue ;
		}
		else
		{
			print_it(pad, node);
		}
		ft_del_info(&node->info);
		node = node->next;
	}
}

int			ft_count_lst(t_name *head)
{
	t_name	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}

void		print_list_basic(t_name *head, t_dir *d)
{
	t_name	*node;
	int		i;

	i = ft_count_lst(head);
	node = head;
	while (node != NULL)
	{
		--i;
		if (node->d_name[0] == '.' && d->a == 0)
		{
			node = node->next;
			continue ;
		}
		else
		{
			ft_printf("%s\n", node->d_name);
		}
		node = node->next;
	}
}

void		ft_print_opt(t_name **head, t_dir *d)
{
	if (d->l == 0)
		print_list_basic(*head, d);
	else
		ft_option_l(head, d);
}
