/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:10:26 by msicot            #+#    #+#             */
/*   Updated: 2018/02/20 14:25:09 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_name	*get_names(char *path)
{
	DIR		*dir;
	t_name	*head;

	head = NULL;
	dir = opendir(path);
	if (dir != NULL)
	{
		head = create_list(dir);
		order_list(&head);
	}
	closedir(dir);
	return (head);
}