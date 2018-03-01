/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:10:26 by msicot            #+#    #+#             */
/*   Updated: 2018/03/01 17:08:38 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_name	*get_names(char *path)
{
	DIR		*dir;
	t_name	*head;

	head = NULL;
	if (!(dir = opendir(path)))
		return (NULL);
	else
	{
		head = create_list(dir);
		ft_merge_sort(&head);
		closedir(dir);
	}
	return (head);
}

t_name	*get_names2(char *path)
{
	t_name	*head;
	DIR		*dir;

	if ((dir = opendir(path)) == NULL)
		return (NULL);
	else
	{
		head = create_list_path(dir, path);
		ft_merge_sort(&head);
		closedir(dir);
	}
	return (head);
}
