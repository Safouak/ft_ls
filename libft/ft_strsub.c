/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:40:59 by shasnaou          #+#    #+#             */
/*   Updated: 2017/03/20 11:44:36 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*dest;

	if (!s || len > ft_strlen(s))
		return (NULL);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	ft_strncpy(dest, s + start, len);
	return (dest);
}
