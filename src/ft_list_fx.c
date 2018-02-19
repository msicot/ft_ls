/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_fx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:34:18 by msicot            #+#    #+#             */
/*   Updated: 2018/02/19 14:42:34 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_list(t_name *head)
{
	t_name *tmp;
	tmp = head;
	while (tmp != NULL)
	{
		ft_printf("%s\n", tmp->d_name);
		tmp = tmp->next;
	}
}
t_name	*ft_list_crea(t_dir *d)
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

void		ft_order_list(t_name **head)
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

void	ft_del_list(t_name **head)
{
	t_name	*tmp;
	t_name	*start;

	start = *head;
	while (start)
	{
		tmp = start;;
//		free(tmp->d_name);
		start = start->next;
		free(tmp);
	}
}

t_name	*ft_create_node(void)
{
	t_name	*node;

	if (!(node = (t_name*)malloc(sizeof(t_name))))
		return (NULL);
	node->next = NULL; 
	return (node);
}
