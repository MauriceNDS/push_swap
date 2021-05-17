NAME		=       shared.a

INCLUDES	=		-I../../includes

SRCS		=       list_creator.c				\
					list_manage1.c				\
					list_manage2.c				\
					push.c						\
					rotate.c					\
					rrotate.c					\
					split.c						\
					swap.c						\
					utils.c						\
					utils2.c					\
					utils3.c					\
					ft_itoa.c

OBJS		=       ${SRCS:.c=.o}

CFLAGS		=		-Wall -Wextra  -g

CC			=		gcc

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

.PHONY : all fclean clean re
