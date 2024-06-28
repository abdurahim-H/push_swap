/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:30:15 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 07:30:22 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_3(t_list **a)
{
	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content > (*a)->next->next->content)
		{
			sa(*a, 1);
			rra(a, 1);
		}
		else if ((*a)->content > (*a)->next->next->content)
			ra(a, 1);
		else
			sa(*a, 1);
	}
	else
	{
		if ((*a)->next->content > (*a)->next->next->content)
		{
			sa(*a, 1);
			ra(a, 1);
		}
		else if ((*a)->content > (*a)->next->next->content)
			rra(a, 1);
	}
}

void	ft_find_min(t_list **a, int *c, int order, int arg)
{
	t_list	*lst;
	int		index;

	lst = *a;
	index = 0;
	while (lst->content != c[order])
	{
		lst = lst->next;
		index++;
	}
	if (index > arg / 2)
	{
		while ((*a)->content != c[order])
			rra(a, 1);
	}
	else
	{
		while ((*a)->content != c[order])
			ra(a, 1);
	}
}

void	ft_sort_4(t_list **a, t_list **b, int *c, int arg)
{
	if (!a || !*a || !b)
		return ;
	ft_find_min(a, c, 0, arg);
	pb(a, b, 1);
	ft_sort_3(a);
	pa(a, b, 1);
}

void	ft_sort_5(t_list **a, t_list **b, int *c, int arg)
{
	if (!a || !*a || !b)
		return ;
	ft_find_min(a, c, 0, arg);
	pb(a, b, 1);
	ft_find_min(a, c, 1, arg);
	pb(a, b, 1);
	ft_sort_3(a);
	pa(a, b, 1);
	pa(a, b, 1);
}

void	sort_small_stack(t_list **a, t_list **b, int *c, int arg)
{
	if (arg == 2)
		sa(*a, 1);
	else if (arg == 3)
		ft_sort_3(a);
	else if (arg == 4)
		ft_sort_4(a, b, c, arg);
	else if (arg == 5)
		ft_sort_5(a, b, c, arg);
}
