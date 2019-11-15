/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:48:10 by shasnaou          #+#    #+#             */
/*   Updated: 2019/05/19 02:51:04 by sawken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_handling(int err_v, char err_n)
{
	(void)err_v;
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(err_n, 2);
	ft_putendl_fd("\nusage: ft_ls [-lRatr] [file ...]", 2);
	exit(2);
	return (0);
}
