/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:22:43 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/03 18:08:05 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void qsortRecursive(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];
	// printf("\n%i\n", mid);

    // Делим массив
   while (i <= j)
   {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) 
		{
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) 
		{
            j--;
        }
        //Меняем элементы местами
        if (i <= j) 
		{
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } 
    // // Рекурсивные вызовы, если осталось, что сортировать
    // if(j > 0) {
    //     //"Левый кусок"
    //     qsortRecursive(mas, j + 1);
    // }
    // if (i < size) {
    //     //"Првый кусок"
    //     qsortRecursive(&mas[i], size - i);
    // }
}

int	main(void)
{
	int str[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 14};
	int i = 0;
	int len = 10;
	while (i < len)
		printf("%i ", str[i++]);
	i = 0;
	qsortRecursive(str, len);
	printf("\n");
	while (i < len)
		printf("%i ", str[i++]);
	return (0);
}
