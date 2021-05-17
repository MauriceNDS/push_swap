/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:40:01 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/14 11:49:17 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list *a, t_list *b)
{
	(void)b;
	if (a->first->value > a->first->next->value)
		printf("sa\n");
}

void	sort_3(t_list *a, t_list *b)
{
	t_entry	*first;
	t_entry	*second;
	t_entry	*third;

	(void)b;
	first = a->first;
	second = a->first->next;
	third = second->next;
	if (first->value > second->value && first->value < third->value)
		ft_putendl("sa");
	else if (first->value > second->value && second->value > third->value)
		ft_putendl("sa\nrra");
	else if (third->value > second->value && third->value < first->value)
		ft_putendl("ra");
	else if (third->value < second->value && third->value > first->value)
		ft_putendl("sa\nra");
	else if (first->value < second->value && first->value > third->value)
		ft_putendl("rra");
}

void	push_min_max_b(t_list *a, t_list *b)
{
	int		i_max;
	int		i_min;

	i_min = closest_ascending(a, find_min(a));
	if (i_min < 0)
		while (i_min++ < 0)
			action1("ra", ra, a);
	else
		while (i_min-- > 0)
			action1("rra", rra, a);
	action2("pb", pb, a, b);
	i_max = closest_ascending(a, find_max(a));
	if (i_max < 0)
		while (i_max++ < 0)
			action1("ra", ra, a);
	else
		while (i_max-- > 0)
			action1("rra", rra, a);
	action2("pb", pb, a, b);
}

void	sort_5(t_list *a, t_list *b)
{
	push_min_max_b(a, b);
	sort_3(a, b);
	ft_putendl("pa");
	ft_putendl("ra");
	ft_putendl("pa");
}
