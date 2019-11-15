/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:56:53 by shasnaou          #+#    #+#             */
/*   Updated: 2017/03/21 12:56:55 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int *tab, int len)
{
	int	i;
	int	res;

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
