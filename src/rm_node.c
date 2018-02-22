/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:18:24 by msicot            #+#    #+#             */
/*   Updated: 2018/02/22 11:19:43 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_name		*rm_node(t_name *currPtr, char *value)
{
	t_name	*nextPtr;

	if (currPtr == NULL)
		return (NULL);
	if (currPtr->d_name == value)
	{
		nextPtr = currPtr->next;
		free(currPtr);
		return (nextPtr);
	}
	currPtr->next = rm_node(currPtr->next, value);
	return (currPtr);
}
