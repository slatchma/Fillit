# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/14 15:43:47 by vsteyaer     #+#   ##    ##    #+#        #
#    Updated: 2017/12/14 21:19:22 by vsteyaer    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_SRCS = ./
PATH_OBJS = ./
PATH_INCS = ./
FILES = main ft_lstend ft_hashtcheck ft_squaremin ft_solve ft_sqrtdecimal ft_putsolve ft_delsolve ft_dotinitialise ft_putchar ft_putstr
SRCS = $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(PATH_OBJS), $(addsuffix .o, $(FILES:.c=.o)))
INCS = $(addprefix $(PATH_INCS), fillit.h)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o : $(PATH_SRCS)%.c $(INCS)
	$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INCS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
