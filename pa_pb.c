/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:35:48 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/06 16:47:46 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	int	i;

	if (ps->b_len == 0)
		return ;
	ps->a_len++;
	ps->b_len--;
	i = ps->a_len - 1;
	while (i >= 1)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = ps->stack_b[0];
	i = 0;
	while (i < ps->b_len)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ft_putstr("pa\n");
}

void	pb(t_ps *ps)
{
	int	i;

	if (ps->a_len == 0)
		return ;
	i = ps->b_len - 1;
	while (i >= 0)
	{
		ps->stack_b[i + 1] = ps->stack_b[i];
		i--;
	}
	ps->stack_b[0] = ps->stack_a[0];
	i = 1;
	while (i < ps->a_len)
	{
		ps->stack_a[i - 1] = ps->stack_a[i ];
		i++;
	}
	ps->a_len--;
	ps->b_len++;
	ft_putstr("pb\n");
}
