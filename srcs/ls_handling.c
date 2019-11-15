/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:50:32 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/15 15:12:03 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				display_lfiles(t_ptr *ptr)
{
	t_list		*tmp;
	t_list		*info;

	info = NULL;
	tmp = ptr->lfiles;
	while (tmp)
	{
		addinfo(&info, ptr, NULL, tmp->content);
		tmp = tmp->next;
	}
	sort(ptr, &info);
	ptr->dfiles = 1;
	print_info(ptr, &info);
	free_handler(ptr, &info);
	if (ft_lstlen(ptr->ldirs))
		ft_putchar('\n');
	free_ptr(&ptr->lfiles);
	return (0);
}

int				display_ldirs(t_ptr *ptr)
{
	ptr->type = FOLDER;
	ptr->flags[R] ? display_rec(ptr) : display_no_rec(ptr);
	free_ptr(&ptr->ldirs);
	return (0);
}

int				display_rec(t_ptr *ptr)
{
	t_list		*tmp;

	tmp = NULL;
	tmp = ptr->ldirs;
	while (tmp)
	{
		ascii_sort_ldirs(&tmp);
		dirs_handling(ptr, tmp->content, NULL);
		if (tmp->next)
			ft_putchar('\n');
		tmp = tmp->next;
	}
	return (0);
}

int				display_no_rec(t_ptr *ptr)
{
	t_list		*tmp;
	t_list		*info;

	info = NULL;
	tmp = NULL;
	tmp = ptr->ldirs;
	while (tmp)
	{
		if (ptr->one_arg != 1)
		{
			ascii_sort_ldirs(&tmp);
			ft_putstr(tmp->content);
			ft_putstr(":\n");
		}
		if (!(ptr->data.dir = opendir(tmp->content)))
			print_errors(tmp->content);
		while ((ptr->data.d = readdir(ptr->data.dir)))
			addinfo(&info, ptr, tmp->content, ptr->data.d->d_name);
		sort_print_and_free(ptr, info);
		if (tmp->next)
			ft_putchar('\n');
		tmp = tmp->next;
		closedir(ptr->data.dir);
	}
	return (0);
}

int				ls_handling(t_ptr *ptr)
{
	ascii_sort_files(&ptr->ldirs);
	ascii_sort_files(&ptr->lfiles);
	ptr->lfiles ? display_lfiles(ptr) : 0;
	ptr->ldirs ? display_ldirs(ptr) : 0;
	return (0);
}
