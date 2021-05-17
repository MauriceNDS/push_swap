/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:03:12 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/04 08:54:24 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *a)
{
	if (a->size)
		a->first = a->first->next;
}

void	rb(t_list *b)
{
	if (b->size)
		b->first = b->first->next;
}

void	rr(t_list *a, t_list *b)
{
	ra(a);
	rb(b);
}
