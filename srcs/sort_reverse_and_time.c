/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_and_time.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:16:10 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/15 15:19:19 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			reverse_sort(t_ptr *ptr, t_list **list)
{
	t_list		*rlist;
	t_list		*tmp;
	t_list		*new;

	(void)ptr;
	tmp = *list;
	rlist = NULL;
	if (tmp)
	{
		new = ft_memalloc(sizeof(t_list));
		ft_memcpy(new, tmp, sizeof(t_list));
		new->next = NULL;
		ft_lstadd(&rlist, new);
		tmp = tmp->next;
	}
	while (tmp)
	{
		ft_lstadd(&rlist, ft_memcpy(\
					ft_memalloc(sizeof(t_list)), tmp, sizeof(t_list)));
		tmp = tmp->next;
	}
	free_list(list);
	*list = rlist;
}

void			time_sort(t_list **list)
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
			if (((t_info *)tmp->next->content)->m_time > p->m_time)
				ft_swap(&tmp->content, &tmp->next->content);
			else if (((t_info *)tmp->next->content)->m_time == p->m_time)
			{
				if (((t_info *)tmp->next->content)->m_timen > p->m_timen)
					ft_swap(&tmp->content, &tmp->next->content);
			}
			tmp = tmp->next;
		}
	}
}
