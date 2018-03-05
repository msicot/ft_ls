/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:09:03 by msicot            #+#    #+#             */
/*   Updated: 2018/03/05 14:39:40 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	time_stamp(char *path)
{
	struct stat	sb;

	if (lstat(path, &sb) == 0)
		return (sb.st_mtime);
	else
		perror(path);
	return (0);
}

char	*time_info(struct stat *sb)
{
	char	*str;
	time_t	now;
	char	*yr;
	char	*tmp;

	if ((now = time(NULL)) == -1)
		perror("time");
	if (!(str = ft_strdup(ctime(&sb->st_mtime))))
		return (NULL);
	str = ft_strncpy(str, &str[4], ft_strlen(str));
	if (now - sb->st_mtime > 15724800)
	{
		if (!(yr = ft_strdup(&str[ft_strlen(str) - 5])))
			return (NULL);
		yr[4] = '\0';
		ft_bzero(&str[ft_strlen(str) - 13], 13);
		str[7] = ' ';
		tmp = str;
		str = ft_strjoin(str, yr);
		ft_strdel(&tmp);
		ft_strdel(&yr);
		return (str);
	}
	ft_bzero(&str[ft_strlen(str) - 9], 9);
	return (str);
}
