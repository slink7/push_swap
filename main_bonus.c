/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:04:34 by scambier          #+#    #+#             */
/*   Updated: 2024/02/19 14:44:04 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "t_stack.h"
#include "libft.h"

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

t_stack	*stack_argv(int argc, char **argv)
{
	t_stack	*s;
	int		tp;

	s = new_stack(argc - 1);
	while (--argc > 0)
	{
		if (!ft_atoi_strict(&tp, argv[argc]))
		{
			free_stack(&s);
			break ;
		}
		push_stack(s, tp);
	}
	return (s);
}

int	handle_next_line(t_stack *a, t_stack *b)
{
	char	*temp;

	temp = get_next_line(0);
	if (temp && !execute(temp, a, b, 0))
	{
		ft_putstr_fd("Error\n", 2);
		free(temp);
		free_stack(&a);
		free_stack(&b);
		exit(EXIT_FAILURE);
	}
	if (temp)
		free(temp);
	return (temp != 0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 2)
		a = read_stack(argv[1]);
	else
		a = stack_argv(argc, argv);
	if (!a)
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	b = new_stack(a->size);
	while (handle_next_line(a, b))
		;
	if (is_ordered(a) && b->height < 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&a);
	free_stack(&b);
	return (EXIT_SUCCESS);
}
