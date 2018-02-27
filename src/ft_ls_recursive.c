/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:30:25 by msicot            #+#    #+#             */
/*   Updated: 2018/02/27 17:10:53 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_is_dir(char *f_name)
{
	struct stat	sb;

	if (lstat(f_name, &sb) == 0)
	{
	//	ft_printf("\t\tout put ?\n");
		if (S_ISDIR(sb.st_mode))
			return (1);
	}
	return (0);
}

static	t_name	*get_names2(char *path)
{
	t_name	*head;
	DIR		*dir;

	if ((dir = opendir(path)) == NULL)
		return (NULL);
	else 
	{
		head = create_list_path(dir, path);
		order_list(&head);
		closedir(dir);
	}
	return (head);
}

static int	ft_is_point(char *value)
{
	if (value == NULL)
		return (0);
	if (ft_strcmp(value, ".") == 0)
		return (1);
	if (ft_strcmp(value, "..") == 0)
		return (1);
	if (value[0] == '.')
		return (1);
	return (0);
}

static void	ft_recursive(char *path)
{
	t_name	*head;
	t_name	*tmp;

	if ((head = get_names2(path)) == NULL)
		return ;
	tmp = head;
	print_list_basic(head);
	ft_printf("\n\n");
	while (tmp != NULL && tmp->d_name != NULL)
	{
		if (ft_is_dir(tmp->path) == 1 && ft_is_point(tmp->d_name) == 0)
		{
			ft_printf("%s:\n",tmp->path);
			ft_recursive(tmp->path);
		}
		tmp = tmp->next;
	}
	if (head != NULL)
		ft_del_listp(&head);
}

void	ft_ls_gr(t_dir *d)
{
	t_name	*tmp;

	ft_path_check(d);
	if (d->path == NULL)
		d->path = ft_create_node(".");
	tmp = d->path;
	ft_printf("ls_gr\n");
	while (tmp != NULL && tmp->d_name != NULL)
	{
		ft_recursive(tmp->d_name);
		tmp = tmp->next;
	}
	if (d->path != NULL)
		ft_del_list(&d->path);
}
