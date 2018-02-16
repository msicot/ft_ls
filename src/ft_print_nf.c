/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:20:45 by msicot            #+#    #+#             */
/*   Updated: 2018/02/16 20:06:44 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_width_ws(void)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	return (ws.ws_col);
}

static void	ft_ordered_list(t_name **head)
{
	t_name	*n;
	char	*tmp;
	t_name	*start;

	start = *head;
	n = start;
	while (n->next != NULL)
	{
		if (ft_strcmp(n->d_name, n->next->d_name) > 0 && n->next != NULL)
		{
			tmp = n->d_name;
			n->d_name = n->next->d_name;
			n->next->d_name = tmp;
			n = start;
		}
		else 
			n = n->next;
	}
}

static void	ft_del_list(t_name **head)
{
	t_name	*tmp;
	t_name	*start;

	start = *head;
	while (start)
	{
		tmp = start;;
		ft_printf("d_name->%s\n", start->d_name);
		start = start->next;
		free(tmp);
	}
//	tmp = NULL;
}

static t_name **ft_list_crea(t_name **head, DIR *dp)
{
	t_name			*start;
	t_name			*tmp;
	struct dirent	*dent;

	if (!(start = (t_name*)malloc(sizeof(t_name))))
		return (NULL);
	start->next = NULL;
	head = &start;
	if ((dent = readdir(dp)) != NULL)
	start->d_name = dent->d_name;
	while ((dent = readdir(dp)) != NULL)
	{
		if (!(tmp = (t_name*)malloc(sizeof(t_name))))
		return (NULL);
		start->next = tmp;
		tmp->d_name = dent->d_name;
		tmp->next = NULL;
		start = tmp;
	}
	ft_ordered_list(head);
	return (head);

}

void		ft_print_nf(void)
{
	t_dir	stru;
	t_name	*names;
	t_name	*n;

	stru.col = ft_width_ws();
	stru.dp = opendir(".");
	if (stru.dp != NULL)
	{
		ft_list_crea(&names, stru.dp);

		n = names;
		while (n != NULL)
		{
			ft_printf("%s\n", n->d_name);
			n = n->next;
		}
	//	n = &names;
	/*	while (n != NULL)
		{
			ft_printf("\t%s\n", n->d_name);
			n = n->next;
		}*/
		ft_del_list(&names);
	}
}
