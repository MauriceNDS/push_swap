/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:51:12 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/17 10:01:00 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_insert(t_list *a, char *arg)
{
	int		element;
	char	*tmp;

	element = ft_atoi(arg);
	tmp = ft_itoa(element);
	if (!ft_str_equals(arg, tmp) || list_element_exists(a, element))
	{
		free(tmp);
		write(2, "Error\n", 6);
		return (FALSE);
	}
	free(tmp);
	lst_push(a, element);
	return (TRUE);
}
