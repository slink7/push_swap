/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:26:00 by scambier          #+#    #+#             */
/*   Updated: 2024/01/06 18:51:59 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

int	pa(t_stack *a, t_stack *b, int print)
{
	if (push_stack(a, pop_stack(b)) && print)
		ft_putstr_fd("pa\n", PRINT_FD);
	return (1);
}

int	pb(t_stack *a, t_stack *b, int print)
{
	if (push_stack(b, pop_stack(a)) && print)
		ft_putstr_fd("pb\n", PRINT_FD);
	return (1);
}
