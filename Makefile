# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2022/01/28 20:32:37 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap\

NAME_B	=	push_swap_bonus\

HEADER		=	./src/push_swap.h\

HEADER_B	=	./src_bonus/push_swap_bonus.h\

SRC		=	./src/ft_algoritm_5.c\
			./src/ft_algoritm.c\
			./src/ft_find_max_min.c\
			./src/ft_rules_correct.c\
			./src/ft_utils.c\
			./src/main.c\
			./src/pa_pb.c\
			./src/push_swap.c\
			./src/ra_rb_rr.c\
			./src/rra_rrb_rrr.c\
			./src/sa_sb_ss.c\

SRC_B	=	./src_bonus/ft_algoritm_5_bonus.c\
			./src_bonus/ft_algoritm_bonus.c\
			./src_bonus/ft_find_max_min_bonus.c\
			./src_bonus/ft_rules_correct_bonus.c\
			./src_bonus/ft_utils_bonus.c\
			./src_bonus/main_bonus.c\
			./src_bonus/pa_pb_bonus.c\
			./src_bonus/push_swap_bonus.c\
			./src_bonus/ra_rb_rr_bonus.c\
			./src_bonus/rra_rrb_rrr_bonus.c\
			./src_bonus/sa_sb_ss_bonus.c\
	
OBJ		=	${SRC:%.c=%.o}

OBJ_B	=	${SRC_B:%.c=%.o}

CC 			= gcc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror

%.o: %.c $(HEADER) $(HEADER_B)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32mPush_Swap Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ"

b: $(NAME_B) 

$(NAME_B): $(OBJ_B) $(HEADER_B)
	@$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)
	@rm -f ./src_bonus/*.o
	@echo "\033[32mPush_Swap_Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ"

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_B)

f: clean
	@$(RM) $(NAME) $(NAME_B)

re: f all

.PHONY: b all clean f re