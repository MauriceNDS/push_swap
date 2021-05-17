/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:27:06 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/17 10:10:55 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	ret;
	int	mul;

	ret = 0;
	mul = 1;
	if (*str == '-')
	{
		str++;
		mul = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * mul);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	return (*s1 - *s2);
}

int	ft_str_equals(char *s1, char *s2)
{
	return (s1 == s2 || ft_strcmp(s1, s2) == 0);
}
