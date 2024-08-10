/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:09:33 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/10 10:10:16 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list **a, char swap_type)
{
	int	temp;

	if (!(*a) || ft_lstsize(*a) == 1)
		return ;
	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
	if (swap_type == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	int	temp;

	if (!(*a) || ft_lstsize(*a) == 1 || !(*b) || ft_lstsize(*b) == 1)
		return ;
	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
	temp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = temp;
	write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*node;

	if (!(*b))
		return ;
	temp = *b;
	node = ft_lstnew(temp->value);
	*b = temp->next;
	ft_lstadd_front(a, node);
	free(temp);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*node;

	if (!(*a))
		return ;
	temp = *a;
	node = ft_lstnew(temp->value);
	*a = temp->next;
	ft_lstadd_front(b, node);
	free(temp);
	write(1, "pb\n", 3);
}
