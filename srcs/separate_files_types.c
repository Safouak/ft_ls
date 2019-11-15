/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_files_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:28:28 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/15 15:33:18 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list				*new_dir(t_list *dir)
{
	t_list			*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	new->content_size = sizeof(t_info);
	new->content = dir->content;
	return (new);
}

t_list				*get_list_dirs(t_list **info)
{
	t_list			*ldirs;
	t_list			*tmp;
	t_list			*ltmp;

	ldirs = NULL;
	ltmp = NULL;
	tmp = *info;
	while (tmp)
	{
		if (((t_info *)tmp->content)->d_type == DT_DIR && !ldirs)
			ldirs = new_dir(tmp);
		else if (((t_info *)tmp->content)->d_type == DT_DIR)
		{
			ltmp = ldirs;
			while (ltmp->next)
				ltmp = ltmp->next;
			ltmp->next = new_dir(tmp);
		}
		tmp = tmp->next;
	}
	return (ldirs);
}

void				open_fill_and_close(t_ptr *ptr, t_list *tmp, DIR *dir)
{
	if (!(dir = opendir(tmp->content)))
	{
		errno != ENOTDIR ? \
		print_errors(tmp->content) : \
		ft_lstaddelem(&ptr->lfiles, tmp->content, tmp->content_size);
		free(dir);
	}
	else
	{
		ft_lstaddelem(&ptr->ldirs, tmp->content, tmp->content_size);
		closedir(dir);
	}
}

int					separate_files_types(t_ptr *ptr, t_list **list)
{
	DIR				*dir;
	t_list			*tmp;
	char			sym[PATH_MAX];

	dir = NULL;
	ascii_sort_files(list);
	tmp = *list;
	while (tmp)
	{
		bzero(sym, PATH_MAX);
		if (readlink(tmp->content, sym, PATH_MAX) != -1)
		{
			if (sym[ft_strlen(sym) - 1] != '/')
			{
				ft_lstaddelem(&ptr->lfiles, tmp->content, tmp->content_size);
				tmp = tmp->next;
				continue ;
			}
		}
		open_fill_and_close(ptr, tmp, dir);
		tmp = tmp->next;
	}
	free_ptr(list);
	return (0);
}
