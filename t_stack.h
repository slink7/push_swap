/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:59:08 by scambier          #+#    #+#             */
/*   Updated: 2023/12/09 15:11:45 by scambier         ###   ########.fr       */
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

//t_stack0.c
t_stack	*new_stack(int size);
void	free_stack(t_stack **s);
t_stack	*read_stack(char *str);

//t_stack1.c
void	push_stack(t_stack *s, int k);
int		pop_stack(t_stack *s);
void	swap_stack(t_stack *s);
void	rotate_stack(t_stack *s);
void	reverse_rotate_stack(t_stack *s);

//t_stack2.c
int		has_dup(t_stack *t);
int		is_ordered(t_stack *t);
int		find_min(t_stack *t);

//ft_swap.c
void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);

//ft_push.c
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

//ft_rotate.c
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);

//ft_reverse_rotate.c
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//gitan_sort.c
void	gitan_sort(t_stack *a);

#endif