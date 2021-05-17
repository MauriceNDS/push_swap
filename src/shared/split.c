/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:43:59 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/03 12:49:38 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*free_all(char **obj, int len)
{
	while (len--)
	{
		free(*obj);
		obj++;
	}
	free(obj);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	cur;

	while (n)
	{
		if (n >= sizeof(long))
		{
			cur = sizeof(long);
			*((long *)s) = 0;
		}
		else
		{
			cur = 1;
			*((char *)s) = 0;
		}
		s += cur;
		n -= cur;
	}
}

static int	ft_init(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			++j;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, count * size);
	return (pointer);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	*newstr;
	char	**output;

	output = ft_calloc(ft_init(s, c) + 1, sizeof(*output));
	if (!s || !output)
		return (NULL);
	i = 0;
	while (*s)
	{
		newstr = ft_strchr(s, c);
		if (!newstr)
			newstr = ft_strchr(s, 0);
		if (newstr - s)
		{
			output[i] = ft_substr(s, 0, newstr - s);
			if (!output[i++])
				return (free_all(output, --i));
			s = newstr;
		}
		else
			s++;
	}
	output[i] = NULL;
	return (output);
}
