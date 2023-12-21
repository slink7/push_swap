/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:01:00 by scambier          #+#    #+#             */
/*   Updated: 2023/12/19 16:19:29 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "t_stack.h"

static int	ft_strarrfree(char **array)
{
	int	k;

	k = 0;
	while (array[k])
		free(array[k++]);
	free(array);
	return (1);
}

static int	ft_strarrlen(char **ptr)
{
	int	k;

	k = 0;
	while (*ptr++)
		k++;
	return (k);
}

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

int	free_stack(t_stack **s)
{
	if (!s || !*s)
		return (1);
	free((*s)->content);
	free(*s);
	*s = 0;
	return (1);
}

t_stack	*read_stack(char *str)
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
