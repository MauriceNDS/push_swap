/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:09:09 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/04 08:54:07 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *a)
{
	if (a->size)
		a->first = a->first->previous;
}

void	rrb(t_list *b)
{
	if (b->size)
		b->first = b->first->previous;
}

void	rrr(t_list *a, t_list *b)
{
	rra(a);
	rrb(b);
}
