/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:44 by scambier          #+#    #+#             */
/*   Updated: 2023/12/08 22:45:28 by scambier         ###   ########.fr       */
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

void PRINT_STACK(t_stack *s)
{
	for (int k = 0; k < s->height; k++)
		printf("[%d]", s->content[k]);
	printf("\n");
}

int	has_dup(t_stack *t)
{
	int	k;
	int	l;

	k = -1;
	while (++k < t->height)
	{
		l = -1;
		while (++l < t->height)
			if (t->content[k] == t->content[l] && k != l)
				return (1);
	}
	return (0);
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

void	gitan_sort(t_stack *a)
{
	t_stack *b;

	b = new_stack(a->size);
	while (1)
	{
		if (is_ordered(a) && b->height == 0)
			break ;
		if (a->height < 1 || is_ordered(a))
		{
			while (b->height > 0)
				pa(a, b);
			break ;
		}
		int r = find_min(a);
		for (int k = 0; k < r; k++)
			ra(a, b);
		if (a->height < 1 || is_ordered(a))
		{
			while (b->height > 0)
				pa(a, b);
			break ;
		}
		if (is_ordered(a) && b->height == 0)
			break ;
		pb(a, b);
	}
	free_stack(&b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	
	a = stack_argv(argc, argv);
	if (!a || has_dup(a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&a);
		return (0);
	}	
	//PRINT_STACK(a);
	gitan_sort(a);
	//PRINT_STACK(a);
	free_stack(&a);
}
