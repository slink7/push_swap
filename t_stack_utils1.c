/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:39:35 by scambier          #+#    #+#             */
/*   Updated: 2024/01/10 16:55:11 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

int	push_stack(t_stack *s, int k)
{
	if (s->height >= s->size)
		return (0);
	s->content[s->height++] = k;
	return (1);
}

int	pop_stack(t_stack *s)
{
	if (s->height < 1)
		return (-0x80000000);
	return (s->content[--s->height]);
}

void	swap_stack(t_stack *s)
{
	int	temp;

	if (s->height < 2)
		return ;
	temp = s->content[s->height - 1];
	s->content[s->height - 1] = s->content[s->height - 2];
	s->content[s->height - 2] = temp;
}

void	rotate_stack(t_stack *s)
{
	int	temp;
	int	k;

	if (s->height < 2)
		return ;
	temp = s->content[s->height - 1];
	k = s->height;
	while (--k > 0)
		s->content[k] = s->content[k - 1];
	s->content[0] = temp;
}

void	reverse_rotate_stack(t_stack *s)
{
	int	temp;
	int	k;

	if (s->height < 2)
		return ;
	temp = s->content[0];
	k = -1;
	while (++k < s->height - 1)
		s->content[k] = s->content[k + 1];
	s->content[s->height - 1] = temp;
}
