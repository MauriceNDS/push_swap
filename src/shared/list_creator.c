/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 09:40:02 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/12 15:46:24 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(t_consumer del)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->del = del;
	list->size = 0;
	list->first = NULL;
	return (list);
}

t_entry	*lst_new_entry(int value, int pos)
{
	t_entry	*entry;

	entry = malloc(sizeof(t_entry));
	if (!entry)
		return (NULL);
	entry->value = value;
	entry->pos = pos;
	entry->next = entry;
	entry->previous = entry;
	return (entry);
}

void	lst_clear(t_list *list)
{
	t_entry	*entry;

	if (lst_is_empty(list))
		return ;
	while (list->size)
	{
		entry = lst_shift_entry(list);
		free(entry);
	}
}

void	lst_destroy(t_list *list)
{
	lst_clear(list);
	free(list);
}
