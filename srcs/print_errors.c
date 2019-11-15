/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:57:53 by shasnaou          #+#    #+#             */
/*   Updated: 2019/05/17 01:35:30 by sawken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_errors(char *d_name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(d_name, 2);
	ft_putstr_fd(": ", 2);
	perror(NULL);
	return (0);
}
