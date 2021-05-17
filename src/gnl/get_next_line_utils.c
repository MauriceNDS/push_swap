#include "get_next_line.h"
#include "push_swap.h"

int	ft_strindex_of(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		if (str[i++] == c)
			return (i - 1);
	return (-1);
}

char	**ft_split_first(char *s, char c)
{
	char	**parts;
	int		i;

	parts = malloc(sizeof(*parts) * 2);
	if (!parts)
		return (NULL);
	i = ft_strindex_of(s, c);
	parts[1] = NULL;
	if (i == -1)
		parts[0] = s;
	else
	{
		parts[0] = ft_substr(s, 0, i);
		parts[1] = ft_strdup(s + i + 1);
		free(s);
		if (!parts[0] || !parts[1])
		{
			free(parts[0]);
			free(parts[1]);
			free(parts);
			return (NULL);
		}
	}
	return (parts);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = 0;
	return (str);
}

int	gnl_init(char ***current, char **tmp_line, ssize_t *result)
{
	if (BUFF_SIZE < 1)
		return (FALSE);
	*tmp_line = NULL;
	*current = NULL;
	*result = BUFF_SIZE;
	return (TRUE);
}
