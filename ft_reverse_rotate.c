/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:26:00 by scambier          #+#    #+#             */
/*   Updated: 2023/12/08 22:42:47 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

void	rra(t_stack *a, t_stack *b)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate_stack(a);
}

void	rrb(t_stack *a, t_stack *b)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_rotate_stack(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_putstr_fd("rrr\n", 1);
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}