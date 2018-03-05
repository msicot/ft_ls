/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:09:46 by msicot            #+#    #+#             */
/*   Updated: 2018/03/05 13:22:27 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	bubble(t_name **head_ref)
{
	t_name	*head;
	int		i;
	t_name	*curr;
	t_name	*tmp;

	head = *head_ref;
	if (head == NULL || head->next == NULL)
		return ;
	tmp = head;
	curr = tmp;
	if (ft_strcmp(curr->d_name, curr->next->d_name <= 0))
	{

	}
	

}
