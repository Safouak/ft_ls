/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:48:59 by shasnaou          #+#    #+#             */
/*   Updated: 2019/05/20 03:15:04 by sawken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			init_ptr(t_ptr *ptr)
{
	int			i;

	i = -1;
	while (++i < NB_FLAGS)
		ptr->flags[i] = 0;
	ptr->nm_flags = 0;
	ptr->nm_opt = 0;
	ptr->type = 0;
	ptr->one_arg = 0;
	ptr->dfiles = 0;
	ptr->args = NULL;
	ptr->files = NULL;
	ptr->lfiles = NULL;
	ptr->ldirs = NULL;
	ptr->lerrors = NULL;
}
