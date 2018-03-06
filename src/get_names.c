/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:10:26 by msicot            #+#    #+#             */
/*   Updated: 2018/03/06 16:52:52 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_name	*get_names(char *path, t_dir *d)
{
	DIR		*dir;
	t_name	*head;

	head = NULL;
	if (!(dir = opendir(path)))
		return (NULL);
	else
	{
		head = create_list(dir);
		ft_merge_sort(&head, d);
		if (d->t == 1)
			ft_merge_sort_t(&head, d);
		closedir(dir);
	}
	return (head);
}

t_name	*get_names2(char *path, t_dir *d, char *str)
{
	t_name	*head;
	DIR		*dir;

	if ((dir = opendir(path)) == NULL)
	{
		ft_err_perm(str);
		return(NULL);
	}
	else
	{
		head = create_list_path(dir, path);
		if (d->r == 0)
			ft_merge_sort(&head, d);
		else
			ft_merge_sort_r(&head, d);
		if (d->t == 1)
		{
			ft_merge_sort_t(&head, d);
		}
		closedir(dir);
	}
	return (head);
}
