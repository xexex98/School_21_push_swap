/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:44 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/07 16:05:42 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_struct(t_ps *ps, int argc)
{
	ps->a_len = (argc - 1);
	ps->b_len = 0;
	ps->a_min_pos = 0;
	ps->a_max_pos = 0;
	ps->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ps->stack_a)
		return (0);
	ps->stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ps->stack_b)
		return (0);
	return (1);
}

void	ft_algoritm_100(t_ps *ps)
{
	int	len_a;
	int	len_b;
	int	mid;
	int	mediana;
	
	len_a = ps->a_len;
	mid = ps->a_len / 2;
	mediana = ps->stack_a[mid];
	while (len_a)
	{
		if (ps->stack_a[0] <= mediana)
			pb(ps);
		else if (ps->stack_a[0] > mediana)
			ra(ps);
		len_a--;
	}
	
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
	else if (ps->a_len <= 100)
		ft_algoritm_100(ps);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_ps	*ps;

	i = 1;
	j = 0;
	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		return (0);
	if (ft_init_struct(ps, argc) == 0)
		return (0);
	if (argc < 2)
		ft_putstr("Error\n");
	else
	{
		while (i < argc)
		{
			if (ft_correct(argv[i]) == 1 && ft_atoi(argv[i]) >= -2147483648
				&& ft_atoi(argv[i]) <= 2147483647)
				ps->stack_a[i - 1] = ft_atoi(argv[i]);
			else
			{	
				ft_putstr("Error");
				return (0);
			}
			i++;
		}
		if (ft_dup(ps->stack_a, ps->a_len) == 1)
		{
			if (ft_sorted(ps) == 1)
				return (0);
			ft_algoritm(ps);
		}
		else
			ft_putstr("Error\n");
	}
	i = 0;
	// sb(ps);
	// pb(ps);
	// pa(ps);
	while (i < ps->a_len)
	{
		printf("a:%i\n", ps->stack_a[i]);
		i++;
	}
	i = 0;
	while (i < ps->b_len)
	{
		printf("b:%i\n", ps->stack_b[i]);
		i++;
	}
	// free(ps->stack_a);
	// free(ps->stack_b);
	// free(ps);
	// while (1)
		// sleep(100);
	return (0);

}
