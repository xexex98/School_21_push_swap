/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:56:18 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/03 13:58:04 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algoritm_2(t_ps *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1])
		sa(ps);
}

void	ft_algoritm_3(t_ps *ps)
{
	if (ps->stack_a[1] < ps->stack_a[0] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
		sa(ps);
	else if (ps->stack_a[1] < ps->stack_a[0] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
	{
		sa(ps);
		rra(ps);
	}
	else if (ps->stack_a[1] < ps->stack_a[0] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
		ra(ps);
	else if (ps->stack_a[1] > ps->stack_a[0] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
	{	
		sa(ps);
		ra(ps);
	}
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
		rra(ps);
}

void	ft_algoritm_4(t_ps *ps)
{
	ft_find_min(ps);
	while (ps->a_min_pos != 0)
	{
		ra(ps);
		ps->a_min_pos--;
	}
	pb(ps);
	ft_algoritm_3(ps);
	pa(ps);
}
