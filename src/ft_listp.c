/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 10:03:43 by msicot            #+#    #+#             */
/*   Updated: 2018/02/23 10:04:51 by msicot           ###   ########.fr       */
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
		tmp = start;;
		ft_strdel(&tmp->path);
		start = start->next;
		free(tmp);
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
		bin = tmp->path;
		tmp->path = ft_strjoin(path, slash);
		bin = tmp->path;
		tmp->path = ft_strjoin(tmp->path, tmp->d_name);
		ft_strdel(&bin);
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
