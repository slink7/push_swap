/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:44 by scambier          #+#    #+#             */
/*   Updated: 2023/12/07 03:49:24 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "libft.h"

static int	ft_strarrfree(char **array)
{
	int	k;

	k = 0;
	while (array[k])
		free(array[k++]);
	free(array);
	return (1);
}

typedef struct t_stack
{
	int	*content;
	int	height;
	int	size;
}	t_stack;

t_stack	*new_stack(int size)
{
	t_stack	*out;

	out = malloc(sizeof(t_stack));
	if (!out)
		return (0);
	out->size = size;
	out->content = malloc(out->size * sizeof(int));
	if (!out->content)
	{
		free(out);
		return (0);
	}
	out->height = 0;
	return (out);
}

void	free_stack(t_stack **s)
{
	if (!s || !*s)
		return ;
	free((*s)->content);
	free(*s);
	*s = 0;
}

int	ft_strarrlen(char **ptr)
{
	int	k;

	k = 0;
	while (*ptr++)
		k++;
	return (k);
}

void	push_stack(t_stack *s, int k)
{
	if (s->height >= s->size)
		return ;
	s->content[s->height++] = k;
}

// int	pop_stack(t_stack *s)
// {
// 	if (s->height < 1)
// 		return (-0x80000000);
// 	return (s->content[s->height--] = 0);
// }

t_stack	*get_stack(char *str)
{
	char	**w;
	t_stack	*out;
	int		k;

	if (!str)
		return (0);
	w = ft_split(str, ' ');
	out = new_stack(ft_strarrlen(w));
	if (!out)
		return (0);
	k = out->size;
	while (--k >= 0)
		push_stack(out, ft_atoi(w[k]));
	ft_strarrfree(w);
	return (out);
}

int	main(int argc, char **argv)
{
	t_stack *s;

	s = get_stack(argv[1]);
	if (!s)
		return (0);
	for(int k = 0; k < s->size; k++)
		printf("[%d]", s->content[k]);
	free_stack(&s);
}