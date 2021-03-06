/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:41:23 by msicot            #+#    #+#             */
/*   Updated: 2018/03/20 12:27:40 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_flag(char c)
{
	char	*str;

	if (c == '\0')
		return ;
	str = "[-Ralrt1]";
	ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls %s [file ...]\n",
			c, str);
	exit(1);
}

void	ft_err_path(char *s)
{
	char	*err;

	if (s[0] == '\0')
		err = ft_strjoin("ft_ls: fts_open", s);
	else
		err = ft_strjoin("ft_ls: ", s);
	perror(err);
	ft_strdel(&err);
}

void	ft_err_perm(char *str)
{
	char	*err;
	char	*s2;
	int		i;

	if (str == NULL)
		return ;
	i = ft_strlen(str);
	if (!(s2 = ft_strdup(str)))
		return ;
	while (s2[i] != '/' && i > 0)
		--i;
	if (s2[i] == '/')
		i++;
	if (!(s2 = ft_strncpy(s2, &s2[i], ft_strlen(str))))
		return ;
	if (!(err = ft_strjoin("ft_ls: ", s2)))
		return ;
	perror(err);
	ft_strdel(&err);
	ft_strdel(&s2);
}
