/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:30:25 by msicot            #+#    #+#             */
/*   Updated: 2018/02/23 12:10:38 by msicot           ###   ########.fr       */
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

static	t_name	*get_names2(DIR *dir, char *path)
{
	t_name	*head;

	head = NULL;
	if (dir != NULL)
	{
		head = create_list_path(dir, path);
		order_list(&head);
	}
	return (head);
}

static int	ft_is_point(char *value)
{
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
	DIR		*dir;

	ft_printf("\tft_recursive(%s)\n", path);

	if ((dir = opendir(path)) == NULL)
			return ;
	head = get_names2(dir, path);
	tmp = head;
	print_list_basic(head);
	ft_printf("\n\n");
	while (tmp != NULL && tmp->d_name != NULL)
	{
		ft_printf("\tname =%s\n", tmp->d_name);
		if (ft_is_dir(tmp->path) == 1 && ft_is_point(tmp->d_name) == 0)
		{
			ft_printf("\t%s ->IS_DIR\n", tmp->d_name);
			ft_printf("\tpath->%s\n", tmp->path);
			ft_printf("%s:\n",tmp->path);
			ft_recursive(tmp->path);
		}
		tmp = tmp->next;
	}
	if (dir != NULL)
	closedir(dir);
	if (head != NULL)
		ft_del_listp(&head);
}

void	ft_ls_gr(t_dir *d)
{
	t_name	*tmp;

	ft_path_check(d);
	if (d->path == NULL)
	{
		d->path = ft_create_node();
		d->path->d_name = ".";
		d->path->next = NULL;
	}
	tmp = d->path;
	while (tmp != NULL && tmp->d_name != NULL)
	{
		ft_recursive(tmp->d_name);
		tmp = tmp->next;
	}
	if (d->path != NULL)
		ft_del_list(&d->path);
}















/*int	ft_is_dir(char *path)
{
	DIR	*directory;

	directory = opendir(path);
	if (directory != NULL)
	{
		closedir(directory);
		return (1);
	}
//	else 
//		closedir(directory);
	return (0);
}
int	ft_is_dir(char *path)
{
	DIR	*directory;

	directory = opendir(path);
	if (directory != NULL)
	{
		closedir(directory);
		return (1);
	}
//	else 
//		closedir(directory);
	return (0);
}

static int	ft_nb_dir(t_dir *d)
{
	int		i;
	t_name	*tmp;

	tmp = d->head;
	while (tmp != NULL)
	{
		i += ft_is_dir(tmp->d_name);
		tmp = tm->next;
	}
	return (i);
}

static void	ft_recu(char *path, t_dir *d)
{
	t_name	*head;
	t_name	*tmp;

	head = get_names(path);;
	tmp = head;
	while (tmp != NULL)
	{
//	ft_printf("\ntest\n");
			if ((ft_strcmp(tmp->d_name, ".") != 0)
					&& (ft_strcmp(tmp->d_name, "..") != 0)
					&& 
		if (ft_is_dir(tmp->d_name) == 1 && tmp->d_name[0] != '.')
		{
			ft_printf("%s:\n", tmp->d_name);
			ft_recu(tmp->d_name);
			ft_printf("\n");
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	ft_del_list(&head);
}*/


