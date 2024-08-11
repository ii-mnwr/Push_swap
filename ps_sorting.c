/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:31:40 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/11 16:25:55 by mthodi           ###   ########.fr       */
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
		sa_sb(a, 'a', 1);
	else if (n1 > n2 && n2 > n3)
	{
		sa_sb(a, 'a', 1);
		rra_rrb(a, 'a', 1);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra_rb(a, 'a', 1);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa_sb(a, 'a', 1);
		ra_rb(a, 'a', 1);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra_rrb(a, 'a', 1);
}

void	four_num_sort(t_list **a, t_list **b)
{
	int	i;

	i = 4;
	while (i--)
	{
		if ((*a)->value == 0)
		{
			pb(a, b, 1);
			break ;
		}
		else
			ra_rb(a, 'a', 1);
	}
	three_num_sort(a);
	pa(a, b, 1);
}

void	five_num_sort(t_list **a, t_list **b)
{
	int	i;

	i = 5;
	while (i--)
	{
		if ((*a)->value == 0 || (*a)->value == 4)
			pb(a, b, 1);
		else
			ra_rb(a, 'a', 1);
	}
	three_num_sort(a);
	pa(a, b, 1);
	pa(a, b, 1);
	if ((*a)->value == 0)
	{
		sa_sb(a, 'a', 1);
		ra_rb(a, 'a', 1);
	}
	else
		ra_rb(a, 'a', 1);
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
				ra_rb(a, 'a', 1);
			else
				pb(a, b, 1);
			j++;
		}
		while (*b != NULL)
			pa(a, b, 1);
		i++;
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sa_sb(a, 'a', 1);
	else if (size == 3)
		three_num_sort(a);
	else if (size == 4)
		four_num_sort(a, b);
	else if (size == 5)
		five_num_sort(a, b);
	else
		num_sort(a, b, size);
}
