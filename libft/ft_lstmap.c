/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:38:38 by shasnaou          #+#    #+#             */
/*   Updated: 2013/12/01 18:58:09 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*list;
	t_list			*tmp;
	t_list			*tmp2;

	tmp = lst;
	list = NULL;
	if (!lst)
		return (NULL);
	while (tmp)
	{
		if (list == NULL)
		{
			list = (*f)(tmp);
			tmp2 = list;
		}
		else
		{
			tmp2->next = (*f)(tmp);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	free(lst);
	lst = NULL;
	return (list);
}
