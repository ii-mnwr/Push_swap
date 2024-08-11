/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:17:05 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/11 16:24:14 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

void	sa_sb(t_list **a, char swap_type, int flag);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b, int flag);
void	pb(t_list **a, t_list **b, int flag);
void	ra_rb(t_list **a, char swap_type, int flag);
void	rr(t_list **a, t_list **b);
void	rra_rrb(t_list **a, char swap_type, int flag);
void	rrr(t_list **a, t_list **b);

void	three_num_sort(t_list **a);
void	four_num_sort(t_list **a, t_list **b);
void	five_num_sort(t_list **a, t_list **b);
void	num_sort(t_list **a, t_list **b, int size);
void	sort_stack(t_list **a, t_list **b);

int		error_zero(int input, char *str);
int		duplicate(int input, t_list *head);
void	free_list(t_list *list);
void	exit_pushswap(t_list *head, char **split);
int		get_list_stack(char **args, t_list **head);
int		sorted(t_list *a);
void	normal_sorting(t_list **list);
void	found_error(void);
void	make_index_value(t_list *a, t_list *clone);
int		get_max_value_bits(t_list *a);

#endif