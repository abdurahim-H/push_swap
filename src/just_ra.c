/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:29:26 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 07:29:30 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_list **a, int i)
{
	t_list	*lst;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	lst = *a;
	*a = lst->next;
	lst->next = NULL;
	ft_lstadd_back(a, lst);
	if (i == 1)
		write(1, "ra\n", 3);
}
