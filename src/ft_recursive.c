/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:30:25 by msicot            #+#    #+#             */
/*   Updated: 2018/03/20 12:32:43 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_is_dir(char *f_name)
{
	struct stat	sb;

	if (lstat(f_name, &sb) == 0)
	{
		if (S_ISDIR(sb.st_mode))
			return (1);
	}
	else
	{
		ft_printf("ls: %s ", f_name);
		perror(f_name);
	}
	return (0);
}

static int	ft_is_point(char *value, t_dir *d)
{
	if (value == NULL)
		return (0);
	if (ft_strcmp(value, ".") == 0)
		return (1);
	if (ft_strcmp(value, "..") == 0)
		return (1);
	if (value[0] == '.' && d->a == 0)
		return (1);
	return (0);
}

static int	ft_check_stat(char *path)
{
	struct stat	sb;

	if (lstat(path, &sb) == -1 || (((sb.st_mode) & S_IRUSR) != 0 &&
				((sb.st_mode) & S_IXUSR) == 0))
		return (0);
	else if (lstat(path, &sb) == -1)
	{
		ft_err_perm(path);
		return (1);
	}
	return (1);
}

static void	ft_recursive(char *path, t_dir *d)
{
	t_name		*head;
	t_name		*tmp;

	head = get_names2(path, d, path);
	tmp = head;
	ft_print_opt(&head, d);
	while (tmp != NULL && tmp->d_name != NULL)
	{
		if (ft_is_dir(tmp->path) == 1 && ft_is_point(tmp->d_name, d) == 0)
		{
			ft_printf("\n%s:\n", tmp->path);
			if (ft_check_stat(tmp->path) == 0)
			{
				tmp = tmp->next;
				continue ;
			}
			ft_recursive(tmp->path, d);
		}
		tmp = tmp->next;
	}
	if (head != NULL)
		ft_del_listp(&head);
}

void		ft_ls_gr(t_dir *d)
{
	t_name	*tmp;
	int		i;

	i = ft_count_lst(d->path);
	if (d->path == NULL && d->nb_path == 0)
		d->path = ft_create_node(".");
	tmp = d->path;
	while (tmp != NULL && tmp->d_name != NULL)
	{
		if (d->nb_path > 1)
			ft_printf("%s:\n", tmp->d_name);
		ft_recursive(tmp->d_name, d);
		tmp = tmp->next;
		if (i > 1)
			ft_printf("\n");
		--i;
	}
	if (d->path != NULL)
		ft_del_list(&d->path);
}
