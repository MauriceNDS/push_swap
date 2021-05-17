
NAME        =       checker

INCLUDES	=		-I../../includes

SRCS        =       ../gnl/get_next_line.c			\
                    ../gnl/get_next_line_utils.c	\
					main.c							\
					read.c

OBJS        =       ${SRCS:.c=.o}

CFLAGS		=       -Wall -Wextra -Werror -g

CC			=		gcc

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) ../shared/shared.a -o $(NAME) $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

.PHONY : all fclean clean re
