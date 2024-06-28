/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:12:26 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 07:12:32 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_list *a, int i)
{
	int	tmp;
	int	tmp2;

	if (a == NULL || a->next == NULL)
		return ;
	tmp = a->content;
	tmp2 = a->order;
	a->content = a->next->content;
	a->order = a->next->order;
	a->next->content = tmp;
	a->next->order = tmp2;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list *b, int i)
{
	int	tmp;

	if (b == NULL || b->next == NULL)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b, int i)
{
	sa(a, i);
	sb(b, i);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b, int i)
{
	t_list	*lst;

	if (*b == NULL)
		return ;
	lst = *b;
	*b = lst->next;
	lst->next = NULL;
	ft_lstadd_front(a, lst);
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int i)
{
	t_list	*lst;

	if (*a == NULL)
		return ;
	lst = *a;
	*a = lst->next;
	lst->next = NULL;
	ft_lstadd_front(b, lst);
	if (i == 1)
		write(1, "pb\n", 3);
}
