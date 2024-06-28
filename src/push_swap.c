/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:29:37 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 10:57:51 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_check_and_sort(t_list **a, t_list **b, int *c, int size)
{
	ft_check_error(c, size);
	introsort(c, size);
	if (ft_check_order(a, c, size - 1))
		exit (EXIT_SUCCESS);
	ft_lstorder(a, c);
	if (size <= 5)
		sort_small_stack(a, b, c, size);
	else
		sort_big_stack(a, b, size);
}

void	ft_init(int argc, char **argv, int i, int len)
{
	t_list	*a;
	t_list	*b;
	t_list	*new;
	int		*c;
	int		j;

	a = NULL;
	b = NULL;
	if (len != 0)
		c = malloc(sizeof(int) * (argc));
	else
		c = malloc(sizeof(int) * (argc - 1));
	if (c == NULL)
		exit (1);
	j = -1;
	while (i < argc)
	{
		ft_check_digit_error(argv, i);
		c[++j] = atoi(argv[i]);
		new = ft_lstnew(atoi(argv[i]));
		ft_lstadd_back(&a, new);
		i++;
	}
	ft_check_and_sort(&a, &b, c, ft_lstsize(a));
	ft_free(&a, &b, c);
}

void	free_args(char **args)
{
	int	j;

	j = 0;
	while (args[j])
	{
		free(args[j]);
		j++;
	}
	free(args);
}

// int	handle_argc_two(char **argv, char ***args, int *argc, int *i)
// {
// 	int	len;

// 	*args = ft_split(argv[1], ' ');
// 	if (!(*args))
// 		return (1);
// 	len = 0;
// 	while ((*args)[len])
// 		len++;
// 	*argc = len + 1;
// 	*i = 0;
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	char	**args;
// 	int		len;
// 	int		i;

// 	if (argc < 2)
// 		return (0);
// 	args = argv;
// 	len = 0;
// 	i = 1;
// 	if (argc == 2)
// 	{
// 		if (handle_argc_two(argv, &args, &argc, &i))
// 			return (1);
// 	}
// 	ft_init(argc, args, i, len);
// 	if (argc == 2)
// 		free_args(args);
// 	return (0);
// }
