/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:17:20 by msicot            #+#    #+#             */
/*   Updated: 2018/03/20 14:49:01 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*u_name(struct stat *sb)
{
	struct passwd	*pw;
	char			*str;

	str = NULL;
	if ((pw = getpwuid(sb->st_uid)) != NULL)
		str = ft_strdup(pw->pw_name);
	else
		str = ft_itoa(sb->st_uid);
	return (str);
}

char	*gr_name(struct stat *sb)
{
	struct group	*gr;
	char			*str;

	str = NULL;
	if ((gr = getgrgid(sb->st_gid)) != NULL)
		str = ft_strdup(gr->gr_name);
	else
		str = ft_itoa(sb->st_gid);
	return (str);
}

void	get_majmin(struct stat *sb, t_lstat **info)
{
	t_lstat	*tmp;

	tmp = *info;
	tmp->maj_min = 1;
	tmp->maj = major(sb->st_rdev);
	tmp->size = minor(sb->st_rdev);
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
	if (sb->st_mode & S_ISUID)
		str[i++] = (sb->st_mode & S_IXUSR) ? 's' : 'S';
	else
		str[i++] = (sb->st_mode & S_IXUSR) ? 'x' : '-';
	str[i++] = (sb->st_mode & S_IRGRP) ? 'r' : '-';
	str[i++] = (sb->st_mode & S_IWGRP) ? 'w' : '-';
	if ((sb->st_mode & S_ISGID))
		str[i++] = (sb->st_mode & S_IXGRP) ? 's' : 'S';
	else
		str[i++] = (sb->st_mode & S_IXGRP) ? 'x' : '-';
	str[i++] = (sb->st_mode & S_IROTH) ? 'r' : '-';
	str[i++] = (sb->st_mode & S_IWOTH) ? 'w' : '-';
	if (sb->st_mode & S_ISVTX)
		str[i] = (sb->st_mode & S_IXOTH) ? 't' : 'T';
	else
		str[i] = (sb->st_mode & S_IXOTH) ? 'x' : '-';
	return (str);
}
