/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_correct_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:53:47 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/28 20:29:41 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_correct(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1 && str[i] == '-')
		return (0);
	if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	ft_sorted(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->a_len - 1)
	{
		if (ps->stack_a[i] > ps->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_dup(int *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_init_struct(t_ps *ps, int argc)
{
	ps->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ps->stack_a)
		return (0);
	ps->stack_b = (int *)ft_calloc((argc - 1), 4);
	if (!ps->stack_b)
		return (0);
	ps->index = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ps->index)
		return (0);
	ps->arrsize = (argc - 1);
	ps->a_len = (argc - 1);
	ps->b_len = 0;
	ps->a_max = 0;
	ps->a_min = 0;
	ps->a_min_pos = 0;
	ps->a_max_pos = 0;
	ps->a_mid_pos = 0;
	return (1);
}

void	init_v(t_v *v)
{
	v->price = 0;
	v->min_price = 0;
	v->nra = 0;
	v->nrra = 0;
	v->price_b_rb = 0;
	v->price_b_rrb = 0;
	v->a_ra = 0;
	v->b_ra = 0;
	v->a_rra = 0;
	v->b_rra = 0;
	v->flag = 0;
	v->i = 0;
	return ;
}
