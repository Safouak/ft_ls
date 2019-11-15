/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:58:55 by shasnaou          #+#    #+#             */
/*   Updated: 2019/05/24 01:56:41 by sawken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_spaces_for_date(t_ptr *ptr, t_info *itmp, int i)
{
	while (itmp->date[++i])
	{
		if (i == 1)
			print_spaces(ptr, itmp->date[1], 4);
		if (i == 2)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(itmp->date[i], 1);
		ft_putchar_fd(' ', 1);
	}
}

void				ls_layout(t_ptr *ptr, t_info *itmp, t_list **info)
{
	int				i;

	i = -1;
	get_lgst_words(ptr, info);
	ft_putstr_fd(itmp->rights, 1);
	ft_putstr_fd(" ", 1);
	print_spaces(ptr, itmp->st_nlink, 0);
	ft_putstr_fd(itmp->st_nlink, 1);
	ft_putchar_fd(' ', 1);
	print_spaces(ptr, itmp->pw_name, 1);
	ft_putstr_fd(itmp->pw_name, 1);
	ft_putstr_fd(" ", 1);
	print_spaces(ptr, itmp->gr_name, 2);
	ft_putstr_fd(itmp->gr_name, 1);
	ft_putstr_fd(" ", 1);
	print_spaces(ptr, itmp->st_size, 3);
	ft_putstr_fd(itmp->st_size, 1);
	ft_putchar_fd(' ', 1);
	print_spaces_for_date(ptr, itmp, i);
}

void				print_info(t_ptr *ptr, t_list **info)
{
	t_list			*tmp;
	t_info			*itmp;

	tmp = *info;
	if (ptr->type == FOLDER)
		blocks_sum(ptr, tmp);
	while (tmp)
	{
		itmp = (t_info *)tmp->content;
		if (!ptr->flags[a] && *(itmp->d_name) == '.')
		{
			tmp = tmp->next;
			continue ;
		}
		if (ptr->flags[l])
			ls_layout(ptr, itmp, info);
		ft_putstr_fd(itmp->d_name, 1);
		if (ptr->flags[l] && itmp->ret_syml != -1)
		{
			ft_putstr_fd(" -> ", 1);
			ft_putstr_fd(itmp->symlink, 1);
		}
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}
