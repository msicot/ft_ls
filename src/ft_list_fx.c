/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_fx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:34:18 by msicot            #+#    #+#             */
/*   Updated: 2018/02/22 16:57:25 by msicot           ###   ########.fr       */
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

static void	ft_path_name(t_name **node, char *path)
{
	t_name	*tmp;
	char	*slash;
	char	*bin;

	if (!(slash = ft_strdup("/")))
		return ;
	tmp = *node;
	while (tmp != NULL)
	{
		tmp->path = ft_strjoin(path, slash);
		bin = tmp->path;
		tmp->path = ft_strjoin(tmp->path, tmp->d_name);
		ft_strdel(&bin);
		tmp = tmp->next;
	}
	ft_strdel(&slash);
}

t_name	*create_list(DIR *dir)
{
	t_name			*head;
	t_name			*tmp;
	t_name			*node;
	struct dirent	*dent;

	if (!(head = ft_create_node()))
		return (NULL);
	if ((dent = readdir(dir)) != NULL)
		head->d_name = dent->d_name;
	node = head;
	while ((dent = readdir(dir)) != NULL)
	{
		if ((tmp = ft_create_node()) == NULL)
			return (NULL);
		node->next = tmp;
		tmp->next = NULL;
		tmp->d_name = dent->d_name;
		node = node->next;
	}
	node->next = NULL;
	dent = NULL;
	return (head);
}


t_name	*create_list_path(DIR *dir, char *path)
{
	t_name			*head;
	t_name			*tmp;
	t_name			*node;
	struct dirent	*dent;

	if (!(head = ft_create_node()))
		return (NULL);
	if ((dent = readdir(dir)) != NULL)
		head->d_name = dent->d_name;
	node = head;
	while ((dent = readdir(dir)) != NULL)
	{
		if ((tmp = ft_create_node()) == NULL)
			return (NULL);
		node->next = tmp;
		tmp->next = NULL;
		tmp->d_name = dent->d_name;
		node = node->next;
	//	ft_printf("create list path \n");
	}
	node->next = NULL;
	dent = NULL;
	ft_path_name(&head, path);
//	ft_printf("test %s<-\n", head->path);
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
