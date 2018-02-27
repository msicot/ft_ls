/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_fx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:34:18 by msicot            #+#    #+#             */
/*   Updated: 2018/02/27 16:57:15 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_list_basic(t_name *head)
{
	t_name *tmp;
	int		i;

	if (head == NULL)
		return ;
	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		++i;
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp != NULL)
	{
		--i;
		if(tmp->d_name[0] != '.')
		{
			ft_printf("%s", tmp->d_name);
			if (i > 0)
				ft_printf("\n");
		}
		tmp = tmp->next;
	}
}

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

void		order_list(t_name **head)
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
	//node->d_name = str;
	node->next = NULL; 
	return (node);
}
