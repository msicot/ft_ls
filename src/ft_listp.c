/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:31:39 by msicot            #+#    #+#             */
/*   Updated: 2018/03/02 13:40:45 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_padd_0(struct s_padding *info)
{
	info->u_pad = 0;
	info->gr_pad = 0;
	info->sz_pad = 0;
	info->ln_pad = 0;
	info->nb_block = 0;
}

void		ft_del_listp(t_name **head)
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
		tmp->path = ft_strjoin(path, slash);
		bin = tmp->path;
		tmp->path = ft_strjoin(tmp->path, tmp->d_name);
		ft_strdel(&bin);
		tmp = tmp->next;
	}
	ft_strdel(&slash);
}

t_name		*create_list_path(DIR *dir, char *path)
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
	ft_path_name(&head, path);
	return (head);
}

void		order_list_p(t_name **head)
{
	t_name	*n;
	char	*tmp;
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
