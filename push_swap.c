/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:44 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/30 19:33:25 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{	
	t_ps *ps;
	int i;
	unsigned int j = 0;
	i = 1;
	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (0);
	ps->a_len = (argc - 1);
	ps->b_len = 0;
	ps->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	ps->stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	
	while (i < argc)
	{
		ps->stack_a[i - 1] = ft_atoi(argv[i]);
		// printf("%i", ps->stack_a[i - 1]);
		i++;
	}
	pb(ps);
	pb(ps);
	pb(ps);
	rrr(ps);
	while (j < 3)
	{
		printf("%i", ps->stack_a[j]);
		j++;
	}
	write(1, "\n", 2);
	j = 0;
	while (j < 3)
	{
		printf("%i", ps->stack_b[j]);
		j++;
	}
	// printf("%d", ;
	return (0);
}