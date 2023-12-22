/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:44 by scambier          #+#    #+#             */
/*   Updated: 2023/12/22 11:24:03 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "libft.h"
#include "t_stack.h"

int	ft_atoi_strict(int *out, char *in)
{
	int	sign;

	*out = 0;
	sign = 1;
	if (*in == '-' && in++)
		sign = -1;
	while (*in)
	{
		if (!ft_isdigit(*in))
			return (0);
		*out = *out * 10 + *in - '0';
		in++;
	}
	*out *= sign;
	return (1);
}

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

void	PRINT_STACK(t_stack *s)
{
	int	c;
	int	prev;

	for (int k = 0; k < s->height; k++)
		printf("[%d]", s->content[k]);
	c = 1;
	for (int k = s->height - 2; k >= 0; k--) {
		if (s->content[k] < s->content[k + 1])
			c++;
	}
	printf("(%druns)\n", c);
}

void	sort_two(t_stack *a)
{
	if (top_stack(a, 1) < top_stack(a, 0))
		sa(a, 0);
}

void	sort_three(t_stack *a)
{
	int	m;

	m = find_min(a);
	if (m == 0)
		ra(a, 0);
	else if (m == 1)
		rra(a, 0);
	if (top_stack(a, 1) < top_stack(a, 0))
		sa(a, 0);
	rra(a, 0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 2)
		a = read_stack(argv[1]);
	else
		a = stack_argv(argc, argv);
	if (!a || has_dup(a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&a);
		return (0);
	}
	if (!is_ordered(a) || a->size < 2)
	{
		if (a->size < 3)
			sort_two(a);
		else if (a->size < 4)
			sort_three(a);
		else
			mekherbo_sort(a);
	}
	// printf("Final:");
	// PRINT_STACK(a);
	free_stack(&a);
}
