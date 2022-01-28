/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:55:50 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/28 20:29:47 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(t_ps *ps)
{
	ft_putstr("Check input values!\n");
	fin_free(ps);
	exit(0);
}

void	actions(t_ps *ps, t_v *v)
{
	if (v->flag == 1 || v->flag == 0)
	{
		while (v->a_rra-- > 0)
		{
			if (v->b_rra-- > 0)
				rrr(ps);
			else
				rra(ps);
		}
		while (v->a_ra-- > 0)
		{
			if (v->b_ra-- > 0)
				rr(ps);
			else
				ra(ps);
		}
		while (v->b_rra-- > 0)
			rrb(ps);
		while (v->b_ra-- > 0)
			rb(ps);
	}
	pa(ps);
	return ;
}

void	ikuzoo(int argc, char **argv, int i, t_ps *ps)
{
	while (i < argc)
	{
		if (ft_correct(argv[i]) == 1 && ft_atoi(argv[i]) >= -2147483648
			&& ft_atoi(argv[i]) <= 2147483647)
			ps->stack_a[i - 1] = ft_atoi(argv[i]);
		else
			ft_error(ps);
		i++;
	}
	if (ft_dup(ps->stack_a, ps->a_len) == 1)
	{
		if (ft_sorted(ps) == 1)
			ft_error(ps);
		else
			ft_algoritm(ps);
	}
	else
		ft_error(ps);
}

int	main(int argc, char **argv)
{
	int		i;
	t_ps	*ps;

	i = 1;
	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		return (0);
	if (ft_init_struct(ps, argc) == 0)
		return (0);
	if (argc < 2)
		exit(0);
	else
		ikuzoo(argc, argv, i, ps);
	fin_free(ps);
	return (0);
}

// print_stack(ps);
// void	print_stack(t_ps *ps)
// {
// 	int	i;

// 	i = -1;
// 	printf("\nstack_a:\n");
// 	while (++i < ps->a_len)
// 		printf("%i\n", ps->stack_a[i]);
// 	printf("\nstack_b:\n");
// 	i = -1;
// 	while (++i < ps->b_len)
// 		printf("%i\n", ps->stack_b[i]);
// }
