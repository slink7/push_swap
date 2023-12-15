/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:45:13 by scambier          #+#    #+#             */
/*   Updated: 2023/12/15 19:28:57 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

int	max(int a, int b)
{
	return (a > b) * a + (a <= b) * b;
}

int	putup_cost(int k, int h)
{
	if (k <= h / 2)
		return (k);
	return (h - 1 - k);
}

int	has_lower(int k, t_stack *a, t_stack *b)
{
	int	l;

	l = -1;
	while (++l < b->height)
		if (b->content[l] < top_stack(a, k))
			return (1);
	return (0);
}

int	get_target_closest(int k, t_stack *a, t_stack *b)
{
	int	l;
	int	out;

	l = -1;
	out = -1;
	while (++l < b->height)
		if (top_stack(a, k) > top_stack(b, l) && (out == -1 || top_stack(b, l) > top_stack(b, out)))
			out = l;
	return (out);
}

int	get_target_max(int k, t_stack *a, t_stack *b)
{
	int l;
	int	out;

	l = -1;
	out = 0;
	while (++l < b->height)
		if (top_stack(b, l) > top_stack(b, out))
			out = l;
	return (out);
}

int	get_target(int k, t_stack *a, t_stack *b)
{
	if (has_lower(k, a, b))
		return (get_target_closest(k, a, b));
	else
		return (get_target_max(k, a, b));
}

int	get_cost(int k, t_stack *a, t_stack *b)
{
	return (putup_cost(k, a->height) + putup_cost(get_target(k, a, b), b->height));
}

int	get_lowest_cost(t_stack *a, t_stack *b)
{
	int	lowest;
	int	k;
	int	out;

	k = -1;
	lowest = 0;
	out = 0;
	while (++k < a->height)
	{
		if (get_cost(k, a, b) < lowest)
		{
			lowest = get_cost(k, a, b);
			out = k;
		}
	}
	return (out);
}

void	puttop_a(int k, t_stack *a)
{
	int	l;

	l = -1;
	if (k <= a->height / 2)
		while (++l < k)
			ra(a, 0);
	else
		while (++l < a->height - k)
			rra(a, 0);
}

void	puttop_b(int k, t_stack *b)
{
	int	l;

	l = -1;
	if (k <= b->height / 2)
		while (++l < k)
			rb(0, b);
	else
		while (++l < b->height - k)
			rrb(0, b);
}

void	insert_b(t_stack *a, t_stack *b)
{
	int	lowest;
	int	target;

	lowest = get_lowest_cost(a, b);
	target = get_target(lowest, a, b);
	
	PRINT_STACK(a);
	PRINT_STACK(b);
	printf("About to push %d on %d.\n", top_stack(a, lowest), top_stack(b, target));

	puttop_a(lowest, a);
	puttop_b(target, b);
	pb(a, b);
}

void	push_sort(t_stack *a, t_stack *b)
{
	if (b->height < 2)
		pb(a, b);
	else
		insert_b(a, b);
}

void	run_sort(t_stack *a)
{
	t_stack	*b;
	int		k;

	b = new_stack(a->size);
	while (a->height > 3)
		push_sort(a, b);
	sort_three(a);
	PRINT_STACK(a);
	PRINT_STACK(b);
	printf("\n");
	free_stack(&b);
}
/*
int	get_target_max(int a, t_stack *b)
{
	int closest;
	int	k;
	
	closest = 0;
	k = -1;
	while (++k < b->height)
		if (top_stack(b, closest) < top_stack(b, k))
			closest = k;
	return (closest);
}

int get_target_min(int a, t_stack *b)
{
	int closest;
	int	k;
	
	closest = -1;
	k = -1;
	printf("\ngtm\n");
	while (++k < b->height)
		if (a > top_stack(b, k) && top_stack(b, k) > top_stack(b, closest))
			closest = k;
	PRINT_STACK(b);
	printf("Found mind %d %d\n", a, top_stack(b, closest));
	return (closest);
}

int	has_lower(int a, t_stack *b)
{
	int	k;

	k = -1;
	while (++k < b->height)
		if (a > b->content[k])
			return (1);
	return (0);
}

int	get_target(int a, t_stack *b)
{
	
	printf("%d has lower : %d\n", a, has_lower(a, b));
	if (has_lower(a, b))
		return (get_target_min(a, b));
	else
		return (get_target_max(a, b));
}


int	get_cost(int k, int h)
{
	if (k < h / 2)
		return (k);
	return (h - 1 - k);
}

int	get_lowest_cost_index(t_stack *a, t_stack *b)
{
	int	best;
	int	bestk;
	int	temp;
	int	k;

	k = -1;
	best = 0x7FFFFFFF;
	bestk = -1;
	PRINT_STACK(a);
	PRINT_STACK(b);
	while (++k < a->height)
	{
		temp = get_target(top_stack(a, k), b) + get_cost(k, a->height);
		printf(" glci[%d] : %d\n", k, temp);
		if (temp < best)
		{
			best = temp;
			bestk = k;
		}
	}
	return (bestk);
}


void	put_on_top_a(int k, t_stack *a)
{
	if (k < a->height / 2)
		while (k-- > 0)
			rra(a, 0);
	else
		while (k++ < a->height - 1)
			ra(a, 0);
}

void	put_on_top_b(int k, t_stack *b)
{
	if (k < b->height / 2)
		while (k-- >= 0)
			rrb(0, b);
	else
		while (k++ < b->height - 1)
			rb(0, b);
}

void	binsert(t_stack *a, t_stack *b)
{
	int	lc;
	int	target;

	lc = get_lowest_cost_index(a, b);
	target = get_target(top_stack(a, lc), b);
	printf("putting %d on %d\n", top_stack(a, lc), top_stack(b, target));
	put_on_top_a(lc, a);
	put_on_top_b(target, b);
	pb(a, b);
}

void	push_sort(t_stack *a, t_stack* b)
{
	if (b->height < 2)
		pb(a, b);
	else
		binsert(a, b);
}
*/
/*
void	pue_la_merde_sort(t_stack *a)
{
	t_stack	*b;
	int		k;

	b = new_stack(a->size);
	k = -1;
	while (a->height > 0)
	{
		k = a->content[a->height - 1];
		while (b->height > 0 && b->content[b->height - 1] > k)
		{
			pa(a, b);
			sa(a, b);
		}
		pb(a, b);
	}
	while (b->height > 0)
		pa(a, b);
	free_stack(&b);
}
*/