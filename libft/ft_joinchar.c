/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:24:31 by shasnaou          #+#    #+#             */
/*   Updated: 2017/03/21 12:57:43 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		*ft_joinchar(unsigned char *s1, unsigned char c)
{
	int				i;
	unsigned char	*dup;

	if (!s1)
	{
		if (!(dup = malloc(sizeof(unsigned char) * 2)))
			return (NULL);
		dup[0] = c;
		dup[1] = '\0';
		return (dup);
	}
	if (!(dup = malloc(sizeof(unsigned char) * (ft_strlen((char *)s1) + 2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i++] = c;
	dup[i] = '\0';
	return (dup);
}
