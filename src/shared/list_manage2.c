/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manage2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:31:18 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/12 15:42:22 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_entry	*lst_push(t_list *list, int value)
{
	t_entry	*entry;

	entry = lst_new_entry(value, 0);
	if (!entry)
		return (NULL);
	if (list->first)
	{
		list->first->previous->next = entry;
		entry->previous = list->first->previous;
		entry->next = list->first;
		list->first->previous = entry;
	}
	else
	{
		entry->next = entry;
		entry->previous = entry;
		list->first = entry;
	}
	++(list->size);
	return (entry);
}

int	list_element_exists(t_list *list, int element)
{
	int		i;
	t_entry	*walker;

	i = -1;
	walker = list->first;
	while (++i < list->size)
	{
		if (walker->value == element)
			return (TRUE);
		walker = walker->next;
	}
	return (FALSE);
}

t_list	*list_copy(t_list *lst)
{
	t_entry	*entry;
	t_list	*copy;
	int		i;

	copy = lst_new(lst->del);
	if (!copy)
		return (NULL);
	if (lst_is_empty(lst))
		return (copy);
	entry = lst->first;
	i = -1;
	while (++i < lst->size)
	{
		lst_push(copy, entry->value);
		entry = entry->next;
	}
	return (copy);
}

t_list	*list_copy_pos(t_list *dest, t_list *src)
{
	t_entry	*dwalk;
	t_entry	*swalk;
	int		i;
	int		j;

	if (dest->size != src->size)
		return (NULL);
	i = -1;
	swalk = src->first;
	while (++i < src->size)
	{
		j = -1;
		dwalk = dest->first;
		while (++j < dest->size)
		{
			if (dwalk->value == swalk->value)
			{
				dwalk->pos = swalk->pos;
				break ;
			}
			dwalk = dwalk->next;
		}
		swalk = swalk->next;
	}
	return (dest);
}
