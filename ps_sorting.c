/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:31:40 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/10 10:09:52 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_num_sort(t_list **a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->value;
	n2 = (*a)->next->value;
	n3 = (*a)->next->next->value;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa_sb(a, 'a');
	else if (n1 > n2 && n2 > n3)
	{
		sa_sb(a, 'a');
		rra_rrb(a, 'a');
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra_rb(a, 'a');
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa_sb(a, 'a');
		ra_rb(a, 'a');
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra_rrb(a, 'a');
}

void	four_num_sort(t_list **a, t_list **b)
{
	int	i;

	i = 4;
	while (i--)
	{
		if ((*a)->value == 0)
		{
			pb(a, b);
			break ;
		}
		else
			ra_rb(a, 'a');
	}
	three_num_sort(a);
	pa(a, b);
}

void	five_num_sort(t_list **a, t_list **b)
{
	int	i;

	i = 5;
	while (i--)
	{
		if ((*a)->value == 0 || (*a)->value == 4)
			pb(a, b);
		else
			ra_rb(a, 'a');
	}
	three_num_sort(a);
	pa(a, b);
	pa(a, b);
	if ((*a)->value == 0)
	{
		sa_sb(a, 'a');
		ra_rb(a, 'a');
	}
	else
		ra_rb(a, 'a');
}

void	num_sort(t_list **a, t_list **b, int size)
{
	int	i;
	int	j;
	int	bits;
	int	shift_and_multiply;

	bits = get_max_value_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			shift_and_multiply = ((*a)->value >> i) & 1;
			if (shift_and_multiply == 1)
				ra_rb(a, 'a');
			else
				pb(a, b);
			j++;
		}
		while (*b != NULL)
			pa(a, b);
		i++;
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sa_sb(a, 'a');
	else if (size == 3)
		three_num_sort(a);
	else if (size == 4)
		four_num_sort(a, b);
	else if (size == 5)
		five_num_sort(a, b);
	else
		num_sort(a, b, size);
}
