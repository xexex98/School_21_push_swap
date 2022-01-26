/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:44 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/26 21:18:03 by mbarra           ###   ########.fr       */
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
	int price_b = 0;
	int	a_ra = 0;
	int	b_ra = 0;
	int	a_rra = 0;
	int	b_rra = 0;
	int flag = 0;
	i = 0;
	j = 0;
	// printf("\n\n");
	while (ps->b_len != 0)
	{
		// print_stack(ps);

		while (i < ps->b_len)
		{
			price_b = i;
		
			// if (i <= ps->b_len / 2)
			// 	price_b = i;
			// else if (i > ps->b_len / 2)
			// 	price_b = ps->b_len - i;
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
					// while (ps->stack_b[i] > ps->stack_a[ps->a_len - 1 - nrra])
					while (ps->stack_b[i] > ps->stack_a[ps->a_len - 1 - nrra])
						nrra++;
					while (ps->stack_b[i] < ps->stack_a[ps->a_len - 1 - nrra])
						nrra++;
					// while (ps->stack_b[i] > ps->stack_a[ps->a_len - nrra] && ps->stack_b[i] < ps->stack_a[ps->a_len - 1 - nrra])
				}
				else if (ps->stack_b[i] < ps->stack_a[0] && ps->stack_b[i] < ps->stack_a[ps->a_len - 1])
				{
					while (ps->stack_b[i] < ps->stack_a[nra])
						nra++;
					while (ps->stack_b[i] > ps->stack_a[nra])
						nra++;
					while (ps->stack_b[i] < ps->stack_a[ps->a_len - 1 - nrra])
						nrra++;
					// while (ps->stack_b[i] < ps->stack_a[ps->a_len - 1 - nrra])
						// nrra++;
				}
				else if (ps->stack_b[i] < ps->stack_a[0] && ps->stack_b[i] > ps->stack_a[ps->a_len - 1])
				{
					while (ps->stack_b[i] > ps->stack_a[nra])
						nra++;
					while (ps->stack_b[i] > ps->stack_a[ps->a_len - 1 - nrra])
						nrra++;
				}
				if (nra < nrra)
				{
					flag = 0;
					price = price_b + nra;
				}
				else if (nra > nrra)
				{
					flag = 1;
					price = price_b + nrra;
				}
				// printf("nra %i  ", nra);
				// printf("nrra %i\n", nrra);
				// printf ("price: %i\n", price);
				
				if (price < min_price)
				{
					min_price = price;
					if (flag == 0)
					{
						a_ra = nra;
						b_ra = price_b;
						a_rra = 0;
						b_rra = 0;
					}
					else if (flag == 1)
					{
						a_ra = 0;
						b_ra = 0;
						a_rra = nrra;
						b_rra = price_b;
					}
				}
				nra = 0;
				nrra = 0;
			i++;

		}
		i = 0;
		min_price = 1000;
		price = 0;
		// printf("\n\n");
		// printf ("a_rra %i a_ra %i b_rra %i b_ra %i   ", a_rra, a_ra, b_rra, b_ra);
		// 	printf ("price: %i\n", price);

		// print_stack(ps);

		while (a_rra > 0)
		{
			a_rra--;
			rra(ps);
		}
		while (a_ra > 0)
		{
			a_ra--;
			ra(ps);
		}
		while (b_rra > 0)
		{
			b_rra--;
			rb(ps);
		}
		while (b_ra > 0)
		{
			b_ra--;
			rb(ps);
		}
		// printf("b %i\n", price_b);
		// printf("rra %i\n", nrra);
		// printf ("flag: %i\n", flag);

		pa(ps);
	}
	while (ft_sorted(ps) != 1)
		ra(ps);
	print_stack(ps);














	return ;
	// while (ps->b_len != 0)
	// {
	// 	while (i < ps->b_len)
	// 	{
	// 		if (i <= ps->b_len / 2)
	// 			price_b = i;
	// 		else if (i > ps->b_len / 2)
	// 			price_b = ps->b_len - i;

	// 		// if (ps->stack_b[i] > ps->stack_a[ps->a_len - 1])
	// 			while (ps->stack_b[i] > ps->stack_a[ra])
	// 				ra++;
	// 		// else if (ps->stack_b[i] < ps->stack_a[ps->a_len - 1] && ps->stack_a[0] > ps->stack_b[i])
	// 		// 	while (ps->stack_b[i] < ps->stack_a[ps->a_len - 1 - rra++])

	// 		if (ps->stack_a[ps->a_len - 1] > ps->stack_b[0])



	// 		price = price_b + ra + rra;
	// 		printf ("price %i\n", price);

	// 		if (price < min_price)
	// 		{
	// 			min_price = price;
	// 			min_price_ra = ra;
	// 			min_price_rra = rra;
	// 			min_price_b = price_b;
	// 		}
	// 		i++;
	// 		ra = 0;
	// 		rra = 0;
	// 	}

	// 	pa(ps);
	// }
	// print_stack(ps);
	// return ;

	// while (ps->b_len != 0)
	// {
	// 	print_stack(ps);
	// 	min_price = ps->arrsize;
	// 	price = 0;
	// 	while (i < ps->b_len)
	// 	{
	// 		while (ps->stack_b[i] > ps->stack_a[j])
	// 			j++;
	// 		if (ps->stack_b[i] < ps->stack_a[ps->a_len - 1] && ps->stack_a[0] > ps->stack_b[i])
	// 			while (ps->stack_b[i] < ps->stack_a[ps->a_len - 1 - k])
	// 				k++;
	// 		printf("k = %i\n", k);
	// 		price = i + j + k;
	// 		if (price < min_price)
	// 		{
	// 			min_price = price;

	// 			min_price_a = j;
	// 			rev_a = k;

	// 			min_price_b = i;
	// 			if (min_price_b >= ps->b_len / 2)
	// 			{
	// 				min_price_b = ps->b_len - (ps->b_len - i);
	// 			}
	// 			printf ("min_price_a %i\n", min_price_a);
	// 			printf ("min_price_b %i\n", min_price_b);
	// 		}
	// 		j = 0;
	// 		k = 0;
	// 		i++;
	// 	}
	// 	while (rev_a > 0)
	// 	{
	// 		rev_a--;
	// 		rra(ps);
	// 	}
	// 	while (min_price_a > 0)
	// 	{
	// 		min_price_a--;
	// 		ra(ps);
	// 	}
	// 	if (i >= ps->b_len / 2)
	// 	{
	// 		while (min_price_b > 0)
	// 		{
	// 			min_price_b--;
	// 			rrb(ps);
	// 		}
	// 	}
	// 	else if (i < ps->b_len / 2)
	// 	{	
	// 		while (min_price_b > 0)
	// 		{
	// 			min_price_b--;
	// 			rb(ps);
	// 		}
	// 	}
	// 	pa(ps);
	// 	i = 0;

	// }
	// // while (ft_sorted(ps) != 1)
	// 	// ra(ps);
	// print_stack(ps);

}

void	ft_algoritm(t_ps *ps)
{
	// if (ps->a_len == 2)
	// 	ft_algoritm_2(ps);
	// else if (ps->a_len == 3)
	// 	ft_algoritm_3(ps);
	// else if (ps->a_len == 4)
	// 	ft_algoritm_4(ps);
	// else if (ps->a_len == 5)
	// 	ft_algoritm_5(ps);
	// else if (ps->a_len <= 100)
	// 	ft_algoritm_100(ps);
//
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
