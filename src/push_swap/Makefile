NAME        =       push_swap

INCLUDES	=		-I../../includes

SRCS        =       main.c				\
					error_check.c		\
					algo.c				\
					small_sort.c		\
					chunk_sort1.c		\
					chunk_sort2.c

OBJS        =       ${SRCS:.c=.o}

CFLAGS      =       -Wall -Wextra -Werror -g

CC			=		gcc

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) ../shared/shared.a -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

.PHONY : all fclean clean re
