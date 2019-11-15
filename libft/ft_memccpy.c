/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:30:17 by shasnaou          #+#    #+#             */
/*   Updated: 2013/11/24 19:56:59 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*des1;
	const char		*src2;

	des1 = (char *)dest;
	src2 = (const char *)src;
	while (n--)
	{
		*des1 = *src2;
		if (*src2 == (char)c)
		{
			des1++;
			return (des1);
		}
		des1++;
		src2++;
	}
	return (0);
}
