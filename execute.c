/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:31:19 by scambier          #+#    #+#             */
/*   Updated: 2024/02/29 14:53:38 by scambier         ###   ########.fr       */
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
		(t_entry){"pa\n", &pa},
		(t_entry){"pb\n", &pb},
		(t_entry){"ra\n", &ra},
		(t_entry){"rb\n", &rb},
		(t_entry){"rr\n", &rr},
		(t_entry){"rra\n", &rra},
		(t_entry){"rrb\n", &rrb},
		(t_entry){"rrr\n", &rrr},
		(t_entry){"sa\n", &sa},
		(t_entry){"sb\n", &sb},
		(t_entry){"ss\n", &ss}
	};
	int				k;
	int				cmp;

	k = -1;
	while (++k < 11)
	{
		cmp = ft_strncmp(instruction, dict[k].index, ft_strlen(instruction));
		if (cmp == 0 && dict[k].f(a, b, print))
			return (1);
	}
	return (0);
}
