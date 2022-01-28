/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:54:14 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/28 20:29:57 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_ps *ps)
{
	int		temp;
	int		i;

	i = ps->a_len - 1;
	temp = ps->stack_a[ps->a_len - 1];
	while (i >= 1)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = temp;
	ft_putstr("rra\n");
}

void	rrb(t_ps *ps)
{
	int		temp;
	int		i;

	i = ps->b_len - 1;
	temp = ps->stack_b[ps->b_len - 1];
	while (i >= 1)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = temp;
	ft_putstr("rra\n");
}

void	rrr(t_ps *ps)
{
	int		temp;
	int		i;

	i = ps->a_len - 1;
	temp = ps->stack_a[ps->a_len - 1];
	while (i >= 1)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = temp;
	i = ps->b_len - 1;
	temp = ps->stack_b[ps->b_len - 1];
	while (i >= 1)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = temp;
	ft_putstr("rrr\n");
}
