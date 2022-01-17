# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2022/01/17 20:46:56 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap\

HEADER	=	push_swap.h\

SRC		=	ft_algoritm_5.c\
			ft_algoritm.c\
			ft_find_max_min.c\
			ft_rules_correct.c\
			ft_utils_1.c\
			pa_pb.c\
			push_swap.c\
			ra_rb_rr.c\
			rra_rrb_rrr.c\
			sa_sb_ss.c\

	
OBJ	=	${SRC:.c=.o}

CC 			= gcc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror -I$(HEADER)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@rm -f *.o
	@echo "\033[32mPush_Swap Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ"

clean:
	@$(RM) $(OBJ)

f: clean
	@$(RM) $(NAME)

re: f all

.PHONY: all clean f re