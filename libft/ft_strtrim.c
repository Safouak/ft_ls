/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:12:48 by shasnaou          #+#    #+#             */
/*   Updated: 2017/03/20 11:16:07 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			check_string(char const *s)
{
	size_t				i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

static int				alloc_and_fill(char const *s, size_t *j,
	size_t *i, char **dest)
{
	while (s[*j])
		(*j)++;
	--(*j);
	while (s[*j] == ' ' || s[*j] == '\n' || s[*j] == '\t')
		(*j)--;
	while (s[*i] == ' ' || s[*i] == '\n' || s[*i] == '\t')
		(*i)++;
	if (!(*dest = (char *)malloc((((*j) - (*i)) + 1) * sizeof(char))))
		return (0);
	return (1);
}

char					*ft_strtrim(char const *s)
{
	size_t				i;
	size_t				j;
	size_t				cl;
	char				*dest;

	i = 0;
	j = 0;
	cl = 0;
	if (!s)
		return (NULL);
	if (!check_string(s))
		return (ft_strdup(""));
	if (alloc_and_fill(s, &j, &i, &dest))
	{
		while (i <= j)
		{
			dest[cl] = s[i];
			i++;
			cl++;
		}
		dest[cl] = '\0';
		return (dest);
	}
	return (NULL);
}
