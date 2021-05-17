/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:58:13 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/17 14:26:34 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *a, t_list *b)
{
	int	pos;
	int	elem;

	if (b->size == 0)
		return ;
	elem = lst_shift(b, &pos);
	lst_unshift(a, elem, pos);
}

void	pb(t_list *a, t_list *b)
{
	int	pos;
	int	elem;

	if (a->size == 0)
		return ;
	elem = lst_shift(a, &pos);
	lst_unshift(b, elem, pos);
}

void	action1(char *str, void (f)(t_list *), t_list *a)
{
	ft_putendl(str);
	f(a);
}

void	action2(char *str, void (f)(t_list *, t_list *), t_list *a, t_list *b)
{
	ft_putendl(str);
	f(a, b);
}
