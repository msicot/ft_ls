/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetype_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:11:46 by msicot            #+#    #+#             */
/*   Updated: 2018/03/09 11:36:48 by msicot           ###   ########.fr       */
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
	if (S_ISBLK(sb->st_mode))
		return ("b");
	if (S_ISSOCK(sb->st_mode))
		return ("s");
	return (NULL);
}

char	*acl_type(const char *path, char *s)
{
	acl_t	acl;
	char	buff[1024];
	char	*str;

	str = ft_strdup(" ");
	acl = NULL;
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (acl != NULL)
	{
		if (ft_strcmp("l", s) != 0)
			str[0] = '+';
		acl_free((void *)acl);
		acl = NULL;
		return (str);
	}
	if (listxattr(path, buff, 1024, XATTR_NOFOLLOW) > 0)
		str[0] = '@';
	return (str);
}
