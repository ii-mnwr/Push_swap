/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:00:59 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/07 09:17:02 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *a)
{
	t_list	*i;
	t_list	*j;

	i = a;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

void	normal_sorting(t_list **list)
{
	t_list	*i;
	t_list	*j;
	int		tmp;

	i = *list;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
			{
				tmp = i->value;
				i->value = j->value;
				j->value = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	make_index_value(t_list *a, t_list *clone)
{
	int		index;
	t_list	*tmp;

	while (a)
	{
		index = 0;
		tmp = clone;
		while (tmp)
		{
			if (a->value == tmp->value)
			{
				a->value = index;
				break ;
			}
			tmp = tmp->next;
			index++;
		}
		a = a->next;
	}
}

int	get_max_value_bits(t_list *a)
{
	t_list	*node;
	int		bits;
	int		max_value;

	node = a;
	bits = 0;
	max_value = node->value;
	while (node)
	{
		if ((node->value) > max_value)
			max_value = node->value;
		node = node->next;
	}
	while (max_value > 0)
	{
		bits++;
		max_value = max_value >> 1;
	}
	return (bits);
}
