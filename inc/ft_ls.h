/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:34:12 by msicot            #+#    #+#             */
/*   Updated: 2018/02/19 12:23:58 by msicot           ###   ########.fr       */
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
	char	**p;
	int		nb_argc;
	int		col;
	DIR		*dp;
	char	*d_name;
	char	*str;
	int		nb_f;
	int		nb_w;
	int		nb_c;
	int		len_m;
	int		width;
	int		nb_l;
	char	**t;
	int		l;
	int		R;
	int		a;
	int		r;
	int		t2;
	int		minus;
	int		options;
}				t_dir;

typedef struct	s_filename
{
	char				*d_name;
	struct s_filename	*next; 
}				t_name;
void			ft_parsing(int argc, char **tab);
//void			ft_read_ls(t_dir *struc, struc dirent *dent);
void			ft_print_nf(void);
int			ft_width_ws(void);
t_name			*ft_create_node(void);
void			ft_del_list(t_name **head);
void			ft_print_line(t_name *head, t_dir *stru);
void			ft_flags(char **tab, t_dir *d);
void			ft_error_flag(char c);
#endif
