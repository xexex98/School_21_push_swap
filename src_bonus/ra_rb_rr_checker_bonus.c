/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_checker_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:09:31 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/29 16:25:56 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra_b(t_ps *ps)
{
	int		temp;
	int		i;

	if (ps->a_len < 2)
		return ;
	i = 0;
	temp = ps->stack_a[0];
	while (i + 1 < ps->a_len)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[ps->a_len - 1] = temp;
}

void	rb_b(t_ps *ps)
{
	int		temp;
	int		i;

	if (ps->b_len < 2)
		return ;
	i = 0;
	temp = ps->stack_b[0];
	while (i + 1 < ps->b_len)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[ps->b_len - 1] = temp;
}

void	rr_b(t_ps *ps)
{
	int		temp;
	int		i;

	if (ps->a_len < 2 || ps->b_len < 2)
		return ;
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
}
