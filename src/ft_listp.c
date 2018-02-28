/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:31:39 by msicot            #+#    #+#             */
/*   Updated: 2018/02/28 15:35:33 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_del_listp(t_name **head)
{
	t_name	*tmp;
	t_name	*start;

	start = *head;
	while (start)
	{
		tmp = start;
		ft_strdel(&tmp->path);
		ft_strdel(&tmp->d_name);
		start = start->next;
		free(tmp);
	}
}

static void	ft_path_name(t_name **node, char *path)
{
	t_name	*tmp;
	char	*slash;
	char	*bin;

	if (path == NULL)
		return ;
	if (!(slash = ft_strdup("/")))
		return ;
	tmp = *node;
	while (tmp != NULL)
	{
	//	bin = tmp->path;
		tmp->path = ft_strjoin(path, slash);
		bin = tmp->path;
		tmp->path = ft_strjoin(tmp->path, tmp->d_name);
		ft_strdel(&bin);
	//	ft_printf("name=%s\t\tpath=%s\n", tmp->d_name, tmp->path);
		tmp = tmp->next;
	}
	ft_strdel(&slash);
}

t_name	*create_list_path(DIR *dir, char *path)
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
		tmp = tmp->next;;
	}
	ft_path_name(&head, path);
	//	ft_printf("test %s<-\n", head->path);
	return (head);
}

void	order_list_p(t_name **head)
{
	t_name	*n;
	char	*tmp;;
	t_name	*start;
	char	*tmp2;

	if (head == NULL)
		return ;
	start = *head;
	n = start;
	while (n->next != NULL)
	{
		if (ft_strcmp(n->d_name, n->next->d_name) > 0 && n->next != NULL)
		{
			tmp = n->d_name;
			tmp2 = n->path;
			n->d_name = n->next->d_name;
			n->path = n->next->path;
			n->next->d_name = tmp;
			n->next->path = tmp2;
			n = start;

		}
		else
			n = n->next;
	}
}
