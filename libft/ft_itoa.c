/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:00:29 by shasnaou          #+#    #+#             */
/*   Updated: 2017/03/21 12:19:38 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_len(int n)
{
	int			len;

	len = 0;
	if (!n)
		return (1);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*fill_str(char *s, int n, int len, int neg)
{
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (neg == 1)
		s[0] = '-';
	if (!n)
		s[0] = '0';
	s[len--] = '\0';
	while (n)
	{
		s[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	int			len;
	int			neg;
	char		*s;

	s = NULL;
	neg = 0;
	len = count_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		len++;
		n = -n;
		neg = 1;
	}
	return (fill_str(s, n, len, neg));
}
