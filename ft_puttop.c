/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:23:09 by scambier          #+#    #+#             */
/*   Updated: 2024/01/06 18:44:55 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

int	putup_cost(int k, int h)
{
	if (k <= h / 2)
		return (k);
	return (h - k);
}

int	mega_putup_cost(int k, int l, t_stack *a, t_stack *b)
{
	int	tra;
	int	trb;
	int	m;

	if (k <= a->height / 2 != l <= b->height / 2)
		return (putup_cost(k, a->height) + putup_cost(l, b->height));
	return (ft_max(putup_cost(k, a->height), putup_cost(l, b->height)));
}

void	puttop_a(int k, t_stack *a)
{
	int	l;

	l = -1;
	if (k <= a->height / 2)
		while (++l < k)
			ra(a, 0, 1);
	else
		while (++l < a->height - k)
			rra(a, 0, 1);
}

void	puttop_b(int k, t_stack *b)
{
	int	l;

	l = -1;
	if (k <= b->height / 2)
		while (++l < k)
			rb(0, b, 1);
	else
		while (++l < b->height - k)
			rrb(0, b, 1);
}
void	puttops(int k, int l, t_stack *a, t_stack *b)
{
	int	tra;
	int	trb;
	int	m;

	if (k <= a->height / 2 != l <= b->height / 2)
	{
		puttop_a(k, a);
		puttop_b(k, b);
		return ;
	}
	tra = putup_cost(k, a->height);
	trb = putup_cost(l, b->height);
	m = -1;
	while (++m < ft_min(tra, trb))
	{
		if (k <= a->height / 2)
			rr(a, b, 1);
		else
			rrr(a, b, 1);
	}
	while (++m < ft_max(tra, trb))
	{
		if (ft_max(tra, trb) == tra)
			if (k <= a->height / 2)
				ra(a, b, 1);
			else
				rra(a, b, 1);
		else
			if (l <= b->height / 2)
				rb(a, b, 1);
			else
				rrb(a, b, 1);
	}
}
