/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:38:03 by adel-sol          #+#    #+#             */
/*   Updated: 2021/04/28 12:48:24 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *a)
{
	int		val;

	if (a->size <= 1)
		return ;
	val = a->first->next->value;
	a->first->next->value = a->first->value;
	a->first->value = val;
}

void	sb(t_list *b)
{
	int		val;

	if (b->size <= 1)
		return ;
	val = b->first->next->value;
	b->first->next->value = b->first->value;
	b->first->value = val;
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
}
