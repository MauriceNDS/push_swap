/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:59:43 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/14 11:22:25 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_entry	*find_min(t_list *a)
{
	int		i;
	int		min;
	t_entry	*walker;
	t_entry	*res;

	i = -1;
	min = INT_MAX;
	walker = a->first;
	while (++i < a->size)
	{
		if (walker->value < min)
		{
			min = walker->value;
			res = walker;
		}
		walker = walker->next;
	}
	return (res);
}

t_entry	*find_max(t_list *a)
{
	int		i;
	int		max;
	t_entry	*walker;
	t_entry	*res;

	i = -1;
	max = INT_MIN;
	walker = a->first;
	while (++i < a->size)
	{
		if (walker->value > max)
		{
			max = walker->value;
			res = walker;
		}
		walker = walker->next;
	}
	return (res);
}

int	closest_ascending(t_list *a, t_entry *elem)
{
	int		up;
	int		down;
	t_entry	*cpy;

	up = 0;
	down = 0;
	if (a->size <= 1)
		return (0);
	cpy = elem;
	while (a->first->value != cpy->value)
	{
		up--;
		cpy = cpy->previous;
	}
	while (a->first->value != elem->value)
	{
		down++;
		elem = elem->next;
	}
	if (-up < down)
		return (up);
	return (down);
}

int	sorting_check(t_list *a, t_list *b)
{
	int		i;
	t_entry	*walk;

	if (b->size)
		return (FALSE);
	i = -1;
	walk = a->first;
	while (++i < a->size - 1)
	{
		if (walk->value > walk->next->value)
			return (FALSE);
		walk = walk->next;
	}
	return (TRUE);
}
