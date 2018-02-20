/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:30:25 by msicot            #+#    #+#             */
/*   Updated: 2018/02/20 18:41:25 by msicot           ###   ########.fr       */
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
	else 
		closedir(directory);
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
	print_list_basic(head);
	while (tmp != NULL)
	{
	ft_printf("\ntest\n");
			if ((ft_strcmp(tmp->d_name, ".") != 0)
					&& (ft_strcmp(tmp->d_name, "..") != 0)
					&& ft_is_dir(tmp->d_name) == 1)
			{
				ft_printf("%s:\n", tmp->d_name);
				ft_recu(tmp->d_name);
				tmp = tmp->next;
			}
		else
			tmp = tmp->next;
	}
	ft_del_list(&head);
}

void	ft_ls_gr(t_dir *d)
{
		int	i;
		int	j;

		j = 0;
		i = 0;
		while (i < d->nb_path)
		{
			d->head = get_names(d->p[i++]);
			ft_recu(d->head->d_name);
		}
}
