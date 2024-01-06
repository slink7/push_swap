#include "t_stack.h"

int	get_target_closest_pa(int k, t_stack *a, t_stack *b)
{
	int	l;
	int	out;

	l = -1;
	out = -1;
	while (++l < a->height)
		if (top_stack(b, k) < top_stack(a, l)
			&& (out == -1 || top_stack(a, l) < top_stack(a, out)))
			out = l;
	return (out);
}

int	get_min(t_stack *a)
{
	int	l;
	int	out;

	l = -1;
	out = 0;
	while (++l < a->height)
		if (top_stack(a, l) < top_stack(a, out))
			out = l;
	return (out);
}

int	get_target_pa(int k, t_stack *a, t_stack *b)
{
	if (has_higher_in_a(k, a, b))
		return (get_target_closest_pa(k, a, b));
	else
		return (get_min(a));
}

int	get_lowest_cost_pa(t_stack *a, t_stack *b)
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
		cost = putup_cost(k, b->height);
		cost += putup_cost(get_target_pa(k, a, b), a->height);
		if (cost < lowest)
		{
			lowest = cost;
			out = k;
		}
	}
	return (out);
}

void	ordered_pa(t_stack *a, t_stack *b)
{
	int	lc_index;
	int	target;

	while (b->height > 0)
	{
		lc_index = 0;
		target = get_target_pa(lc_index, a, b);
		puttop_b(lc_index, b);
		puttop_a(target, a);
		pa(a, b, 1);
	}
}
