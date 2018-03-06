/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:18:24 by msicot            #+#    #+#             */
/*   Updated: 2018/03/05 15:04:58 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_name		*rm_node(t_name *currptr, char *value)
{
	t_name	*nextptr;

	if (currptr == NULL)
		return (NULL);
	if (currptr->d_name == value)
	{
		nextptr = currptr->next;
		ft_strdel(&currptr->d_name);
		free(currptr);
		return (nextptr);
	}
	currptr->next = rm_node(currptr->next, value);
	return (currptr);
}

void		del_tab(char ***tab)
{
	int i;

	if (tab == NULL)
		return ;
	i = 0;
	while (i < 5)
		ft_strdel(tab[i++]);
}
