#include "push_swap.h"

static char	*count_char(long n, int *count)
{
	int		sign;
	char	*res;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
		(*count)++;
	}
	while (n / 10)
	{
		n /= 10;
		(*count)++;
	}
	(*count)++;
	res = malloc(sizeof(char) * (*count + 1));
	if (!res)
		return (NULL);
	return (res);
}

static void	manage_range(char *res, long *n, long *div, int *i)
{
	if (*n < 0)
	{
		res[(*i)++] = '-';
		*n *= -1;
		*div /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	long	cp;
	int		count;
	long	div;
	int		i;

	count = 0;
	i = 0;
	div = 1;
	cp = (long)n;
	res = count_char(cp, &count);
	if (!res)
		return (NULL);
	while (--count)
		div *= 10;
	manage_range(res, &cp, &div, &i);
	while (div)
	{
		res[i++] = cp / div + 48;
		cp %= div;
		div /= 10;
	}
	res[i] = '\0';
	return (res);
}
