/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:44 by scambier          #+#    #+#             */
/*   Updated: 2023/12/07 15:39:38 by scambier         ###   ########.fr       */
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
			write(2, "Error\n", 6);
			free_stack(&s);
			break ;
		}
		push_stack(s, tp);
	}
	return (s);
}

void PRINT_STACK(t_stack *s)
{
	for (int k = 0; k < s->height; k++)
		printf("[%d]", s->content[k]);
	printf("\n");
}

int	is_ordered(t_stack *t)
{
	int	k;

	k = -1;
	while (++k < t->height - 1)
		if (t->content[k] < t->content[k + 1])
			return (0); 
	return (1);
}

int	find_min(t_stack *t)
{
	int	k;
	int	min;

	k = -1;
	min = 0;
	while (++k < t->height)
		if (t->content[min] > t->content[k])
			min = k;
	return (t->height - min - 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	
	a = stack_argv(argc, argv);
	b = new_stack(a->size);
	
	while (1)
	{
		if (a->height < 1)
		{
			while (b->height > 0)
			{
				write(1, "pa\n", 3);
				push_stack(a, pop_stack(b));
			}
			break ;
		}
		int r = find_min(a);
		for (int k = 0; k < r; k++)
		{
			write(1, "ra\n", 3);
			rotate_stack(a);
		}
		write(1, "pb\n", 3);
		push_stack(b, pop_stack(a));
	}
	free_stack(&a);
	free_stack(&b);
}
