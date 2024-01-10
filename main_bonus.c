/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:04:34 by scambier          #+#    #+#             */
/*   Updated: 2024/01/10 18:43:35 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "t_stack.h"
#include "libft.h"

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

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

	if (argc != 2)
		return (0);
	a = read_stack(argv[1]);
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
