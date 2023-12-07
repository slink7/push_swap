/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:59:08 by scambier          #+#    #+#             */
/*   Updated: 2023/12/07 05:03:53 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H

typedef struct t_stack
{
	int	*content;
	int	height;
	int	size;
}	t_stack;

t_stack	*new_stack(int size);
void	free_stack(t_stack **s);
t_stack	*read_stack(char *str);

void	push_stack(t_stack *s, int k);
int		pop_stack(t_stack *s);
void	swap_stack(t_stack *s);
void	rotate_stack(t_stack *s);
void	reverse_rotate_stack(t_stack *s);

#endif