/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:29:59 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/17 21:08:31 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_nb(char const *s, char c)
{
	size_t		word_nb;

	word_nb = ((*s == c) ? (0) : (1));
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			word_nb++;
		s++;
	}
	return (word_nb);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t		word_len;

	word_len = 0;
	while (*s != c && *s)
	{
		s++;
		word_len++;
	}
	return (word_len);
}

static void		ft_free_tab(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		i;

	if (!s)
		return (NULL);
	if (!(tab = malloc((ft_word_nb(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(tab[i] = ft_strsub(s, 0, ft_word_len(s, c))))
			{
				ft_free_tab(tab, i);
				return (NULL);
			}
			s += ft_word_len(s, c);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
