/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ordered_pb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:34 by scambier          #+#    #+#             */
/*   Updated: 2024/01/06 20:21:41 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

int	get_target_closest_pb(int k, t_stack *a, t_stack *b)
{
	int	l;
	int	out;

	l = -1;
	out = -1;
	while (++l < b->height)
		if (top_stack(a, k) > top_stack(b, l)
			&& (out == -1 || top_stack(b, l) > top_stack(b, out)))
			out = l;
	return (out);
}

int	get_max(t_stack *a)
{
	int	l;
	int	out;

	l = -1;
	out = 0;
	while (++l < a->height)
		if (top_stack(a, l) > top_stack(a, out))
			out = l;
	return (out);
}

int	get_target_pb(int k, t_stack *a, t_stack *b)
{
	return (get_target_closest_pb(k, a, b));
}

int	get_lowest_cost_pb(t_stack *a, t_stack *b)
{
	int	lowest;
	int	k;
	int	out;
	int	cost;

	k = -1;
	lowest = 0;
	out = 0;
	while (++k < a->height)
	{
		cost = mega_putup_cost(k, get_target_pb(k, a, b), a, b);
		if (cost < lowest)
		{
			lowest = cost;
			out = k;
		}
	}
	return (out);
}

void	ordered_pb(t_stack *a, t_stack *b)
{
	int	lc_index;
	int	target;

	while (a->height > 3)
	{
		if (b->height < 2)
			pb(a, b, 1);
		else
		{
			lc_index = get_lowest_cost_pb(a, b);
			target = get_target_pb(lc_index, a, b);
			puttops(lc_index, target, a, b);
			pb(a, b, 1);
		}
	}
}
