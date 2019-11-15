/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:30:22 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/15 15:20:07 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_list(t_list **list)
{
	t_list		*tmp;
	t_list		*cpy;

	tmp = *list;
	while (tmp)
	{
		cpy = tmp;
		tmp = tmp->next;
		free(cpy);
	}
}

void			ascii_sort_ldirs(t_list **ldirs)
{
	int			i;
	int			len;
	t_list		*tmp;

	i = -1;
	len = ft_lstlen(*ldirs);
	while (++i < len)
	{
		tmp = *ldirs;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->content, tmp->next->content) > 0)
				ft_swap(&tmp->content, &tmp->next->content);
			tmp = tmp->next;
		}
	}
}

void			ascii_sort_files(t_list **list)
{
	int			i;
	int			len;
	t_list		*tmp;
	size_t		csize;

	i = -1;
	len = ft_lstlen(*list);
	while (++i < len)
	{
		tmp = *list;
		while (tmp->next)
		{
			if (ft_strcmp((char *)tmp->next->content, (char *)tmp->content) < 0)
			{
				ft_swap(&tmp->content, &tmp->next->content);
				csize = tmp->content_size;
				tmp->content_size = tmp->next->content_size;
				tmp->next->content_size = csize;
			}
			tmp = tmp->next;
		}
	}
}

void			ascii_sort(t_list **list)
{
	int			i;
	int			len;
	t_list		*tmp;
	t_info		*p;

	i = -1;
	len = ft_lstlen(*list);
	while (++i < len)
	{
		tmp = *list;
		while (tmp->next)
		{
			p = (t_info *)tmp->content;
			if (ft_strcmp(((t_info *)tmp->next->content)->d_name, p->d_name) < \
					0)
				ft_swap(&tmp->content, &tmp->next->content);
			tmp = tmp->next;
		}
	}
}

void			sort(t_ptr *ptr, t_list **list)
{
	int			type;

	type = TIME | REVERSE;
	if (type & ptr->flags[t])
		time_sort(list);
	if (type & ptr->flags[r])
		reverse_sort(ptr, list);
}
