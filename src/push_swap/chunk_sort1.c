/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:52:44 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/17 14:27:15 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	weak_sort(t_list *a)
{
	t_entry	*walker;
	t_entry	*runner;
	int		tmp;
	int		i;
	int		j;

	i = 0;
	walker = a->first;
	while (++i <= a->size)
	{
		j = i;
		runner = walker->next;
		while (++j <= a->size)
		{
			if (walker->value > runner->value)
			{
				tmp = walker->value;
				walker->value = runner->value;
				runner->value = tmp;
			}
			runner = runner->next;
		}
		walker = walker->next;
	}
}

void	init_pos(t_list *a)
{
	t_entry	*walker;
	int		i;

	i = 0;
	walker = a->first;
	while (++i <= a->size)
	{
		walker->pos = i;
		walker = walker->next;
	}
}

int	find_closest_push(t_list *a, int i, int size, int cks)
{
	int		sky;
	int		bot;

	sky = count_chunk_push(a, 1, (i + 1) * (size / cks) + (size % cks));
	bot = count_chunk_push(a, 0, (i + 1) * (size / cks) + (size % cks));
	if (sky * sky < bot * bot)
		return (sky);
	return (-bot);
}

void	push_by_chunks(t_list *a, t_list *b, int cks)
{
	int		size;
	int		i;
	int		act;

	size = a->size;
	i = 0;
	while (++i <= size)
	{
		act = find_closest_push(a, (i - (size % cks) - 1) / \
		(size / cks), size, cks);
		if (act < 0)
			while (act++ < 0)
				action1("ra", ra, a);
		else
			while (act-- > 0)
				action1("rra", rra, a);
		action2("pb", pb, a, b);
	}
}

void	chunk_sort(t_list *a, t_list *b, int cks)
{
	t_list	*cpy;

	cpy = list_copy(a);
	if (!cpy)
		return ;
	weak_sort(cpy);
	init_pos(cpy);
	a = list_copy_pos(a, cpy);
	lst_destroy(cpy);
	push_by_chunks(a, b, cks);
	push_back(a, b);
}
