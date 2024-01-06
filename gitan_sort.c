/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gitan_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:06:37 by scambier          #+#    #+#             */
/*   Updated: 2024/01/06 18:43:40 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

void	gitan_sort(t_stack *a)
{
	t_stack	*b;
	int		min;
	int		k;

	b = new_stack(a->size);
	while (1)
	{
		if (is_ordered(a) && b->height == 0 || a->height < 1 || is_ordered(a))
			break ;
		min = find_min(a);
		k = -1;
		if (min < (a->height - min))
			while (++k < min)
				ra(a, b, 1);
		else
			while (++k < (a->height - min))
				rra(a, b, 1);
		if (is_ordered(a) && b->height == 0)
			break ;
		pb(a, b, 1);
	}
	while (b->height > 0)
		pa(a, b, 1);
	free_stack(&b);
}
