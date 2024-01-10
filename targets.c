/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:14:31 by scambier          #+#    #+#             */
/*   Updated: 2024/01/10 19:21:48 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

void	double_set(int *pa, int va, int *pb, int vb)
{
	*pa = va;
	*pb = vb;
}

int	find_target(t_stack *a, int v)
{
	int	min_max;
	int	out;
	int	k;

	min_max = 0x7FFFFFFF;
	out = -1;
	k = -1;
	while (++k < a->height)
		if (top_stack(a, k) > v && top_stack(a, k) < min_max)
			double_set(&out, k, &min_max, top_stack(a, k));
	if (out != -1)
		return (out);
	min_max = 0x7FFFFFFF;
	k = -1;
	while (++k < a->height)
		if (top_stack(a, k) < min_max)
			double_set(&out, k, &min_max, top_stack(a, k));
	return (out);
}

int	get_cost(t_stack *a, t_stack *b, int ia, int ib)
{
	int	out;

	out = 0;
	if (ia <= a->height / 2)
		out += ia;
	else
		out += a->height - ia;
	if (ib <= b->height / 2)
		out += ib;
	else
		out += b->height - ib;
	return (out);
}

int	get_target_index(t_stack *a, t_stack *b)
{
	int	k;
	int	temp;
	int	min;
	int	out;

	k = -1;
	min = 0x7FFFFFFF;
	out = -1;
	while (++k < b->height)
	{
		temp = find_target(a, top_stack(b, k));
		temp = get_cost(a, b, temp, k);
		if (temp < min)
		{
			min = temp;
			out = k;
		}
	}
	return (out);
}
