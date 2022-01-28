/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:56:18 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/28 20:29:39 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_algoritm_main(t_ps *ps)
{
	t_v	v;

	init_v(&v);
	min_max_in_a_and_index(ps);
	while (ps->b_len != 0)
	{
		v.i = 0;
		v.min_price = ps->arrsize * 10;
		while (v.i < ps->b_len)
		{
			b_val(ps, &v);
			price_1(ps, &v);
			price_2(ps, &v);
			flag(&v);
			steps_val(&v);
			v.i++;
		}
		actions(ps, &v);
	}
	fin_rotatae(ps);
}

void	ft_algoritm(t_ps *ps)
{
	if (ps->a_len == 2)
		ft_algoritm_2(ps);
	else if (ps->a_len == 3)
		ft_algoritm_3(ps);
	else if (ps->a_len == 4)
		ft_algoritm_4(ps);
	else if (ps->a_len == 5)
		ft_algoritm_5(ps);
	else if (ps->a_len <= 500)
		ft_algoritm_main(ps);
	return ;
}
