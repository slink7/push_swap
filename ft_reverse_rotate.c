/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:26:00 by scambier          #+#    #+#             */
/*   Updated: 2024/01/06 18:54:09 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

int	rra(t_stack *a, t_stack *b, int print)
{
	reverse_rotate_stack(a);
	if (print)
		ft_putstr_fd("rra\n", PRINT_FD);
	return (1);
}

int	rrb(t_stack *a, t_stack *b, int print)
{
	reverse_rotate_stack(b);
	if (print)
		ft_putstr_fd("rrb\n", PRINT_FD);
	return (1);
}

int	rrr(t_stack *a, t_stack *b, int print)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (print)
		ft_putstr_fd("rrr\n", PRINT_FD);
	return (1);
}
