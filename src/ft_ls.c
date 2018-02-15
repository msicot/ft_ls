/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:04:10 by msicot            #+#    #+#             */
/*   Updated: 2018/02/15 18:49:07 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	DIR	*dir;
	struct dirent *dent;
	if (argc == 0)
		dir = opendir(".");
	else if (argv[0] != NULL)
	{
		dir = opendir(".");
		if (dir != NULL)
		{
			while ((dent = readdir(dir)) != NULL)
				ft_printf("%s\n",dent->d_name);
		}
	}
	return (0);
}

