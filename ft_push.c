/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:26:00 by scambier          #+#    #+#             */
/*   Updated: 2023/12/09 20:02:01 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

void	pa(t_stack *a, t_stack *b)
{
	if (push_stack(a, pop_stack(b)))
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	if (push_stack(b, pop_stack(a)))
		ft_putstr_fd("pb\n", 1);
}
