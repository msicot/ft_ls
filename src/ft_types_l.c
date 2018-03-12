/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:17:20 by msicot            #+#    #+#             */
/*   Updated: 2018/03/12 18:51:25 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
