/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:30:25 by msicot            #+#    #+#             */
/*   Updated: 2018/02/22 16:58:19 by msicot           ###   ########.fr       */
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

	dir = opendir(path);

//	ft_printf("BALISE SEGF FT_RECURSIVE 0 name\n");
	head = get_names2(dir, path);
//	ft_printf("BALISE SEGF FT_RECURSIVE 0.6 name\n");
	tmp = head;
	print_list_basic(head);
	ft_printf("\n");
//	ft_printf("BALISE SEGF FT_RECURSIVE 1 name\n");
	while (tmp != NULL && tmp->d_name != NULL)
	{
	//	ft_printf("\ttmp->d_name->%s\n",tmp->d_name);
	//	ft_printf("\tIS_DIR=%d<- IS_POINT=%d\n", ft_is_dir(tmp->d_name), ft_is_point(tmp->d_name));
		if (ft_is_dir(tmp->path) == 1 && ft_is_point(tmp->d_name) == 0)
		{
//			ft_printf("\t\tIS_DIR\n");
//			ft_printf("./%s:\n",tmp->d_name);
			ft_recursive(tmp->path);
			ft_printf("\n");
		}
		tmp = tmp->next;
	}
	if (dir != NULL)
	closedir(dir);
//	ft_printf("BALISE SEGF FT_RECURSIVE 3\n");
	if (head != NULL)
		ft_del_list(&head);
//	ft_printf("BALISE SEGF FT_RECURSIVE 4\n");
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


