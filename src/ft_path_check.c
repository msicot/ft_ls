/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:27:27 by msicot            #+#    #+#             */
/*   Updated: 2018/02/21 19:24:35 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_name		*rm_node(t_name *tmp, char *d_name)
{
	t_name	*next;

	if (tmp == NULL)
		return (NULL);
	if (tmp->d_name == d_name)
	{
		next = tmp->next;
		free(tmp);
		return (next);
	}
	tmp->next = rm_node(tmp->next, d_name);
	return (tmp);
}

void	ft_path_check(t_name **head)
{
	struct stat	sb;
	t_name		*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (stat(tmp->d_name, &sb) == 0)
		{
			if (S_ISDIR(sb.st_mode))
				tmp = tmp->next;
			else if (S_ISREG(sb.st_mode))
			{
				ft_printf("%s\n", tmp->d_name);
				tmp = rm_node(tmp, tmp->d_name);
			}
		}
		else
		{
			perror(tmp->d_name);
			tmp = rm_node(tmp, tmp->d_name);
		}
	}
}
/*
void	ft_path_check(t_namer)
{

	ft_valid_path(d->path);
//	tmp = head;
}
*/
