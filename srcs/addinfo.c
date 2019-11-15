/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:17:37 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/17 20:53:20 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*check_rights(off_t st_mode)
{
	char			*rights;

	rights = ft_strdup(RIGHTS);
	S_ISBLK(st_mode) ? *rights = 'b' : 0;
	S_ISCHR(st_mode) ? *rights = 'c' : 0;
	S_ISDIR(st_mode) ? *rights = 'd' : 0;
	S_ISFIFO(st_mode) ? *rights = 'f' : 0;
	S_ISLNK(st_mode) ? *rights = 'l' : 0;
	S_ISSOCK(st_mode) ? *rights = 's' : 0;
	rights[1] = (st_mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (st_mode & S_IWUSR) ? 'w' : '-';
	rights[3] = (st_mode & S_IXUSR) ? 'x' : '-';
	rights[4] = (st_mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (st_mode & S_IWGRP) ? 'w' : '-';
	rights[6] = (st_mode & S_IXGRP) ? 'x' : '-';
	rights[7] = (st_mode & S_IROTH) ? 'r' : '-';
	rights[8] = (st_mode & S_IWOTH) ? 'w' : '-';
	rights[9] = (st_mode & S_IXOTH) ? 'x' : '-';
	if (st_mode & S_ISUID)
		rights[3] = (rights[3] == '-') ? 'S' : 's';
	if (st_mode & S_ISGID)
		rights[6] = (rights[6] == '-') ? 'S' : 's';
	if (st_mode & S_ISVTX)
		rights[9] = (rights[9] == '-') ? 'T' : 't';
	return (rights);
}

void				fetch_major_minor(char **str, struct stat *fstat)
{
	char			*major;
	char			*minor;

	major = ft_itoa(major(fstat->st_rdev));
	minor = ft_itoa(minor(fstat->st_rdev));
	(*str) = ft_strnew(ft_strlen(major) + ft_strlen(minor) + 3);
	ft_strcpy(*str, major);
	ft_strcat(*str, ", ");
	ft_strcat(*str, minor);
	major ? free(major) : 0;
	minor ? free(minor) : 0;
}

void				fetch_data(t_ptr *ptr, t_info **new, struct stat *fstat)
{
	(*new)->rights = check_rights((*fstat).st_mode);
	if (!(ptr->data.pwd = getpwuid((*fstat).st_uid)))
		(*new)->pw_name = ft_itoa((*fstat).st_uid);
	else
		(*new)->pw_name = ft_strdup(ptr->data.pwd->pw_name);
	if (!(ptr->data.grp = getgrgid((*fstat).st_gid)))
		(*new)->gr_name = ft_itoa((*fstat).st_gid);
	else
		(*new)->gr_name = ft_strdup(ptr->data.grp->gr_name);
	(*new)->st_nlink = ft_itoa((*fstat).st_nlink);
	if (*((*new)->rights) == 'b' || *((*new)->rights) == 'c')
		fetch_major_minor(&((*new)->st_size), fstat);
	else
		(*new)->st_size = ft_itoa((*fstat).st_size);
	(*new)->st_blks = (*fstat).st_blocks;
	(*new)->date = clip_date(ctime(&((*fstat).st_mtime)), (*fstat).st_mtime);
	(*new)->m_time = fstat->st_mtimespec.tv_sec;
	(*new)->m_timen = fstat->st_mtimespec.tv_nsec;
}

t_list				*new_data(t_ptr *ptr, char *path, char *name)
{
	t_list			*p;
	t_info			*new;
	struct stat		fstat;
	char			*way;

	p = NULL;
	new = NULL;
	way = NULL;
	if (!(p = malloc(sizeof(t_list))))
		return (NULL);
	if (!(new = malloc(sizeof(t_info))))
		return (NULL);
	if (!path)
		way = name;
	else
		way = ft_strjoinc(path, '/', name);
	if (lstat(way, &fstat) == -1)
		exit(-1);
	if (path)
		free(way);
	get_file_type(new, &fstat);
	if (ptr->flags[l])
		fetch_data(ptr, &new, &fstat);
	fill_new_node(&new, &path, name);
	return (set_content_to_node(&p, &new));
}

int					addinfo(t_list **info, t_ptr *ptr, char *path, char *name)
{
	t_list			*tmp;

	tmp = *info;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_data(ptr, path, name);
	}
	else
		*info = new_data(ptr, path, name);
	return (1);
}
