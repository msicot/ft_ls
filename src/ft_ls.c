/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:04:10 by msicot            #+#    #+#             */
/*   Updated: 2018/02/19 17:31:20 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_dir d)
{

}

int	main(int argc, char **argv)
{
//	struct dirent	*dent;
//	struct winsize	ws;
//	DIR				*dp;
	t_dir	d;

	d.nb_argc = argc;
	d.p = NULL;
	if (argc == 1)
	{
		ft_print_nf(&d);
		return (0);
	}
	else
	{
		ft_flags(argv, &d);
		d.flags = (d.options != 0) ? 1 : 0;
		ft_ls(d);
	}
	ft_freeing(d.p, &d);
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

