/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:31:19 by scambier          #+#    #+#             */
/*   Updated: 2024/01/10 19:07:37 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_stack.h"

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
