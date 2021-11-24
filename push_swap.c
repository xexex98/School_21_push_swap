/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:44 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/24 20:26:55 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*stack(char *argv)
{
	char	*stack_a;

	stack_a = malloc(100);
	if (!stack_a)
		return (NULL);
	stack_a = ft_strjoin(stack_a, argv);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	char	*stack_a;
	int		i;

	i = 0;
	
	while (i < 2)
	{
		stack_a = stack(argv[i]);
		i++;
	}
	// printf("%s",argv[1]);
	printf("%s", stack_a);
	return (0);
}