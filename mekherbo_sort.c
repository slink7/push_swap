/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mekherbo_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:52 by scambier          #+#    #+#             */
/*   Updated: 2024/02/19 11:02:38 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

void	fill_stack_b(t_stack *a, t_stack *b)
{
	int	pushed;
	int	stacklen;
	int	lentmp;

	pushed = 0;
	stacklen = a->height;
	lentmp = stacklen;
	while (stacklen > 6 && pushed < lentmp / 2)
	{
		if (top_stack(a, 0) < lentmp / 2)
		{
			pb(a, b, 1);
			pushed++;
		}
		else
			ra(a, b, 1);
		stacklen--;
	}
	while (lentmp - pushed > 3 && !is_ordered(a))
	{
		pb(a, b, 1);
		pushed++;
	}
}

void	make_move(t_stack *a, t_stack *b, int ia, int ib)
{
	int	k;

	k = -1;
	if (ia <= a->height / 2)
		while (++k < ia)
			ra(a, b, 1);
	else
		while (++k < a->height - ia)
			rra(a, b, 1);
	k = -1;
	if (ib <= b->height / 2)
		while (++k < ib)
			rb(a, b, 1);
	else
		while (++k < b->height - ib)
			rrb(a, b, 1);
	pa(a, b, 1);
}

int	get_min_index(t_stack *a)
{
	int	k;
	int	out;
	int	min;

	k = -1;
	out = -1;
	min = 0x7FFFFFFF;
	while (++k < a->height)
		if (top_stack(a, k) < min)
			double_set(&out, k, &min, top_stack(a, k));
	return (out);
}

void	put_min_top(t_stack *a)
{
	int	i;
	int	k;

	i = get_min_index(a);
	k = -1;
	if (i <= a->height / 2)
		while (++k < i)
			ra(a, 0, 1);
	else
		while (++k < a->height - i)
			rra(a, 0, 1);
}

void	mekherbo_sort(t_stack *a)
{
	t_stack	*b;
	int		lowcost;

	b = new_stack(a->size);
	fill_stack_b(a, b);
	sort_three(a);
	while (b->height > 0)
	{
		lowcost = get_target_index(a, b);
		make_move(a, b, find_target(a, top_stack(b, lowcost)), lowcost);
	}
	put_min_top(a);
	free_stack(&b);
}
