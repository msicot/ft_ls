/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:21:35 by msicot            #+#    #+#             */
/*   Updated: 2018/03/20 11:20:24 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_del_info(t_lstat *info)
{
	if (info != NULL)
	{
		ft_strdel(&info->type);
		ft_strdel(&info->user);
		ft_strdel(&info->group);
		ft_strdel(&info->date);
		ft_strdel(&info->perm);
		ft_strdel(&info->acl);
	}
}

void	ft_set_info(t_lstat *info)
{
		info->type = NULL;
		info->user = NULL;
		info->group = NULL;
		info->date = NULL;
		info->perm = NULL;
		info->acl = NULL;
}

