# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2021/11/24 18:51:15 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap.a\

HEADER	=	push_swap.h\

SRC		=	push_swap.c\
	
OBJS	=	${SRC:.c=.o}

CC 			= gcc
RM 			= rm -f
FLAGS 		= -Wall -Wextra -Werror -I$(HEADER)

OBJECTS = $(patsubst %.c, %.o, $(SRC))

all: $(NAME) 

$(NAME): $(OBJECTS) $(HEADER)
	@ar rcs $(NAME) $?
	@rm -rf *.o
%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) $< -o $@

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: @fclean all

.PHONY: @all clean fclean re