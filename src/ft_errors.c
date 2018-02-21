/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:41:23 by msicot            #+#    #+#             */
/*   Updated: 2018/02/21 18:22:26 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_flag(char c)
{
	ft_printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n", c);
	exit(1);
}

void	ft_err_path(char *s)
{
	ft_printf("ls: %s: No such file or directory\n", s);
}
