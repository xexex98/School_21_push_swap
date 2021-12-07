/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:58:05 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/06 14:50:31 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_top_min_5(t_ps *ps)
{
	if (ps->a_min_pos == 0)
		pb(ps);
	else if (ps->a_min_pos == 1)
	{
		ra(ps);
		pb(ps);
	}
	else if (ps->a_min_pos == 2)
	{
		ra(ps);
		ra(ps);
		pb(ps);
	}
	else if (ps->a_min_pos == 3)
	{
		rra(ps);
		pb(ps);
	}
	else if (ps->a_min_pos == 4)
	{
		rra(ps);
		pb(ps);
	}
}

void	ft_push_top_max_5(t_ps *ps)
{
	if (ps->a_max_pos == 0)
		pb(ps);
	else if (ps->a_max_pos == 1)
	{
		ra(ps);
		pb(ps);
	}
	else if (ps->a_max_pos == 2)
	{
		ra(ps);
		ra(ps);
		pb(ps);
	}
	else if (ps->a_max_pos == 3)
	{
		rra(ps);
		rra(ps);
		pb(ps);
	}
	else if (ps->a_max_pos == 4)
	{
		rra(ps);
		pb(ps);
	}
}

void	ft_algoritm_5(t_ps *ps)
{
	ft_find_max(ps);
	ft_push_top_max_5(ps);
	ft_find_min(ps);
	ft_push_top_min_5(ps);
	ft_algoritm_3(ps);
	pa(ps);
	pa(ps);
	ra(ps);
}
