/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:59:08 by scambier          #+#    #+#             */
/*   Updated: 2024/01/06 18:54:41 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H

# define PRINT_FD 1

typedef struct t_stack
{
	int	*content;
	int	height;
	int	size;
}	t_stack;

//t_stack0.c
t_stack	*new_stack(int size);
int		free_stack(t_stack **s);
t_stack	*read_stack(char *str);
int		top_stack(t_stack *a, int off);

//t_stack1.c
int		push_stack(t_stack *s, int k);
int		pop_stack(t_stack *s);
void	swap_stack(t_stack *s);
void	rotate_stack(t_stack *s);
void	reverse_rotate_stack(t_stack *s);

//t_stack2.c
int		has_dup(t_stack *t);
int		is_ordered(t_stack *t);
int		find_min(t_stack *t);

//ft_swap.c
int		sa(t_stack *a, t_stack *b, int print);
int		sb(t_stack *a, t_stack *b, int print);
int		ss(t_stack *a, t_stack *b, int print);

//ft_push.c
int		pa(t_stack *a, t_stack *b, int print);
int		pb(t_stack *a, t_stack *b, int print);

//ft_rotate.c
int		ra(t_stack *a, t_stack *b, int print);
int		rb(t_stack *a, t_stack *b, int print);
int		rr(t_stack *a, t_stack *b, int print);

//ft_reverse_rotate.c
int		rra(t_stack *a, t_stack *b, int print);
int		rrb(t_stack *a, t_stack *b, int print);
int		rrr(t_stack *a, t_stack *b, int print);

//ft_puttop.c
int		putup_cost(int k, int h);
int		mega_putup_cost(int k, int l, t_stack *a, t_stack *b);
void	puttop_a(int k, t_stack *a);
void	puttop_b(int k, t_stack *b);
void	puttops(int k, int l, t_stack *a, t_stack *b);

//gitan_sort.c
void	gitan_sort(t_stack *a);

//run_sort.c
void	run_sort(t_stack *a);
void	sort_three(t_stack *a);

#endif