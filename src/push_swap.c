/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:44 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/28 19:01:11 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	price_1(t_ps *ps, t_v *v)
{
	if (ps->stack_b[v->i] > ps->stack_a[0]
		&& ps->stack_b[v->i] < ps->stack_a[ps->a_len - 1])
	{
		while (ps->stack_b[v->i] > ps->stack_a[v->nra])
			v->nra++;
		while (ps->stack_b[v->i] < ps->stack_a[ps->a_len - 1 - v->nrra])
			v->nrra++;
	}
	if (ps->stack_b[v->i] > ps->stack_a[0]
		&& ps->stack_b[v->i] > ps->stack_a[ps->a_len - 1])
	{
		while (ps->stack_b[v->i] > ps->stack_a[v->nra])
			v->nra++;
		while (ps->stack_b[v->i] > ps->stack_a[ps->a_len - 1 - v->nrra])
			v->nrra++;
		while (ps->stack_b[v->i] < ps->stack_a[ps->a_len - 1 - v->nrra])
			v->nrra++;
	}
}

void	price_2(t_ps *ps, t_v *v)
{
	if (ps->stack_b[v->i] < ps->stack_a[0]
		&& ps->stack_b[v->i] < ps->stack_a[ps->a_len - 1])
	{
		while (ps->stack_b[v->i] < ps->stack_a[v->nra])
			v->nra++;
		while (ps->stack_b[v->i] > ps->stack_a[v->nra])
			v->nra++;
		while (ps->stack_b[v->i] < ps->stack_a[ps->a_len - 1 - v->nrra])
			v->nrra++;
	}
	if (ps->stack_b[v->i] < ps->stack_a[0]
		&& ps->stack_b[v->i] > ps->stack_a[ps->a_len - 1])
	{
		while (ps->stack_b[v->i] > ps->stack_a[v->nra])
			v->nra++;
		while (ps->stack_b[v->i] > ps->stack_a[ps->a_len - 1 - v->nrra])
			v->nrra++;
	}
}

void	flag(t_v *v)
{
	if (v->nra < v->nrra)
	{
		v->flag = 0;
		v->price = v->price_b_rb + v->price_b_rrb + v->nra;
	}
	else if (v->nra > v->nrra)
	{
		v->flag = 1;
		v->price = v->price_b_rb + v->price_b_rrb + v->nrra;
	}
}

void	steps_val(t_v *v)
{
	if (v->price < v->min_price)
	{
		v->min_price = v->price;
		if (v->flag == 0)
		{
			v->a_ra = v->nra;
			v->b_ra = v->price_b_rb;
			v->b_rra = v->price_b_rrb;
			v->a_rra = 0;
		}
		else if (v->flag == 1)
		{
			v->a_rra = v->nrra;
			v->b_ra = v->price_b_rb;
			v->b_rra = v->price_b_rrb;
			v->a_ra = 0;
		}
	}
}

void	b_val(t_ps *ps, t_v *v)
{
	v->nra = 0;
	v->nrra = 0;
	if (v->i <= ps->b_len / 2)
	{
		v->price_b_rrb = 0;
		v->price_b_rb = v->i;
	}
	else if (v->i > ps->b_len / 2)
	{
		v->price_b_rrb = ps->b_len - v->i;
		v->price_b_rb = 0;
	}
	return ;
}
