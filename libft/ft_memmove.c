/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:14:47 by shasnaou          #+#    #+#             */
/*   Updated: 2013/12/01 17:38:36 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t				i;
	char				*cp_s1;
	char				*cp_s2;

	i = 0;
	if (s1 > s2)
	{
		cp_s1 = (char *)s1 + n - 1;
		cp_s2 = (char *)s2 + n - 1;
		while (i < n)
		{
			*cp_s1 = *cp_s2;
			cp_s2--;
			cp_s1--;
			i++;
		}
		return (s1);
	}
	return (ft_memcpy(s1, s2, n));
}
