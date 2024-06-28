/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:11:06 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 07:11:14 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_lstorder(t_list **a, int *c)
{
	int		i;
	t_list	*lst;

	lst = *a;
	while (lst)
	{
		i = 0;
		while (lst->content != c[i])
			i++;
		lst->order = i;
		lst = lst->next;
	}
}

void	ft_lstclear_2(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	ft_free(t_list **a, t_list **b, int *c)
{
	ft_lstclear_2(a);
	ft_lstclear_2(b);
	free(c);
	c = NULL;
}
