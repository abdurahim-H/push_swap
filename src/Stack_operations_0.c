/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:11:32 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 07:11:39 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rb(t_list **b, int i)
{
	t_list	*lst;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	lst = *b;
	*b = lst->next;
	lst->next = NULL;
	ft_lstadd_back(b, lst);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int i)
{
	ra(a, i);
	rb(b, i);
	if (i == 1)
		write(1, "rr\n", 3);
}

void	rra(t_list **a, int i)
{
	t_list	*tmp;
	t_list	*lst;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	lst = *a;
	while (lst->next->next != NULL)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	ft_lstadd_front(a, tmp);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int i)
{
	t_list	*tmp;
	t_list	*lst;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	lst = *b;
	while (lst->next->next != NULL)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	ft_lstadd_front(b, tmp);
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int i)
{
	rra(a, i);
	rrb(b, i);
	if (i == 1)
		write(1, "rrr\n", 4);
}
