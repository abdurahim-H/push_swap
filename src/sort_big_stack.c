/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:30:01 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 07:30:04 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	sort_big_stack(t_list **a, t_list **b, int size)
// {
// 	int	i;
// 	int	j;
// 	int	num;
// 	int	max_num;
// 	int	max_bits;

// 	max_num = size - 1;
// 	max_bits = 0;
// 	while ((max_num >> max_bits) != 0)
// 		max_bits++;
// 	i = -1;
// 	while (++i < max_bits)
// 	{
// 		j = -1;
// 		while (++j < size)
// 		{
// 			num = (*a)->order;
// 			if (((num >> i) & 1) == 1)
// 				ra(a, 1);
// 			else
// 				pb(a, b, 1);
// 		}
// 		while (*b)
// 			pa(a, b, 1);
// 	}
// }

int	calculate_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	process_bit(t_list **a, t_list **b, int size, int bit)
{
	int	j;
	int	num;

	j = 0;
	while (j < size)
	{
		num = (*a)->order;
		if (((num >> bit) & 1) == 1)
			ra(a, 1);
		else
			pb(a, b, 1);
		j++;
	}
	while (*b)
		pa(a, b, 1);
}

void	sort_big_stack(t_list **a, t_list **b, int size)
{
	int	max_bits;
	int	i;

	max_bits = calculate_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		process_bit(a, b, size, i);
		i++;
	}
}
