/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:19:40 by msicot            #+#    #+#             */
/*   Updated: 2018/03/01 17:20:15 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_need(t_name *s, t_name **f, t_name **b)
{
	f = &s;
	(b) = NULL;
}

static void		fbsplit(t_name *source, t_name **front_r, t_name **back_r)
{
	t_name	*fast;
	t_name	*slow;

	slow = NULL;
	if (source == NULL || source->next == NULL)
		ft_need(source, front_r, back_r);
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
	}
	*front_r = source;
	*back_r = slow->next;
	slow->next = NULL;
}

static t_name	*sortedmerge(t_name *a, t_name *b)
{
	t_name *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->d_name, b->d_name) <= 0)
	{
		result = a;
		result->next = sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next);
	}
	return (result);
}

void			ft_merge_sort(t_name **head_ref)
{
	t_name	*head;
	t_name	*a;
	t_name	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	fbsplit(head, &a, &b);
	ft_merge_sort(&a);
	ft_merge_sort(&b);
	*head_ref = sortedmerge(a, b);
}
