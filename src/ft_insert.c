/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:14:55 by msicot            #+#    #+#             */
/*   Updated: 2018/03/13 17:38:37 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*static int	ft_compare(t_name *a, t_name *b, t_dir *d)
{
	int i;

	i = d->nb_path;
	return(ft_strcmp(a->d_name, b->d_name));

}*/

static t_name *get_prev(t_name *head, t_name *a)
{
	t_name	*tmp;
	t_name	*pre_a;

	pre_a = NULL;
	if (head == a)
		return (NULL);
	tmp = head;
	while (tmp && tmp != a)
	{
		pre_a = tmp;
		tmp = tmp->next;
	}
	return (pre_a);
}

static void	ft_swap_ptr(t_name **head, t_name **a, t_name **b)
{
	t_name	*pre_a;
	t_name	*pre_b;
	t_name	*temp;

	if ((*head) == NULL || (*a) == NULL || (*b) == NULL)
		return ;
	temp = NULL;
	pre_a = get_prev(*head, *a);
	pre_b = get_prev(*head, *b);
	if (pre_a)
		pre_a->next = (*b);
	if (pre_b)
		pre_b->next = (*a);
	temp = (*a)->next;
	(*a)->next = (*b)->next;
	(*b)->next = temp;
	if ((*head) == (*a))
		*head = *b;
	else
		if (*head == *b)
			*head = *a;
}

void	ft_sort_insert(t_name **head_ref, t_dir *d)
{
	t_name	*tmp;
	t_name	*curr;
	t_name	*head;


	
	if (head_ref == NULL)
		return ;
	if (d->nb_path >= 0)
		d->nb_path += 0;
	head = *head_ref;
	curr = head;
	tmp = head;
//	while (curr != NULL)
//	{
	//	tmp = curr;
//		lowest = curr;
		while (tmp != NULL && tmp->next != NULL)
		{
			if (ft_strcmp(tmp->d_name, tmp->next->d_name) < 0)
			{
				ft_swap_ptr(&head, &tmp, &tmp->next);
//				ft_printf("\tstrcmp low\n");
				tmp = head;;
			}
			else
				tmp = tmp->next;
	/*		if (tmp == NULL && ft_strcmp(lowest->d_name, curr->d_name) < 0) 
			{
				ft_swap_ptr(head_ref, &curr, &lowest);
			}*/
//		}
//		curr = curr->next;
	}
}
