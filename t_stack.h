/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:59:08 by scambier          #+#    #+#             */
/*   Updated: 2023/12/08 22:35:33 by scambier         ###   ########.fr       */
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

void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif