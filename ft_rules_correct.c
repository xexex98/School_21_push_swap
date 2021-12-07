/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:53:47 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/03 13:57:27 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
