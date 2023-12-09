/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:45:13 by scambier          #+#    #+#             */
/*   Updated: 2023/12/09 20:25:20 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

void	run_sort(t_stack *a)
{
	t_stack	*b;
	int		k;
	int		prev;
	int		mode;

	b = new_stack(a->size);
	while (a->height > 3)
		pb(a, b);
	while (1)
	{
		sort_three(a, b);
		PRINT_STACK(a);
		PRINT_STACK(b);
		if (b->height < 1)
			break;
		pa(a, b);
		pa(a, b);
		pa(a, b);
	}
	PRINT_STACK(a);
	PRINT_STACK(b);
	free_stack(&b);
}

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