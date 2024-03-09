/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:26:00 by scambier          #+#    #+#             */
/*   Updated: 2024/03/09 03:04:55 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

int	ra(t_stack *a, t_stack *b, int print)
{
	(void) b;
	rotate_stack(a);
	if (print)
		ft_putstr_fd("ra\n", PRINT_FD);
	return (1);
}

int	rb(t_stack *a, t_stack *b, int print)
{
	(void) a;
	rotate_stack(b);
	if (print)
		ft_putstr_fd("rb\n", PRINT_FD);
	return (1);
}

int	rr(t_stack *a, t_stack *b, int print)
{
	rotate_stack(a);
	rotate_stack(b);
	if (print)
		ft_putstr_fd("rr\n", PRINT_FD);
	return (1);
}
