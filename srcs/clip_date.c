/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_date.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:15:40 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/17 20:44:38 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				set_date_in_tab(char **ret, t_date *date)
{
	ret[0] = date->month;
	ret[1] = date->day;
	ret[2] = date->hour_or_year;
	ret[3] = NULL;
}

char				**clip_date(char *ctime, time_t mtimestamp)
{
	t_date			date;
	char			**tab;
	char			**ret;
	time_t			rawtime;

	if (!(ret = malloc(sizeof(char *) * 4)))
		_exit(EXIT_FAILURE);
	tab = ft_strsplit(ctime, ' ');
	date.month = NULL;
	date.day = NULL;
	date.hour_or_year = NULL;
	date.month = ft_strdup(tab[1]);
	date.day = ft_strdup(tab[2]);
	date.hour_or_year = ft_strdup(tab[3]);
	date.hour_or_year[5] = '\0';
	if (time(&rawtime) - mtimestamp > 15552000)
	{
		free(date.hour_or_year);
		date.hour_or_year = ft_strdup(tab[4]);
		date.hour_or_year[4] = '\0';
	}
	set_date_in_tab(ret, &date);
	free_date(tab);
	return (ret);
}
