/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:26:00 by scambier          #+#    #+#             */
/*   Updated: 2024/03/09 03:04:39 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

int	sa(t_stack *a, t_stack *b, int print)
{
	(void) b;
	swap_stack(a);
	if (print)
		ft_putstr_fd("sa\n", PRINT_FD);
	return (1);
}

int	sb(t_stack *a, t_stack *b, int print)
{
	(void) a;
	swap_stack(b);
	if (print)
		ft_putstr_fd("sb\n", PRINT_FD);
	return (1);
}

int	ss(t_stack *a, t_stack *b, int print)
{
	swap_stack(a);
	swap_stack(b);
	if (print)
		ft_putstr_fd("ss\n", PRINT_FD);
	return (1);
}
