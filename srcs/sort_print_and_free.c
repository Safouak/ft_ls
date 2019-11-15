/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_print_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:13:31 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/15 15:14:17 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_print_and_free(t_ptr *ptr, t_list *info)
{
	ascii_sort(&info);
	sort(ptr, &info);
	print_info(ptr, &info);
	free_handler(ptr, &info);
	info = NULL;
}
