/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:26:00 by scambier          #+#    #+#             */
/*   Updated: 2023/12/08 22:43:02 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

void	ra(t_stack *a, t_stack *b)
{
	ft_putstr_fd("ra\n", 1);
	rotate_stack(a);
}

void	rb(t_stack *a, t_stack *b)
{
	ft_putstr_fd("rb\n", 1);
	rotate_stack(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_putstr_fd("rr\n", 1);
	rotate_stack(a);
	rotate_stack(b);
}