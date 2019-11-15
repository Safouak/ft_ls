/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:57:21 by shasnaou          #+#    #+#             */
/*   Updated: 2017/03/21 13:00:04 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_fmax(float *tab, int len)
{
	int		i;
	float	res;

	i = 0;
	if (len <= 0)
		return (-1);
	if (len == 1)
		return (tab[0]);
	res = tab[0];
	while (i < len)
	{
		if (res > tab[i])
			res = tab[i];
		i++;
	}
	return (res);
}
