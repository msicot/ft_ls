/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:17:20 by msicot            #+#    #+#             */
/*   Updated: 2018/03/05 14:09:49 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*filetype(struct stat *sb)
{
	if (S_ISREG(sb->st_mode))
		return ("-");
	if (S_ISDIR(sb->st_mode))
		return ("d");
	if (S_ISCHR(sb->st_mode))
		return ("c");
	if (S_ISLNK(sb->st_mode))
		return ("l");
	if (S_ISFIFO(sb->st_mode))
		return ("p");
	if (S_ISSOCK(sb->st_mode))
		return ("b");
	return (NULL);
}

char	*u_name(struct stat *sb)
{
	struct passwd	*pw;

	if ((pw = getpwuid(sb->st_uid)) == NULL)
		return (NULL);
	return (pw->pw_name);
}

char	*gr_name(struct stat *sb)
{
	struct group	*gr;

	if ((gr = getgrgid(sb->st_gid)) == NULL)
		return (NULL);
	return (gr->gr_name);
}

char	*perm(struct stat *sb)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(9)))
		return (NULL);
	str[i++] = (sb->st_mode & S_IRUSR) ? 'r' : '-';
	str[i++] = (sb->st_mode & S_IWUSR) ? 'w' : '-';
	str[i++] = (sb->st_mode & S_IXUSR) ? 'x' : '-';
	str[i++] = (sb->st_mode & S_IRGRP) ? 'r' : '-';
	str[i++] = (sb->st_mode & S_IWGRP) ? 'w' : '-';
	str[i++] = (sb->st_mode & S_IXGRP) ? 'x' : '-';
	str[i++] = (sb->st_mode & S_IROTH) ? 'r' : '-';
	str[i++] = (sb->st_mode & S_IWOTH) ? 'w' : '-';
	str[i++] = (sb->st_mode & S_IXOTH) ? 'x' : '-';
	return (str);
}
