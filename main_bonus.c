/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:04:34 by scambier          #+#    #+#             */
/*   Updated: 2024/01/06 19:26:18 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "t_stack.h"
#include "libft.h"

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

typedef struct s_entry
{
	char	*index;
	int		(*f)(t_stack*, t_stack*, int);
}	t_entry;

int	execute(char *instruction, t_stack *a, t_stack *b, int print)
{
	static t_entry	dict[] = {
		(t_entry){"pa", &pa},
		(t_entry){"pb", &pb},
		(t_entry){"ra", &ra},
		(t_entry){"rb", &rb},
		(t_entry){"rr", &rr},
		(t_entry){"rra", &rra},
		(t_entry){"rrb", &rrb},
		(t_entry){"rrr", &rrr},
		(t_entry){"sa", &sa},
		(t_entry){"sb", &sb},
		(t_entry){"ss", &ss}
	};
	int				k;
	int				cmp;

	k = -1;
	while (++k < 11)
	{
		cmp = ft_strncmp(instruction, dict[k].index, 4);
		if ((cmp == 10 || cmp == 0) && dict[k].f(a, b, print))
			return (1);
	}
	return (0);
}

int	handle_next_line(t_stack *a, t_stack *b)
{
	char	*temp;

	temp = get_next_line(0);
	if (temp && !execute(temp, a, b, 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
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
