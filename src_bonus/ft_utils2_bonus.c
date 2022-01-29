/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:49:40 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/29 21:04:52 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp_n(const char *s1, const char *s2)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	unsigned int	i;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	i = 0;
	while (buf1[i] != '\n' || buf2[i] != '\n')
	{
		if (buf1[i] != buf2[i])
			return (buf1[i] - buf2[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	unsigned int	i;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	i = 0;
	while (buf1[i] || buf2[i])
	{
		if (buf1[i] != buf2[i])
			return (buf1[i] - buf2[i]);
		i++;
	}
	return (0);
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

void	fin_free(t_ps *ps)
{
	free(ps->stack_a);
	free(ps->stack_b);
	free(ps->index);
	free(ps);
}

void	checker_error(t_ps *ps, char *line)
{
	free(line);
	ft_error(ps);
}
