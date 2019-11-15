/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:13:20 by sawken            #+#    #+#             */
/*   Updated: 2019/05/24 18:50:59 by sawken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_ptr(t_list **list)
{
	t_list	*tmp;
	t_list	*to_free;

	tmp = *list;
	to_free = NULL;
	while (tmp)
	{
		free(tmp->content);
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
}

void		free_date(char **date)
{
	int		i;

	i = -1;
	while (date[++i])
		free(date[i]);
	free(date);
}

void		free_if_flags(t_ptr *ptr, t_list **list)
{
	t_info	*itmp;
	t_list	*tmp;

	itmp = NULL;
	tmp = *list;
	if (ptr->flags[l])
	{
		while (tmp)
		{
			itmp = (t_info *)tmp->content;
			free(itmp->pw_name);
			free(itmp->gr_name);
			free(itmp->st_size);
			free(itmp->rights);
			free(itmp->st_nlink);
			free_date(itmp->date);
			tmp = tmp->next;
		}
	}
}

void		free_handler(t_ptr *ptr, t_list **list)
{
	t_list	*tmp;
	t_list	*cpy_ptr;
	void	*cpy_content;

	free_if_flags(ptr, list);
	tmp = *list;
	while (tmp)
	{
		free(((t_info *)tmp->content)->d_name);
		free(((t_info *)tmp->content)->symlink);
		cpy_content = tmp->content;
		cpy_ptr = tmp;
		free(cpy_content);
		tmp = tmp->next;
		cpy_ptr->next = NULL;
		free(cpy_ptr);
	}
}
