/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:10:45 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 08:38:58 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_order(t_list **a, int *c, int size)
{
	t_list		*lst;
	int			i;

	if (!a || !*a || !c)
		return (0);
	lst = *a;
	i = 0;
	while (i < size)
	{
		if (!lst || lst->content != c[i])
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

int	int_cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void	add_to_table(t_hash_table **htable, int key)
{
	t_hash_table	*item;

	item = (t_hash_table *)malloc(sizeof(t_hash_table));
	if (!item)
	{
		HASH_CLEAR(hh, *htable);
		ft_error("Memory allocation failed\n");
	}
	item->key = key;
	HASH_ADD_INT(*htable, key, item);
}

void	ft_check_error(int *c, int size)
{
	t_hash_table	*htable;
	t_hash_table	*item;
	int				i;

	htable = NULL;
	i = -1;
	while (++i < size)
	{
		item = NULL;
		HASH_FIND_INT(htable, &c[i], item);
		if (item)
		{
			HASH_CLEAR(hh, htable);
			ft_error("Duplicate found\n");
		}
		else
			add_to_table(&htable, c[i]);
	}
	HASH_CLEAR(hh, htable);
}

void	ft_check_digit_error(char **argv, int i)
{
	char	*endptr;
	long	val;

	if (!argv || !argv[i])
		ft_error("Null pointer passed to ft_check_digit_error");
	errno = 0;
	val = strtol(argv[i], &endptr, 10);
	if (val > INT_MAX || val < INT_MIN)
		ft_error("Integer overflow or underflow");
	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
		|| (errno != 0 && val == 0))
		ft_error("Numeric range error or invalid number");
	if (endptr == argv[i] || *endptr != '\0')
		ft_error("Non-numeric characters found");
	if (argv[i][0] == '-' && argv[i][1] == '\0')
		ft_error("Lone minus sign found");
}
