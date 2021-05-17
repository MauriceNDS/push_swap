/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:53:04 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/14 11:48:11 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_chunk_push(t_list *a, int mod, int cond)
{
	t_entry	*climber;
	int		res;
	int		k;

	k = 0;
	res = 0;
	climber = a->first;
	while (++k <= a->size)
	{
		if (climber->pos <= cond)
		{
			res = -(k - 1);
			return (res);
		}
		if (mod)
			climber = climber->next;
		else
			climber = climber->previous;
	}
	return (res);
}

void	push_back(t_list *a, t_list *b)
{
	int		act;

	while (b->size)
	{
		act = closest_ascending(b, find_max(b));
		if (act < 0)
			while (act++ < 0)
				action1("rb", rb, b);
		else
			while (act-- > 0)
				action1("rrb", rrb, b);
		action2("pa", pa, a, b);
	}
}
