/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:18:57 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/30 15:38:15 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*big;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	big = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!big)
		return (NULL);
	while (s1[i] != '\0')
	{
		big[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		big[i++] = s2[j++];
	big[i] = '\0';
	return (big);
}

int	ft_atoi(const char *nptr)
{
	long	minus;
	long	i;
	long	num;

	i = 0;
	minus = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + nptr[i++] - '0';
	if (num < 0)
	{
		if (minus == 1)
			return (-1);
		else if (minus == -1)
			return (0);
	}
	return (num * minus);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
	return ;
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (s < d)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	int	*p;
// 	int	*c;
// 	size_t			i;

// 	if (n == 0)
// 		return (dest);
// 	if (!dest && !src)
// 		return (NULL);
// 	p = (int *) dest;
// 	c = (int *) src;
// 	i = 0;
// 	while (i < n)
// 	{
// 		p[i] = c[i];
// 		i++;
// 	}
// 	return (dest);
// }

// int main()
// {
// 	int src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
// 	int src1[1] = {1};
// 	ft_memmove(&src[0], &src1[0], 0);
// 	printf("%i", &src1);
// }