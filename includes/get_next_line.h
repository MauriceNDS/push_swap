/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:18:49 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/03 16:20:02 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define FALSE				0
# define TRUE				1
# define BUFF_SIZE			50

typedef struct s_gnl_entry	t_gnl_entry;

struct s_gnl_entry
{
	void	*next;
	int		fd;
	char	*content;
};

char		**ft_split_first(char *s, char c);
int			get_next_line(int fd, char **line);
char		*ft_strjoin(const char *s1, const char *s2);
int			gnl_init(char ***current, char **tmp_line, ssize_t *result);

#endif
