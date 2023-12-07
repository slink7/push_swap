/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:44 by scambier          #+#    #+#             */
/*   Updated: 2023/12/07 05:14:00 by scambier         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	
	a = stack_argv(argc, argv);
	b = new_stack(a->size);
	
	PRINT_STACK(a);
	PRINT_STACK(b);
	printf("\n");
	
	swap_stack(a);

	PRINT_STACK(a);
	PRINT_STACK(b);
	printf("\n");
	
	int temp;
	temp = pop_stack(a);
	push_stack(b, temp);
	temp = pop_stack(a);
	push_stack(b, temp);
	temp = pop_stack(a);
	push_stack(b, temp);
	
	PRINT_STACK(a);
	PRINT_STACK(b);
	printf("\n");

	swap_stack(a);

	PRINT_STACK(a);
	PRINT_STACK(b);
	printf("\n");

	temp = pop_stack(b);
	push_stack(a, temp);
	temp = pop_stack(b);
	push_stack(a, temp);
	temp = pop_stack(b);
	push_stack(a, temp);

	PRINT_STACK(a);
	PRINT_STACK(b);
	printf("\n");

	free_stack(&a);
	free_stack(&b);
}
