/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:09:31 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/30 19:10:43 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	int		temp;
	int		i;

	i = 0;
	temp = ps->stack_a[0];
	while (i + 1 < ps->a_len)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[ps->a_len - 1] = temp;
	ft_putstr("ra\n");
}

void	rb(t_ps *ps)
{
	int		temp;
	int		i;

	i = 0;
	temp = ps->stack_b[0];
	while (i + 1 < ps->b_len)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[ps->b_len - 1] = temp;
	ft_putstr("rb\n");
}


void	rr(t_ps *ps)
{
	int		temp;
	int		i;

	i = 0;
	temp = ps->stack_a[0];
	while (i + 1 < ps->a_len)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[ps->a_len - 1] = temp;
	i = 0;
	temp = ps->stack_b[0];
	while (i + 1 < ps->b_len)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[ps->b_len - 1] = temp;
	ft_putstr("rr\n");
}
