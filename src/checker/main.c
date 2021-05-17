/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:31:15 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/14 10:01:28 by adel-sol         ###   ########lyon.fr   */
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
	if (!reading_loop(a, b))
		return (program_exit(a, b, 1));
	return (program_exit(a, b, 0));
}
