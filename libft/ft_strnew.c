/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:03:53 by shasnaou          #+#    #+#             */
/*   Updated: 2017/03/21 11:58:44 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strnew(size_t size)
{
	char				*s;

	if (!(s = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	s = ft_memset(s, '\0', size + 1);
	return (s);
}
