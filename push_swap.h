/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:40:26 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/30 19:08:15 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP__
# define __PUSH_SWAP__

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ps
{
	int		*stack_a;
	int		*stack_b;
	int		a_len;
	int		b_len;
}				t_ps;


int	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int	ft_atoi(const char *nptr);
void	ft_putstr(char *str);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

#endif