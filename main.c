/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:44 by scambier          #+#    #+#             */
/*   Updated: 2024/01/23 13:43:20 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "libft.h"
#include "t_stack.h"

t_stack	*stack_argv(int argc, char **argv)
{
	t_stack	*s;
	int		tp;

	s = new_stack(argc - 1);
	while (--argc > 0)
	{
		if (!ft_atoi_strict(&tp, argv[argc]))
		{
			free_stack(&s);
			break ;
		}
		push_stack(s, tp);
	}
	return (s);
}

void	sort_two(t_stack *a)
{
	if (top_stack(a, 1) < top_stack(a, 0))
		sa(a, 0, 1);
}

void	sort_three(t_stack *a)
{
	int	m;

	m = find_min(a);
	if (m == 0)
		ra(a, 0, 1);
	else if (m == 1)
		rra(a, 0, 1);
	if (top_stack(a, 1) < top_stack(a, 0))
		sa(a, 0, 1);
	rra(a, 0, 1);
}

int	main(int argc, char **argv)
{ 
	t_stack	*a;

	if (argc == 1)
		return (0);
	if (argc == 2)
		a = read_stack(argv[1]);
	else
		a = stack_argv(argc, argv);
	if (!a || has_dup(a) || ft_strlen(argv[1]) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&a);
		return (0);
	}
	if (!is_ordered(a))
	{
		if (a->size < 3)
			sort_two(a);
		else if (a->size < 4)
			sort_three(a);
		else
			mekherbo_sort(a);
	}
	free_stack(&a);
}
