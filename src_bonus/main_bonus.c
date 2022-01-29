/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:55:50 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/29 21:06:19 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(t_ps *ps)
{
	ft_putstr("Error\n");
	fin_free(ps);
	exit(0);
}

void	checker_2(t_ps *ps, char *line)
{
	if (ft_strcmp_n(line, "ra\n") == 0)
		ra_b(ps);
	else if (ft_strcmp_n(line, "rb\n") == 0)
		rb_b(ps);
	else if (ft_strcmp_n(line, "rr\n") == 0)
		rr_b(ps);
	else if (ft_strcmp_n(line, "rra\n") == 0)
		rra_b(ps);
	else if (ft_strcmp_n(line, "rrb\n") == 0)
		rrb_b(ps);
	else if (ft_strcmp_n(line, "rrr\n") == 0)
		rrr_b(ps);
	else if (ft_strcmp_n(line, "sa\n") == 0)
		sa_b(ps);
	else if (ft_strcmp_n(line, "sb\n") == 0)
		sb_b(ps);
	else if (ft_strcmp_n(line, "ss\n") == 0)
		ss_b(ps);
	else if (ft_strcmp_n(line, "pa\n") == 0)
		pa_b(ps);
	else if (ft_strcmp_n(line, "pb\n") == 0)
		pb_b(ps);
	else
		checker_error(ps, line);
}

void	checker(t_ps *ps)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		checker_2(ps, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (ft_sorted(ps) != 1 || ps->b_len != 0)
		ft_putstr("KO\n");
	else if (ft_sorted(ps) == 1 && ps->b_len == 0)
		ft_putstr("OK\n");
}

void	ikuzoo(int argc, char **argv, int i, t_ps *ps)
{
	while (i < argc)
	{
		if (ft_correct(argv[i]) == 1 && ft_atoi(argv[i]) >= -2147483648
			&& ft_atoi(argv[i]) <= 2147483647 && ft_strcmp(argv[i], "") != 0)
			ps->stack_a[i - 1] = ft_atoi(argv[i]);
		else
			ft_error(ps);
		i++;
	}
	if (ft_dup(ps->stack_a, ps->a_len) == 1)
		checker(ps);
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
