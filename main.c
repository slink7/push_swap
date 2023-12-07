/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:44 by scambier          #+#    #+#             */
/*   Updated: 2023/12/07 04:19:08 by scambier         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack *s;
	int		tp;

	s = new_stack(argc - 1);
	while (--argc > 0)
	{
		if (!ft_atoi_strict(&tp, argv[argc]))
		{
			free_stack(&s);
			write(2, "Error\n", 6);
			return (0);
		}
		push_stack(s, tp);
	}
	for(int k = 0; k < s->size; k++)
		printf("[%d]", s->content[k]);
	free_stack(&s);
}