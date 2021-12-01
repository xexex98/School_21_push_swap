/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:44 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/01 21:24:11 by mbarra           ###   ########.fr       */
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

void	ft_init_struct(t_ps *ps, int argc)
{
	ps->a_len = (argc - 1);
	ps->b_len = 0;
	ps->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	ps->stack_b = (int *)malloc(sizeof(int) * (argc - 1));
}

void	ft_algoritm(t_ps *ps)
{
	if (ps->a_len == 2)
		ft_algoritm_2(ps);	
	else if (ps->a_len <= 3)
		ft_algoritm_3(ps);
	else if (ps->a_len <= 5)
		ft_algoritm_5(ps);
}
void	ft_algoritm_2(t_ps *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1])
		sa(ps);
}

void	ft_algoritm_3(t_ps *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
		sa(ps);
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2])
	{
		sa(ps);
		rra(ps);
	}
	else if (ps->stack_a[1] < ps->stack_a[0] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
		ra(ps);
	else if (ps->stack_a[1] > ps->stack_a[0] && ps->stack_a[1] > ps->stack_a[2])
	{	
		sa(ps);
		ra(ps);
	}
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2])
		rra(ps);
}

void	ft_algoritm_5(t_ps *ps)
{
	return ;
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
	ft_init_struct(ps, argc);
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
				return (0);
			i++;
		}
		if (ft_dup(ps->stack_a, ps->a_len) == 1)
		{
			ft_algoritm(ps);
			// printf("OK");
		}
		else
			ft_putstr("Error\n");
	}
	i = 0;
	pb(ps);
	pb(ps);
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
	return (0);
}
