/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:06:10 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/17 21:06:32 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char			*cp_s1;
	char			*cp_s2;
	size_t			i;

	i = -1;
	cp_s1 = (char *)s1;
	cp_s2 = (char *)s2;
	while (++i < n)
		cp_s1[i] = cp_s2[i];
	return (s1);
}
