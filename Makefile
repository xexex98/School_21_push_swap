# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2022/01/29 21:07:47 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap\

NAME_B	=	checker\

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

SRC_B	=	./src_bonus/ft_rules_correct_bonus.c\
			./src_bonus/ft_utils_bonus.c\
			./src_bonus/ft_utils2_bonus.c\
			./src_bonus/main_bonus.c\
			./src_bonus/ra_rb_rr_checker_bonus.c\
			./src_bonus/rra_rrb_rrr_checker_bonus.c\
			./src_bonus/ps_pb_sa_sb_ss_checker_bonus.c\
			./src_bonus/gnl/get_next_line.c\
			./src_bonus/gnl/get_next_line_utils.c\
	
OBJ		=	${SRC:%.c=%.o}

OBJ_B	=	${SRC_B:%.c=%.o}

CC 			= gcc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror

%.o: %.c $(HEADER) $(HEADER_B)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) -I ./gnl $(OBJ) -o $(NAME)
	@echo "\033[32mPush_Swap Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ""\033[0m"

bonus: $(NAME_B) 

$(NAME_B): $(OBJ_B) $(HEADER_B)
	@$(CC) $(CFLAGS) -I ./gnl $(OBJ_B) -o $(NAME_B)
	@echo "\033[32mPush_Swap_Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ""\033[0m"

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_B)

fclean: clean
	@$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: bonus all clean fclean re