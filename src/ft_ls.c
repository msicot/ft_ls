/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:04:10 by msicot            #+#    #+#             */
/*   Updated: 2018/02/16 19:39:28 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
//	struct dirent	*dent;
//	struct winsize	ws;
//	DIR				*dp;
//	t_dir			struc;

	ft_parsing(argc, argv);
	/*
	dent = NULL;
	ioctl(0, TIOCGWINSZ, &ws);
	struc.col = ws.ws_col;
	ft_printf("%d argc and %d columns\n", argc, struc.col);
	if (argc == 1)
	{
		dp = opendir(".");
		if(dp != NULL)
		{
			ft_read_ls(&struc, dent)
			ft_printf("test\n");
			while ((dent = readdir(dp)) != NULL)
				ft_printf("%s\n", dent->d_name);
		}
	}
	else if (argv[0] != NULL)
	{
		return (0);
	}*/
	return (0);
}

