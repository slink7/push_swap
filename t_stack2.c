/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:41:19 by scambier          #+#    #+#             */
/*   Updated: 2023/12/19 16:20:01 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

int	has_dup(t_stack *t)
{
	int	k;
	int	l;

	k = -1;
	while (++k < t->height)
	{
		l = -1;
		while (++l < t->height)
			if (t->content[k] == t->content[l] && k != l)
				return (1);
	}
	return (0);
}

int	is_ordered(t_stack *t)
{
	int	k;

	k = -1;
	while (++k < t->height - 1)
		if (t->content[k] < t->content[k + 1])
			return (0);
	return (1);
}

int	find_min(t_stack *t)
{
	int	k;
	int	min;

	k = -1;
	min = 0;
	while (++k < t->height)
		if (t->content[min] > t->content[k])
			min = k;
	return (t->height - min - 1);
}

int	top_stack(t_stack *a, int off)
{
	return (a->content[a->height - 1 - off]);
}
