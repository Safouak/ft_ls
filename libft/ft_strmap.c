/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:48:29 by shasnaou          #+#    #+#             */
/*   Updated: 2013/12/01 20:32:19 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strmap(char const *s, char (*f)(char))
{
	char				*ns;
	size_t				i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(ns = (char *)malloc(ft_strlen(s) + 1 * sizeof(char))))
		return (NULL);
	while (s[i])
	{
		ns[i] = f(s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
