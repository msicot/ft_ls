/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:34:12 by msicot            #+#    #+#             */
/*   Updated: 2018/02/16 19:33:03 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H
# include "../libft/inc/libft.h"
# include "../libft/inc/libftprintf.h"
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/dirent.h>
# include <dirent.h>
# include <sys/ioctl.h> /* ioctl TIOCGWINSZ */
# include <stdlib.h>

typedef struct	s_dir
{
	char	*path;
	int		col;
	DIR		*dp;
	char	**arg;
	char	d_namec;
	int		nb_f;
}				t_dir;

typedef struct	s_filename
{
	char				*d_name;
	struct s_filename	*next; 
}				t_name;
void			ft_parsing(int argc, char **tab);
//void			ft_read_ls(t_dir *struc, struc dirent *dent);
void			ft_print_nf(void);
int				ft_width_ws(void);
#endif
