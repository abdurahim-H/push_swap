/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:29:08 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 10:21:31 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <math.h>

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	introsort_util(int arr[], int *begin, int *end, int depthLimit)
{
	int	size;
	int	*pivot;

	size = end - begin + 1;
	if (size <= 32)
	{
		insertion_sort(begin, size);
		return ;
	}
	if (depthLimit == 0)
	{
		heap_sort(begin, size);
		return ;
	}
	pivot = partition(arr, begin - arr, end - arr) + arr;
	introsort_util(arr, begin, pivot - 1, depthLimit - 1);
	introsort_util(arr, pivot + 1, end, depthLimit - 1);
}

void	introsort(int arr[], int n)
{
	int	depthlimit;

	depthlimit = (int)(2 * log(n) / M_LN2);
	introsort_util(arr, arr, arr + n - 1, depthlimit);
}
