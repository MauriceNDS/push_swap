/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 08:52:49 by adel-sol          #+#    #+#             */
/*   Updated: 2021/05/14 11:48:18 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*** Includes *****************************************************************/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*** Macros *******************************************************************/

# define TRUE			1
# define FALSE			0

/*** Type definitions *********************************************************/

typedef void					(*t_consumer)(void *);
typedef struct s_entry			t_entry;
typedef struct s_list			t_list;

/*** Double chained, circled lists implementation *****************************/

struct s_entry
{
	int			value;
	int			pos;
	t_entry		*next;
	t_entry		*previous;
};

struct s_list
{
	int			size;
	t_entry		*first;
	t_consumer	del;
};

/*** Methods ******************************************************************/

void		sa(t_list *a);
void		sb(t_list *b);
void		ss(t_list *a, t_list *b);
void		pa(t_list *a, t_list *b);
void		pb(t_list *a, t_list *b);
void		ra(t_list *a);
void		rb(t_list *b);
void		rr(t_list *a, t_list *b);
void		rra(t_list *a);
void		rrb(t_list *b);
void		rrr(t_list *a, t_list *b);

t_list		*lst_new(t_consumer del);
t_entry		*lst_new_entry(int value, int pos);
int			lst_not_empty(t_list *list);
int			lst_is_empty(t_list *list);
void		lst_free(t_list *list);
void		lst_clear(t_list *list);
void		lst_destroy(t_list *list);
t_entry		*lst_shift_entry(t_list *list);
int			lst_shift(t_list *list, int *pos);
int			lst_unshift(t_list *list, int element, int pos);
t_entry		*lst_walk_right(t_entry *walk);
t_entry		*lst_walk_left(t_entry *walk);
t_entry		*lst_push(t_list *list, int value);
int			list_element_exists(t_list *list, int element);
t_list		*list_copy(t_list *lst);
t_list		*list_copy_pos(t_list *dest, t_list *src);

char		*ft_itoa(int n);
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);
char		**ft_split(const char *s, char c);
int			ft_str_equals(char *s1, char *s2);
ssize_t		ft_putnbr_fd(long n, int fd);
ssize_t		ft_putchar_fd(char c, int fd);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *str, int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_substr(const char *s, unsigned int start, size_t len);
void		ft_putendl(char *s);
void		print_stack(t_list *a, char *str);

int			check_insert(t_list *a, char *arg);
int			reading_loop(t_list *a, t_list *b);

t_entry		*find_min(t_list *a);
t_entry		*find_max(t_list *a);
int			closest_ascending(t_list *a, t_entry *elem);
void		action1(char *str, void (f)(t_list *), t_list *a);
void		action2(char *str, void (f)(t_list *, t_list *), t_list *a, \
t_list *b);
void		sort_2(t_list *a, t_list *b);
void		sort_3(t_list *a, t_list *b);
void		sort_4(t_list *a, t_list *b);
void		sort_5(t_list *a, t_list *b);
void		chunk_sort(t_list *a, t_list *b, int cks);
void		push_back(t_list *a, t_list *b);
int			sorting_check(t_list *a, t_list *b);
int			count_chunk_push(t_list *a, int mod, int cond);

/******************************************************************************/

#endif
