/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:11:12 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/17 20:52:49 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_file_type(t_info *new, struct stat *fstat)
{
	new->d_type = 0;
	if (S_ISDIR(fstat->st_mode))
		new->d_type = 4;
}

void		fill_new_node(t_info **new, char **path, char *name)
{
	char	*path_name;

	path_name = NULL;
	(*new)->d_name = ft_strdup(name);
	if (!((*new)->symlink = malloc(sizeof(char) * PATH_MAX)))
		(*new)->symlink = NULL;
	bzero((*new)->symlink, PATH_MAX);
	if (*path)
	{
		path_name = ft_strjoinc(*path, '/', name);
		(*new)->ret_syml = readlink(path_name, (*new)->symlink, PATH_MAX);
		free(path_name);
	}
	else
		(*new)->ret_syml = readlink(name, (*new)->symlink, PATH_MAX);
}

t_list		*set_content_to_node(t_list **p, t_info **new)
{
	(*p)->content = *new;
	(*p)->content_size = sizeof(t_info);
	(*p)->next = NULL;
	return (*p);
}
