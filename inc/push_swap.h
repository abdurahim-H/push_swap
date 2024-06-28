/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:05:00 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 08:10:07 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <time.h>
# include "../uthash/include/uthash.h"

typedef struct hash_table
{
	int					key;
	UT_hash_handle		hh;
}	t_hash_table;

/*****OPERATIONS*****/
void	sa(t_list *a, int i);
void	sb(t_list *b, int i);
void	ss(t_list *a, t_list *b, int i);
void	ra(t_list **a, int i);
void	rb(t_list **b, int i);
void	rr(t_list **a, t_list **b, int i);
void	rra(t_list **a, int i);
void	rrb(t_list **b, int i);
void	rrr(t_list **a, t_list **b, int i);
void	pa(t_list **a, t_list **b, int i);
void	pb(t_list **a, t_list **b, int i);

/*****FUNCTIONS*****/
void	ft_check_digit_error(char **argv, int i);
void	ft_check_error(int *c, int argc);
int		ft_check_order(t_list **a, int *c, int size);
void	ft_lstorder(t_list **a, int *c);
void	ft_error(const char *error_message);
void	sort_small_stack(t_list **a, t_list **b, int *c, int arg);
void	sort_big_stack(t_list **a, t_list **b, int size);
void	ft_free(t_list **a, t_list **b, int *c);
int		get_next_line(char **line);
int		ft_strcmp(char *s1, char *s2);
void	introsort(int arr[], int n);
void	swap(int *a, int *b);
void	insertion_sort(int arr[], int n);
void	heapify(int arr[], int n, int i);
void	heap_sort(int arr[], int n);

#endif
