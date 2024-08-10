/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:20:56 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/07 09:03:23 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_list **a, char swap_type)
{
	t_list	*temp;
	t_list	*last;

	if (!(*a) || ft_lstsize(*a) == 1)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	temp->next = NULL;
	last->next = temp;
	if (swap_type == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*last_a;
	t_list	*temp_b;
	t_list	*last_b;

	if (!(*a) || ft_lstsize(*a) == 1 || !(*b) || ft_lstsize(*b) == 1)
		return ;
	temp_a = *a;
	last_a = ft_lstlast(*a);
	*a = (*a)->next;
	temp_a->next = NULL;
	last_a->next = temp_a;
	temp_b = *b;
	last_b = ft_lstlast(*b);
	*b = (*b)->next;
	temp_b->next = NULL;
	last_b->next = temp_b;
	write(1, "rr\n", 3);
}

void	rra_rrb(t_list **a, char swap_type)
{
	t_list	*temp;
	t_list	*last;

	if (!(*a) || ft_lstsize(*a) == 1)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *a;
	*a = last;
	if (swap_type == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
