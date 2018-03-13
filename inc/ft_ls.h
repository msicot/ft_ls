/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:34:12 by msicot            #+#    #+#             */
/*   Updated: 2018/03/13 18:01:16 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H
# include "../libft/inc/libft.h"
# include "../libft/inc/libftprintf.h"
# include <errno.h>
# include <sys/acl.h>
# include <grp.h>
#include <pwd.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/dirent.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h> /* ioctl TIOCGWINSZ */
# include <sys/xattr.h>
# include <stdlib.h>
# include <time.h>
# include <uuid/uuid.h>
typedef struct	s_lstat
{
	char	*type;
	char	*perm;
	char	*all_p;
	char	*acl;
	int		nb_l;
	char	*user;
	char	*group;
	int		maj;
	int		maj_min;
	int		size;
	char	*date;
	char	*name;

}				t_lstat;

struct	s_padding
{
	int		u_pad;
	int		gr_pad;
	int		sz_pad;
	int		ln_pad;
	int		nb_block;
	int		maj_pad;
};

typedef struct	s_filename
{
	char				*d_name;
	char				*path;
	time_t				ts;
	t_lstat				info;
	struct s_filename	*next; 
}				t_name;

typedef struct	s_dir
{
	t_name	*path;
	t_name	*head;
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
	int		l;
	int		R;
	int		a;
	int		r;
	int		t;
	int		un;
	int		flags;
	int		minus;
	int		options;
	int		nb_path;
}				t_dir;

//void			ft_parsing(int argc, char **tab);
//void			ft_read_ls(t_dir *struc, struc dirent *dent);
//void			ft_print_nf(t_dir *d);
int				ft_width_ws(void);
t_name			*ft_create_node(char *str);
void			ft_del_list(t_name **head);
void			ft_del_listp(t_name **head);
void			ft_del_info(t_lstat *info);
void			ft_flags(char **tab, t_dir *d);
void			ft_error_flag(char c);
void			ft_err_path(char *s);
void			ft_err_perm(char *str);
t_name			*create_list(DIR *dir);
t_name			*create_list_path(DIR *dir, char *path, t_dir *d);
void			order_list(t_name **head);
void			order_list_p(t_name **head);
void			ft_merge_sort(t_name **head_ref, t_dir *d);
void			ft_merge_sort_t(t_name **head_ref, t_dir *d);
void			ft_merge_sort_r(t_name **head_ref, t_dir *d);
int				ft_count_lst(t_name *head);
void			print_list_basic(t_name *head, t_dir *d);
void			ft_print_opt(t_name **head, t_dir *d);//, t_dir *d);
void			ft_print_l(struct s_padding pad, t_name **head, t_dir *d,
		int i);
void			ft_print_file(t_dir *d, t_name **tmp2);
void			ft_freeing(char **tab, t_dir *d);
void			ft_ls_0(t_dir *d);
void			ft_ls_else(t_dir *d);
void			ft_ls_gr(t_dir *d);
int				ft_retrieve_l(char *path, t_lstat *info, struct s_padding *pad);
void			ft_size_padd(struct s_padding *s, t_lstat l, t_dir *d, char *str);
void			ft_path_check(t_dir *d, t_name **head);
void			ft_path_order(t_dir *d);
t_name			*get_names(char *path, t_dir *d);
t_name			*get_names2(char *path, t_dir *d, char *str);
void			ft_linked(t_name **node);
t_name			*rm_node(t_name *currptr, char *value);
void			del_tab(char ***tab);
void			ft_option_l(t_name **head, t_dir *d);
char			*filetype(struct stat *sb);
char			*acl_type(const char *path, char *str);
char			*perm(struct stat *sb);
char			*u_name(struct stat *sb);
char			*gr_name(struct stat *sb);
void			get_majmin(struct stat *sb, t_lstat **info);
char			*time_info(struct stat *sb);
time_t			time_stamp(char *path);
void			ft_padd_0(struct s_padding *info);
int				ft_total(t_name *tmp);
void			print_it(struct s_padding pad, t_name *node);
int				ft_pis_reg(t_dir *d, t_name **node);
int				ft_pis_lnk(t_dir *d, t_name **node, struct stat *sb);
#endif
