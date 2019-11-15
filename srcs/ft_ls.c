/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:48:37 by shasnaou          #+#    #+#             */
/*   Updated: 2019/05/25 01:52:27 by sawken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_ls(int ac, char **av)
{
	t_ptr	ptr;

	(void)ac;
	init_ptr(&ptr);
	collect_arguments(&ptr, av);
	separate_files_types(&ptr, &ptr.args);
	ls_handling(&ptr);
	return (0);
}
