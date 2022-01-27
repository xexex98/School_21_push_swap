/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:44 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/27 17:54:18 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_struct(t_ps *ps, int argc)
{
	ps->arrsize = (argc - 1);
	ps->a_len = (argc - 1);
	ps->b_len = 0;
	ps->a_min_pos = 0;
	ps->b_min_pos = 0;

	ps->a_max_pos = 0;
	ps->b_max_pos = 0;

	ps->a_mid_pos = 0;
	ps->b_mid_pos = 0;
	ps->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ps->stack_a)
		return (0);
	ps->stack_b = (int *)ft_calloc((argc - 1), 4);
	if (!ps->stack_b)
		return (0);
	ps->index = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ps->index)
		return (0);
	ps->index_b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ps->index_b)
		return (0);
	return (1);
}


void print_stack(t_ps *ps)
{
	int	i;

	i = -1;
	
	printf("\nstack_a:\n");
	while (++i < ps->a_len)
		printf("%i\n", ps->stack_a[i]);
	
	printf("\nstack_b:\n");
	i = -1;
	while (++i < ps->b_len)
		printf("%i\n", ps->stack_b[i]);
	// i = -1;
	// printf("\nindex_b:\n");
	// while (++i < ps->b_len)
	// 	printf("%i\n", ps->index_b[i]);
	// printf("\n");
}


void	ft_find_min_b(t_ps *ps)
{
	int	j;

	ps->b_min = ps->stack_b[0];
	j = 0;
	while (j < ps->b_len)
	{
		if (ps->stack_b[j] < ps->b_min)
		{
			ps->b_min = ps->stack_b[j];
			ps->b_min_pos = j;
		}
		j++;
	}
}

void	ft_find_max_b(t_ps *ps)
{
	int	i;

	ps->b_max = ps->stack_b[0];
	i = 0;
	while (i < ps->b_len)
	{
		if (ps->stack_b[i] > ps->b_max)
		{
			ps->b_max = ps->stack_b[i];
			ps->b_max_pos = i;
		}
		i++;
	}
}

