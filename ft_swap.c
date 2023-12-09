/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:26:00 by scambier          #+#    #+#             */
/*   Updated: 2023/12/09 14:34:04 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

void	sa(t_stack *a, t_stack *b)
{
	ft_putstr_fd("sa\n", 1);
	swap_stack(a);
}

void	sb(t_stack *a, t_stack *b)
{
	ft_putstr_fd("sb\n", 1);
	swap_stack(b);
}

void	ss(t_stack *a, t_stack *b)
{
	ft_putstr_fd("ss\n", 1);
	swap_stack(a);
	swap_stack(b);
}
