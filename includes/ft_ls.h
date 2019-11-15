/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:40:22 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/17 20:54:39 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <dirent.h>
# include <errno.h>
# include <limits.h>

# include <stdio.h>

# include "../libft/libft.h"

# define FLAGS				"lRatr"
# define NB_FLAGS			5
# define NB_WORDS			5

# define FAILURE			0
# define SUCCESS			1
# define FALSE				0
# define TRUE				1

# define OPTIONS			"lart"
# define RIGHTS				"-rwxrwxrwx"
# define RIGHTS_HIERARCHY	256
# define RIGHTS_LEN			9

# define FOLDER				2

# define TIME				2
# define SECOND				5

# define ASCII				1
# define REVERSE			4

typedef struct		s_info
{
	char			*d_name;
	char			*pw_name;
	char			*gr_name;
	char			*st_nlink;
	char			*st_size;
	char			**date;
	char			*rights;
	char			*symlink;
	blkcnt_t		st_blks;
	time_t			clock;
	time_t			m_time;
	time_t			m_timen;
	int				ret_syml;
	unsigned char	d_type;
}					t_info;

typedef struct		s_data
{
	DIR				*dir;
	struct dirent	*d;
	struct stat		stat;
	struct passwd	*pwd;
	struct group	*grp;
}					t_data;

typedef struct		s_ptr
{
	t_list			*args;
	t_list			*files;
	t_list			*lfiles;
	t_list			*ldirs;
	t_list			*lerrors;
	t_data			data;
	int				type;
	int				one_arg;
	int				dfiles;
	int				nm_flags;
	int				nm_opt;
	int				flags[NB_FLAGS];
	int				lwords[NB_WORDS];
}					t_ptr;

typedef struct		s_date
{
	char			*month;
	char			*day;
	char			*hour_or_year;
}					t_date;

typedef enum		e_err_values
{
	ERR_ARGS,
}					t_err_values;

typedef enum		e_flag_id
{
	l,
	R,
	a,
	t,
	r
}					t_flag_id;

/*
**					main.c
*/

int					main(int ac, char **av);

/*
**					ft_ls.c
*/

int					ft_ls(int ac, char **av);

/*
**					init_ptr.c
*/

void				init_ptr(t_ptr *ptr);

/*
**					collect_arguments.c
*/

int					check_if_flags(char *av);
int					check_is_in(char opt);
int					display_options(int *flags);
int					collect_flags(int *flags, char *av);
int					collect_arguments(t_ptr *info, char **av);

/*
**					separate_files_types.c
*/

t_list				*new_dir(t_list *dir);
t_list				*get_list_dirs(t_list **info);
void				open_fill_and_close(t_ptr *ptr, t_list *tmp, DIR *dir);
int					separate_files_types(t_ptr *ptr, t_list **list);

/*
**					ls_handling.c
*/

int					display_lfiles(t_ptr *ptr);
int					display_ldirs(t_ptr *ptr);
int					display_rec(t_ptr *ptr);
int					display_no_rec(t_ptr *ptr);
int					ls_handling(t_ptr *ptr);

/*
**					sorts.c
*/

void				free_list(t_list **list);
void				ascii_sort_ldirs(t_list **ldirs);
void				ascii_sort_files(t_list **list);
void				ascii_sort(t_list **list);
void				sort(t_ptr *ptr, t_list **list);

/*
**					addinfo.c
*/

char				*check_rights(off_t st_mode);
void				fetch_major_minor(char **str, struct stat *fstat);
void				fetch_data(t_ptr *ptr, t_info **new, struct stat *fstat);
t_list				*new_data(t_ptr *ptr, char *path, char *name);
int					addinfo(t_list **info, t_ptr *ptr, char *path, char *name);

/*
**					prints.c
*/

void				print_spaces_for_date(t_ptr *ptr, t_info *itmp, int i);
void				ls_layout(t_ptr *ptr, t_info *itmp, t_list **info);
void				print_info(t_ptr *ptr, t_list **info);

/*
**					free_handler.c
*/

void				free_ptr(t_list **list);
void				free_date(char **date);
void				free_if_flags(t_ptr *ptr, t_list **list);
void				free_handler(t_ptr *ptr, t_list **list);

/*
**					print_errors.c
*/

int					print_errors(char *d_name);

/*
**					sort_print_and_free.c
*/

void				sort_print_and_free(t_ptr *ptr, t_list *info);

/*
**					dirs_handling.c
*/

int					read_dir(t_ptr *ptr, t_list **i, char *name, char *d_name);
void				free_info_and_ldirs(t_ptr *ptr, t_list **ldirs, t_list **i);
void				sort_and_print(t_ptr *ptr, t_list **info, t_list **ldirs);
int					dirs_handling(t_ptr *ptr, char *name, char *d_name);

/*
**					compute_layout.c
*/

void				get_word_sizes(t_ptr *ptr, t_list *tmp, int l);
int					get_lgst_words(t_ptr *ptr, t_list **info);
void				print_spaces(t_ptr *ptr, char *s, int index);
void				blocks_sum(t_ptr *ptr, t_list *list);

/*
**					error_handling.c
*/

int					error_handling(int err_v, char err_n);

/*
**					ptr_swap.c
*/

void				ft_swap(void **a, void **b);

/*
**					sort_reverse_and_time.c
*/

void				reverse_sort(t_ptr *ptr, t_list **list);
void				time_sort(t_list **list);

/*
**					fill_node.c
*/

void				get_file_type(t_info *new, struct stat *fstat);
void				fill_new_node(t_info **new, char **path, char *name);
t_list				*set_content_to_node(t_list **p, t_info **new);

/*
**					clip_date.c
*/

void				set_date_in_tab(char **ret, t_date *date);
char				**clip_date(char *ctime, time_t mtimestamp);

#endif
