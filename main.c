/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:44 by scambier          #+#    #+#             */
/*   Updated: 2023/12/09 15:06:45 by scambier         ###   ########.fr       */
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

// void	PRINT_STACK(t_stack *s)
// {
// 	for (int k = 0; k < s->height; k++)
// 		printf("[%d]", s->content[k]);
// 	printf("\n");
// }

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
	gitan_sort(a);
	free_stack(&a);
}
