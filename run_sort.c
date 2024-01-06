/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:45:13 by scambier          #+#    #+#             */
/*   Updated: 2024/01/06 20:19:35 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

int	has_higher_in_a(int k, t_stack *a, t_stack *b)
{
	int	l;

	l = -1;
	while (++l < a->height)
		if (a->content[l] > top_stack(b, k))
			return (1);
	return (0);
}

int	has_lower_in_b(int k, t_stack *a, t_stack *b)
{
	int	l;

	l = -1;
	while (++l < b->height)
		if (b->content[l] < top_stack(a, k))
			return (1);
	return (0);
}

void	run_sort(t_stack *a)
{
	t_stack	*b;
	int		k;

	b = new_stack(a->size);
	ordered_pb(a, b);
	sort_three(a);
	ordered_pa(a, b);
	puttop_a(get_min(a), a);
	free_stack(&b);
}
