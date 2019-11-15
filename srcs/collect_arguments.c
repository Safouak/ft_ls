/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:10:14 by shasnaou          #+#    #+#             */
/*   Updated: 2019/06/15 15:04:02 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_if_flags(char *av)
{
	if (av && *av == '-' && *(av + 1))
		return (SUCCESS);
	return (FAILURE);
}

int			check_is_in(char opt)
{
	int		i;

	i = -1;
	while (FLAGS[++i])
		if (opt == FLAGS[i])
			return (1);
	return (0);
}

int			display_options(int *flags)
{
	if (flags[l])
		ft_putchar('l');
	if (flags[R])
		ft_putchar('R');
	if (flags[a])
		ft_putchar('a');
	if (flags[t])
		ft_putchar('t');
	ft_putchar('\n');
	return (0);
}

int			collect_flags(int *flags, char *av)
{
	int		i;

	i = 0;
	while (*(av + ++i))
	{
		if (check_is_in(*(av + i)))
		{
			flags[l] = (*(av + i) == 'l' ? 1 : flags[l]);
			flags[R] = (*(av + i) == 'R' ? 1 : flags[R]);
			flags[a] = (*(av + i) == 'a' ? 1 : flags[a]);
			flags[t] = (*(av + i) == 't' ? TIME : flags[t]);
			flags[r] = (*(av + i) == 'r' ? REVERSE : flags[r]);
		}
		else
			error_handling(ERR_ARGS, *(av + i));
	}
	return (0);
}

int			collect_arguments(t_ptr *info, char **av)
{
	int		i;

	i = -1;
	while (av[++i + 1])
	{
		if (!info->nm_opt && !ft_strcmp(av[i + 1], "--") && av[i + 2])
		{
			info->nm_opt = 1;
			continue ;
		}
		if (!info->nm_opt && !info->nm_flags && check_if_flags(av[i + 1]))
			collect_flags(info->flags, av[i + 1]);
		else
		{
			info->nm_flags = 1;
			ft_lstaddelem(&info->args, av[i + 1], ft_strlen(av[i + 1]) + 1);
		}
	}
	if (!info->args)
		ft_lstaddelem(&info->args, ".", 2);
	if (ft_lstlen(info->args) == 1)
		info->one_arg = 1;
	return (0);
}
