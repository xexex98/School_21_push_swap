/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:59:45 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/18 13:42:38 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_max(t_ps *ps)
{
	int	i;

	ps->a_max = ps->stack_a[0];
	i = 0;
	while (i < ps->a_len)
	{
		if (ps->stack_a[i] > ps->a_max)
		{
			ps->a_max = ps->stack_a[i];
			ps->a_max_pos = i;
		}
		i++;
	}
}

void	ft_find_min(t_ps *ps)
{
	int	j;

	ps->a_min = ps->stack_a[0];
	j = 0;
	while (j < ps->a_len)
	{
		if (ps->stack_a[j] < ps->a_min)
		{
			ps->a_min = ps->stack_a[j];
			ps->a_min_pos = j;
		}
		j++;
	}
}

void	ft_index(t_ps *ps)
{
	int	i;
	int	j;
	int	z;

	i = -1;
	while (++i < ps->a_len)
	{
		ps->index[i] = ps->stack_a[i];
		j = -1;
		z = 1;
		while (++j < ps->a_len)
			if (ps->index[i] > ps->stack_a[j])
				z++;
		ps->index[i] = z;
	}
	return ;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*str;
	unsigned int	mem;

	mem = nmemb * size;
	str = malloc(mem);
	if (!str)
		return (NULL);
	ft_memset(str, '\0', mem);
	return (str);
}
