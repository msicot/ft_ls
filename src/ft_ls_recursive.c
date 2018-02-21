/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:18:09 by msicot            #+#    #+#             */
/*   Updated: 2018/02/21 11:29:25 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:30:25 by msicot            #+#    #+#             */
/*   Updated: 2018/02/21 10:15:05 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
/*
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
*/
static void	ft_recu(char *path)
{
	t_name	*head;
	t_name	*tmp;

	head = get_names(path);;
	tmp = head;
	while (tmp != NULL)
	{
//	ft_printf("\ntest\n");
		/*	if ((ft_strcmp(tmp->d_name, ".") != 0)
					&& (ft_strcmp(tmp->d_name, "..") != 0)
					&& */
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
}

void	ft_ls_gr(t_dir *d)
{
		int		i;
		int		j;
		t_name	*path;

		path = d->path;
		j = 0;
		i = 0;
		d->head = get_names(path->d_name);
		print_list_basic(d->head);
		while (i < d->nb_path)
		{
			ft_recu(path->d_name);
	//		d->head = get_names(path->d_name);
			path = path->next;
			i++;
		}
}
