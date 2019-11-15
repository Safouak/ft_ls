/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_layout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:04:50 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/17 20:23:30 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				get_word_sizes(t_ptr *ptr, t_list *tmp, int l)
{
	t_info			*itmp;

	if (tmp)
	{
		while (tmp->next)
		{
			itmp = (t_info *)tmp->next->content;
			if ((l = ft_strlen(((t_info *)(tmp->next->content))->st_nlink)) > \
					ptr->lwords[0])
				ptr->lwords[0] = l;
			if ((l = ft_strlen(((t_info *)(tmp->next->content))->pw_name)) > \
					ptr->lwords[1])
				ptr->lwords[1] = l;
			if ((l = ft_strlen(((t_info *)(tmp->next->content))->gr_name)) > \
					ptr->lwords[2])
				ptr->lwords[2] = l;
			if ((l = ft_strlen(((t_info *)(tmp->next->content))->st_size)) > \
					ptr->lwords[3])
				ptr->lwords[3] = l;
			if ((l = ft_strlen(itmp->date[1])) > ptr->lwords[4])
				ptr->lwords[4] = l;
			tmp = tmp->next;
		}
	}
}

int					get_lgst_words(t_ptr *ptr, t_list **info)
{
	t_list			*tmp;
	t_info			*itmp;
	int				l;

	l = 0;
	tmp = *info;
	itmp = NULL;
	itmp = (t_info *)(tmp->content);
	ptr->lwords[0] = ft_strlen(itmp->st_nlink);
	ptr->lwords[1] = ft_strlen(itmp->pw_name);
	ptr->lwords[2] = ft_strlen(itmp->gr_name);
	ptr->lwords[3] = ft_strlen(itmp->st_size);
	ptr->lwords[4] = ft_strlen(itmp->date[1]);
	get_word_sizes(ptr, tmp, l);
	return (0);
}

void				print_spaces(t_ptr *ptr, char *s, int index)
{
	int				i;
	int				nb_spaces;

	i = -1;
	nb_spaces = ptr->lwords[index] - ft_strlen(s);
	while (++i < nb_spaces)
		ft_putchar_fd(' ', 1);
}

void				blocks_sum(t_ptr *ptr, t_list *list)
{
	long int		sum;
	t_info			*itmp;
	t_list			*tmp;

	sum = 0;
	tmp = list;
	while (list)
	{
		itmp = (t_info *)list->content;
		list = list->next;
		if (!ptr->flags[a] && *(itmp->d_name) == '.')
			continue ;
		sum += itmp->st_blks;
	}
	if (tmp && ptr->flags[l])
	{
		ft_putstr("total ");
		ft_putnbr((int)sum);
		ft_putchar('\n');
	}
	return ;
}
