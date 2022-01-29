/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:40:26 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/29 21:05:00 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./gnl/get_next_line.h"

typedef struct s_ps
{
	int		*stack_a;
	int		*stack_b;
	int		*index;

	int		arrsize;
	int		a_len;
	int		b_len;
	int		a_max;
	int		a_min;
	int		a_min_pos;
	int		a_max_pos;
	int		a_mid_pos;
}				t_ps;

typedef struct s_v
{
	int	price;
	int	min_price;
	int	nra;
	int	nrra;
	int	price_b_rb;
	int	price_b_rrb;
	int	a_ra;
	int	b_ra;
	int	a_rra;
	int	b_rra;
	int	flag;
	int	i;
}				t_v;

int			ft_correct(char *str);
int			ft_sorted(t_ps *ps);
int			ft_dup(int *str, int len);
int			ft_init_struct(t_ps *ps, int argc);

void		ft_putstr(char *str);
int			ft_strlen(char *str);
int			ft_isdigit(int c);
long int	ft_atoi(const char *nptr);
void		*ft_memset(void *s, int c, size_t n);

int			ft_strcmp_n(const char *s1, const char *s2);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_calloc(size_t nmemb, size_t size);
void		fin_free(t_ps *ps);
void		checker_error(t_ps *ps, char *line);

void		pa_b(t_ps *ps);
void		pb_b(t_ps *ps);
void		sa_b(t_ps *ps);
void		sb_b(t_ps *ps);
void		ss_b(t_ps *ps);

void		ra_b(t_ps *ps);
void		rb_b(t_ps *ps);
void		rr_b(t_ps *ps);

void		rra_b(t_ps *ps);
void		rrb_b(t_ps *ps);
void		rrr_b(t_ps *ps);

void		ft_error(t_ps *ps);
void		checker_2(t_ps *ps, char *line);
void		checker(t_ps *ps);
void		ikuzoo(int argc, char **argv, int i, t_ps *ps);

#endif
// void		print_stack(t_ps *ps);