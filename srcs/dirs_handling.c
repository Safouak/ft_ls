/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:44:02 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/15 15:07:01 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					read_dir(t_ptr *ptr, t_list **i, char *name, char *d_name)
{
	*i = NULL;
	ptr->data.dir = opendir(name);
	if (!ptr->one_arg)
	{
		ft_putstr(name);
		ft_putstr(":\n");
	}
	ptr->one_arg = 0;
	if (!(ptr->data.dir))
	{
		print_errors(d_name);
		return (-1);
	}
	while ((ptr->data.d = readdir(ptr->data.dir)))
	{
		if (!ptr->flags[a] && *(ptr->data.d->d_name) == '.')
			continue ;
		addinfo(i, ptr, name, ptr->data.d->d_name);
	}
	closedir(ptr->data.dir);
	return (0);
}

void				free_info_and_ldirs(t_ptr *ptr, t_list **ldirs, t_list **i)
{
	t_list *cp_ldirs;

	if (*i)
		free_handler(ptr, &(*i));
	while (*ldirs)
	{
		cp_ldirs = *ldirs;
		*ldirs = (*ldirs)->next;
		free(cp_ldirs);
	}
}

void				sort_and_print(t_ptr *ptr, t_list **info, t_list **ldirs)
{
	ascii_sort(info);
	ascii_sort(ldirs);
	sort(ptr, &(*info));
	sort(ptr, &(*ldirs));
	print_info(ptr, &(*info));
}

int					dirs_handling(t_ptr *ptr, char *name, char *d_name)
{
	char			*path;
	t_list			*info;
	t_list			*ldirs;
	t_info			*dir;
	t_list			*dtmp;

	path = NULL;
	read_dir(ptr, &info, name, d_name);
	ldirs = get_list_dirs(&info);
	sort_and_print(ptr, &info, &ldirs);
	dtmp = ldirs;
	while (dtmp)
	{
		dir = (t_info *)dtmp->content;
		if (ft_strcmp(dir->d_name, "..") && ft_strcmp(dir->d_name, "."))
		{
			path = ft_strjoinc(name, '/', dir->d_name);
			ft_putchar_fd('\n', 1);
			dirs_handling(ptr, path, dir->d_name);
			free(path);
		}
		dtmp = dtmp->next;
	}
	free_info_and_ldirs(ptr, &ldirs, &info);
	return (0);
}
