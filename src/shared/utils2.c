/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:42:16 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/14 09:54:51 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
		return (ft_putchar_fd('-', fd) + ft_putnbr_fd(-n, fd));
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	return (ft_putnbr_fd(n / 10, fd) + ft_putnbr_fd(n % 10, fd));
}

char	*ft_strchr(const char *str, int c)
{
	char	*cp;

	if (!str)
		return (NULL);
	cp = (char *)str;
	while (1)
	{
		if (*cp == c)
			return (cp);
		if (!*cp)
			break ;
		++cp;
	}
	return (NULL);
}

static size_t	min(size_t t1, size_t t2)
{
	if (t1 < t2)
		return (t1);
	return (t2);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sstr;
	unsigned char	*dstr;

	i = 0;
	sstr = (unsigned char *)src;
	dstr = dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dstr[i] = sstr[i];
		++i;
	}
	return (dst);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	len = min(len, ft_strlen(s));
	if (start >= ft_strlen(s))
		len = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = 0;
	return (str);
}
