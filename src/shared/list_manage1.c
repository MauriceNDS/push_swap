/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manage1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 09:40:33 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/12 15:58:49 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_entry	*lst_shift_entry(t_list *list)
{
	t_entry	*first;

	if (lst_is_empty(list))
		return (NULL);
	first = list->first;
	list->first = first->next;
	first->previous->next = list->first;
	list->first->previous = first->previous;
	--(list->size);
	return (first);
}

int	lst_shift(t_list *list, int *pos)
{
	t_entry	*first;
	int		value;

	if (lst_is_empty(list))
		return (0);
	first = lst_shift_entry(list);
	if (list->size == 0)
		list->first = NULL;
	value = first->value;
	*pos = first->pos;
	free(first);
	return (value);
}

int	lst_unshift(t_list *list, int element, int pos)
{
	t_entry	*entry;

	entry = lst_new_entry(element, pos);
	if (!entry)
		return (0);
	if (list->first)
	{
		entry->next = list->first;
		entry->previous = list->first->previous;
		list->first->previous->next = entry;
		list->first->previous = entry;
	}
	else
	{
		entry->next = entry;
		entry->previous = entry;
	}
	list->first = entry;
	++(list->size);
	return (element);
}

int	lst_is_empty(t_list *list)
{
	if (!list)
		return (1);
	return (!(list->first));
}

int	lst_not_empty(t_list *list)
{
	if (!list)
		return (1);
	return (!!(list->first));
}
