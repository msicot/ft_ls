/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:09:03 by msicot            #+#    #+#             */
/*   Updated: 2018/03/12 19:04:01 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t		time_stamp(char *path)
{
	struct stat	sb;

	if (lstat(path, &sb) == 0)
		return (sb.st_mtime);
	else
		perror(path);
	return (0);
}

static char	*ft_future(char **s)
{
	char	*yr;
	char	*tmp;
	char	*str;

	str = *s;
	if (!(yr = ft_strdup(" 10000")))
		return (NULL);
	ft_bzero(&str[7], ft_strlen(str) - 7);
	tmp = str;
	str = ft_strjoin(str, yr);
	ft_strdel(&tmp);
	ft_strdel(&yr);
	return (str);
}

static char	*ft_six(char **s)
{
	char	*yr;
	char	*str;
	char	*tmp;

	str = *s;
	if (!(yr = ft_strdup(&str[ft_strlen(str) - 5])))
		return (NULL);
	yr[4] = '\0';
	ft_bzero(&str[ft_strlen(str) - 13], 13);
	str[7] = ' ';
	tmp = str;
	str = ft_strjoin(str, yr);
	ft_strdel(&yr);
	ft_strdel(&tmp);
	return (str);
}

char		*time_info(struct stat *sb)
{
	char	*str;
	time_t	now;
	char	*tmp;

	if ((now = time(NULL)) == -1)
		perror("time");
	if (!(str = ft_strdup(ctime(&sb->st_mtime))))
		return (NULL);
	str = ft_strncpy(str, &str[4], ft_strlen(str));
	if (now - sb->st_mtime > 15724800)
	{
		tmp = str;
		str = ft_six(&str);
		return (str);
	}
	else if (now - sb->st_mtime < 0)
	{
		str = ft_future(&str);
		return (str);
	}
	ft_bzero(&str[ft_strlen(str) - 9], 9);
	return (str);
}
