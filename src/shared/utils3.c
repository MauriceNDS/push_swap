/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:54:15 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/17 14:20:12 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		;
	return (i);
}

ssize_t	ft_putchar_fd(char c, int fd)
{
	if (c)
		return (write(fd, &c, 1));
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	size_t	size;
	int		i;

	size = ft_strlen(s1) + 1;
	pointer = malloc(size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		pointer[i] = s1[i];
		i++;
	}
	pointer[i] = 0;
	return (pointer);
}

void	ft_putendl(char *s)
{
	// printf("%s\n", s);
	if (ft_strlen(s) > 0)
		write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void	print_stack(t_list *a, char *str)
{
	t_entry	*walker;
	int		i;

	walker = a->first;
	i = 0;
	ft_putendl("_________________________");
	ft_putendl(str);
	ft_putendl("_________________________");
	while (i++ < a->size)
	{
		ft_putnbr_fd(walker->value, 1);
		write(1, "\t\t", 2);
		ft_putnbr_fd(walker->pos, 1);
		ft_putendl("");
		walker = walker->next;
	}
}
