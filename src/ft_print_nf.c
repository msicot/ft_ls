/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:20:45 by msicot            #+#    #+#             */
/*   Updated: 2018/02/19 11:04:52 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_width_ws(void)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	return (ws.ws_col);
}

static void		ft_order_list(t_name **head)
{
	t_name	*n;
	char	*tmp;
	t_name	*start;

	start = *head;
	n = start;
	while (n->next != NULL)
	{
		if (ft_strcmp(n->d_name, n->next->d_name) > 0 && n->next != NULL)
		{
			tmp = n->d_name;
			n->d_name = n->next->d_name;
			n->next->d_name = tmp;
			n = start;
		}
		else
			n = n->next;
	}
}

static t_name	*ft_list_crea(t_dir *d)
{
	t_name			*head;
	t_name			*tmp;
	t_name			*node;
	struct dirent	*dent;

	d->nb_w = 0;
	if (!(head = ft_create_node()))
		return (NULL);
	if ((dent = readdir(d->dp)) != NULL)
		head->d_name = dent->d_name;
	node = head;
	++d->nb_w;
	while ((dent = readdir(d->dp)) != NULL)
	{
		if ((tmp = ft_create_node()) == NULL)
			return (NULL);
		node->next = tmp;
		tmp->next = NULL;
		tmp->d_name = dent->d_name;
		node = node->next;
		++d->nb_w;
	}
	node->next = NULL;
	dent = NULL;
	return (head);
}

void			ft_print_nf(void)
{
	t_dir	stru;
	t_name	*head;
	t_name	*n;

	head = NULL;
	stru.col = ft_width_ws();
	stru.dp = opendir(".");
	if (stru.dp != NULL)
	{
		head = ft_list_crea(&stru);
		n = head;
		ft_order_list(&head);
		ft_print_line(head, &stru);
		ft_del_list(&head);
	}
	closedir(stru.dp);
}
