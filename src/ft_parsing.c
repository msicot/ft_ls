/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:29:51 by msicot            #+#    #+#             */
/*   Updated: 2018/02/19 15:57:43 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_freeing(char **tab, t_dir *d)
{
	int i;
	int lim;

	i = 0;
/*	while (tab[i][j] != '\0')
	{
		++i;
		printf("i =%d\n",i);
	}*/
	if (d->options == d->nb_argc -1)
		lim = 2;
	else
		lim = (d->nb_argc - d->options);
	while (i < lim)
		ft_strdel(&tab[i++]);
	free(tab);
}

/*void	ft_parsing()
{

	d.nb_argc = argc;
	if (argc == 1)
		ft_print_nf(&d);
	else
	{
	//	ft_printf("--->>%s<<---\n", d.p[0]);
		ft_freeing(d.p, &d);
	}
	//penser a free le **t de la structure une fois les noms des fichiers recup
}*/
