/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:45:24 by shasnaou          #+#    #+#             */
/*   Updated: 2013/11/26 17:45:28 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*cp_s;

	i = 0;
	cp_s = (unsigned char *)s;
	while (i < n)
	{
		if (*cp_s == (unsigned char)c)
			return ((void *)cp_s);
		i++;
		cp_s++;
	}
	return (NULL);
}
