/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_fx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:34:18 by msicot            #+#    #+#             */
/*   Updated: 2018/03/01 18:24:33 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_name	*create_list(DIR *dir)
{
	t_name			*head;
	t_name			*tmp;
	t_name			*node;
	struct dirent	*dent;

	head = NULL;
	tmp = NULL;
	node = NULL;
	if ((dent = readdir(dir)) != NULL)
	{
		if (!(node = ft_create_node(dent->d_name)))
			return (NULL);
	}
	head = node;
	tmp = node;
	while ((dent = readdir(dir)) != NULL)
	{
		if ((tmp->next = ft_create_node(dent->d_name)) == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (head);
}

void	order_list(t_name **head)
{
	t_name	*n;
	char	*tmp;
	t_name	*start;

	start = *head;
	if (start == NULL)
		return ;
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
		ft_strdel(&start->d_name);
		tmp = start;
		start = start->next;
		free(tmp);
	}
}

t_name	*ft_create_node(char *str)
{
	t_name	*node;

	if (!(node = (t_name*)malloc(sizeof(t_name))))
		return (NULL);
	node->d_name = ft_strdup(str);
	node->next = NULL;
	return (node);
}
