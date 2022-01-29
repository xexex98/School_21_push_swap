/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_checker_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:22:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/29 17:10:46 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_b(t_ps *ps)
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
}

void	pb_b(t_ps *ps)
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
}

void	sa_b(t_ps *ps)
{
	int	temp;

	if (ps->a_len >= 2)
	{
		temp = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = temp;
	}
	else
		return ;
}

void	sb_b(t_ps *ps)
{
	int	temp;

	if (ps->b_len >= 2)
	{
		temp = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = temp;
	}
	else
		return ;
}

void	ss_b(t_ps *ps)
{
	int	temp;

	if (ps->a_len >= 2 || ps->b_len >= 2)
	{
		if (ps->a_len >= 2)
		{
			temp = ps->stack_a[0];
			ps->stack_a[0] = ps->stack_a[1];
			ps->stack_a[1] = temp;
		}
		if (ps->b_len >= 2)
		{
			temp = ps->stack_b[0];
			ps->stack_b[0] = ps->stack_b[1];
			ps->stack_b[1] = temp;
		}
	}
	else
		return ;
}
