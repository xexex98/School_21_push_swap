/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:35:48 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/28 20:29:51 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_ps *ps)
{
	int	i;

	if (ps->b_len == 0)
		return ;
	i = ps->a_len - 1;
	while (i >= 0)
	{
		ps->stack_a[i + 1] = ps->stack_a[i];
		i--;
	}
	ps->stack_a[0] = ps->stack_b[0];
	i = 1;
	while (i < ps->arrsize)
	{
		ps->stack_b[i - 1] = ps->stack_b[i];
		i++;
	}
	ps->stack_b[ps->arrsize - 1] = 0;
	ps->a_len++;
	ps->b_len--;
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
	while (i < ps->arrsize)
	{
		ps->stack_a[i - 1] = ps->stack_a[i];
		i++;
	}
	ps->stack_a[ps->arrsize - 1] = 0;
	ps->b_len++;
	ps->a_len--;
	ft_putstr("pb\n");
}
