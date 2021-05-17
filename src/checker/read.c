/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:54:50 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/17 14:21:35 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	execute(t_list *a, t_list *b, char *cmd)
{
	if (ft_str_equals("sa", cmd))
		sa(a);
	else if (ft_str_equals("sb", cmd))
		sb(b);
	else if (ft_str_equals("ss", cmd))
		ss(a, b);
	else if (ft_str_equals("pa", cmd))
		pa(a, b);
	else if (ft_str_equals("pb", cmd))
		pb(a, b);
	else if (ft_str_equals("ra", cmd))
		ra(a);
	else if (ft_str_equals("rb", cmd))
		rb(b);
	else if (ft_str_equals("rr", cmd))
		rr(a, b);
	else if (ft_str_equals("rra", cmd))
		rra(a);
	else if (ft_str_equals("rrb", cmd))
		rrb(b);
	else if (ft_str_equals("rrr", cmd))
		rrr(a, b);
	else
		return (FALSE);
	return (TRUE);
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

int	reading_loop(t_list *a, t_list *b)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret > 0 && !execute(a, b, line))
		{
			free(line);
			write(2, "Error\n", 6);
			return (FALSE);
		}
		free(line);
	}
	if (sorting_check(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (TRUE);
}
