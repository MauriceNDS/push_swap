/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:38:20 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/17 10:10:13 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	manage_arg(char *arg, t_list *a)
{
	char	**args;
	int		i;

	if (arg)
	{
		i = 0;
		args = ft_split(arg, ' ');
		while (args[i])
		{
			if (!check_insert(a, args[i]))
			{
				i = -1;
				while (args[++i])
					free(args[i]);
				free(args);
				return (FALSE);
			}
			i++;
		}
		i = -1;
		while (args[++i])
			free(args[i]);
		free(args);
	}
	return (TRUE);
}

int	manage_array(char **args, int count, t_list *a)
{
	int		i;

	i = -1;
	while (++i < count - 1)
	{
		if (!check_insert(a, args[i]))
			return (FALSE);
	}
	return (TRUE);
}

void	sort_list(t_list *a, t_list *b)
{
	if (a->size < 2)
		;
	else if (a->size == 2)
		sort_2(a, b);
	else if (a->size == 3)
		sort_3(a, b);
	else if (a->size == 4)
		chunk_sort(a, b, 4);
	else if (a->size == 5)
		sort_5(a, b);
	else if (a->size == 100)
		chunk_sort(a, b, 5);
	else if (a->size > 480 && a->size < 520)
		chunk_sort(a, b, 11);
	else
		chunk_sort(a, b, 6);
}

int	program_exit(t_list *a, t_list *b, int i)
{
	lst_destroy(a);
	lst_destroy(b);
	return (i);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = lst_new(NULL);
	b = lst_new(NULL);
	if (argc == 1)
		return (program_exit(a, b, 0));
	else if (argc == 2)
	{
		if (!manage_arg(argv[1], a))
			return (program_exit(a, b, 1));
	}
	else if (!manage_array(++argv, argc, a))
		return (program_exit(a, b, 1));
	if (sorting_check(a, b))
		return (program_exit(a, b, 0));
	sort_list(a, b);
	return (program_exit(a, b, 0));
}