// 100, 700 дейсвий
void	ft_algoritm_100(t_ps *ps)
{
	int	i;
	int j;
	int	mid;

	mid = ps->arrsize / 2;
	ft_index(ps);
	
	i = -1;
	while (++i < ps->a_len)
		ps->stack_a[i] = ps->index[i];

	while (ps->a_len != 3)
	{
		if (ps->stack_a[0] == 1 || ps->stack_a[0] == ps->arrsize || ps->stack_a[0] == mid)
			ra(ps);
		else
			pb(ps);
	}
	ft_algoritm_3(ps);
	// i = 0;
	// j = 0;

	// print_stack(ps);

	//stack_b
			// int price_b = 0;

			// i = 0;
			// while (i < ps->b_len)
			// {
			// 	if (i <= ps->b_len / 2)
			// 		price_b = i;
			// 	else if (i > ps->b_len / 2)
			// 		price_b = ps->b_len - i;
			// 	printf("ind_b:%i b:%i\n", i, price_b);
			// 	i++;
			// }

	//stack_a
	int price_a = 0;
	int price = 0;
	int	min_price = 1000;
	int	min_price_ra;
	int	min_price_rra;

	int	min_price_b;
	j = 0;
	// while (j < ps->a_len)
	// {
	// 	if (j <= ps->a_len / 2)
	// 		price_a = j;
	// 	else if (j > ps->a_len / 2)
	// 		price_a = ps->a_len - j;
	// 	printf("ind_a:%i a:%i\n", j, price_a);
	// 	j++;
	// }
	// print_stack(ps);
	// print_stack(ps);

	// pb(ps);
	// pb(ps);
	// pb(ps);
	// pb(ps);
	// pb(ps);
	// pb(ps);
	// pb(ps);
	// rrb(ps);
	// pa(ps);

	// print_stack(ps);

	// return ;
	int	nra = 0;
	int	nrra = 0;
	int price_b_rb = 0;
	int price_b_rrb = 0;

	int	a_ra = 0;
	int	b_ra = 0;
	int	a_rra = 0;
	int	b_rra = 0;
	int flag = 0;
	i = 0;
	j = 0;
	// printf("\n\n");
	int pri_rb = 0;
	int pri_rrb = 0;
	int price_b = 0;
	while (ps->b_len != 0)
	{
		// print_stack(ps);

		while (i < ps->b_len)
		{				
				if (i <= ps->b_len / 2)
				{
					price_b_rb = i;
					pri_rrb = ps->b_len - i;
					pri_rb = i;
					price_b_rrb = 0;
				}
				else if (i > ps->b_len / 2)
				{
					price_b_rrb = ps->b_len - i;
					pri_rrb = ps->b_len - i;
					pri_rb = i;
					price_b_rb = 0;
				}
			
				if (ps->stack_b[i] > ps->stack_a[0] && ps->stack_b[i] < ps->stack_a[ps->a_len - 1])
				{
					while (ps->stack_b[i] > ps->stack_a[nra])
						nra++;
					while (ps->stack_b[i] < ps->stack_a[ps->a_len - 1 - nrra])
						nrra++;
				}
				else if (ps->stack_b[i] > ps->stack_a[0] && ps->stack_b[i] > ps->stack_a[ps->a_len - 1])
				{
					while (ps->stack_b[i] > ps->stack_a[nra])
						nra++;
					while (ps->stack_b[i] > ps->stack_a[ps->a_len - 1 - nrra])
						nrra++;
					while (ps->stack_b[i] < ps->stack_a[ps->a_len - 1 - nrra])
						nrra++;
				}
				else if (ps->stack_b[i] < ps->stack_a[0] && ps->stack_b[i] < ps->stack_a[ps->a_len - 1])
				{
					while (ps->stack_b[i] < ps->stack_a[nra])
						nra++;
					while (ps->stack_b[i] > ps->stack_a[nra])
						nra++;
					while (ps->stack_b[i] < ps->stack_a[ps->a_len - 1 - nrra])
						nrra++;
				}
				else if (ps->stack_b[i] < ps->stack_a[0] && ps->stack_b[i] > ps->stack_a[ps->a_len - 1])
				{
					while (ps->stack_b[i] > ps->stack_a[nra])
						nra++;
					while (ps->stack_b[i] > ps->stack_a[ps->a_len - 1 - nrra])
						nrra++;
				}

				// if (nra + price_b_rb < nra + price_b_rrb && nra + price_b_rb < nrra + price_b_rb
				// 	&& nra + price_b_rb < nrra + price_b_rrb)
				// {
				// 	price = nra + price_b_rb;
				// 	if (price < min_price)
				// 	{	
				// 		min_price = price;
			
				// 		a_ra = nra;
				// 		b_ra = price_b_rb;
						
				// 		a_rra = 0;
				// 		b_rra = 0;
						
				// 		// price_b_rrb = 0;
				// 	}
				// }
				// if (nrra + price_b_rrb < nrra + price_b_rb && nrra + price_b_rrb < nra + price_b_rrb
				// 	&& nrra + price_b_rrb < nra + price_b_rb)
				// {
					// price = nra + price_b_rrb;
					// if (price < min_price)
					// {
					// 	min_price = price;
						
					// 	a_rra = nrra;
					// 	b_rra = price_b_rrb;
						
					// 	a_ra = 0;
					// 	b_ra = 0;
						
					// 	// price_b_rb = 0;
					// }
				// }
				// else
				// {
					if (nra < nrra)
					{
						flag = 0;
						price = price_b_rb + price_b_rrb + nra;
					}
					else if (nra > nrra)
					{
						flag = 1;
						price = price_b_rb + price_b_rrb + nrra;
					}
					if (price < min_price)
					{
						min_price = price;
						if (flag == 0)
						{
							a_rra = 0;
							a_ra = nra;
							b_ra = price_b_rb;
							b_rra = price_b_rrb;
						}
						else if (flag == 1)
						{
							a_rra = nrra;
							a_ra = 0;
							b_ra = price_b_rb;
							b_rra = price_b_rrb;
						}
					}
				// }



				// }
				nra = 0;
				nrra = 0;
				price_b_rb = 0;
				price_b_rrb = 0;
			i++;
		}
		i = 0;
		min_price = 1000;

		while (a_rra-- > 0)
		{
			if (b_rra-- > 0)
				rrr(ps);
			else
				rra(ps);
		}
		while (a_ra-- > 0)
		{
			if (b_ra-- > 0)
				rr(ps);
			else
				ra(ps);
		}
		while (b_rra-- > 0)
			rrb(ps);
		while (b_ra-- > 0)
			rb(ps);
		pa(ps);
	}
	ft_find_min(ps);
	if (ps->a_min_pos >= ps->a_len / 2)
		while (ft_sorted(ps) != 1)
			rra(ps);
	else
		while (ft_sorted(ps) != 1)
			ra(ps);
	// print_stack(ps);
	return ;
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
	else if (ps->a_len <= 550)
		ft_algoritm_100(ps);
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
	return (0);
}
