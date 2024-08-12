/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:24:28 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/12 16:11:45 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"
#include "push_swap.h"

static int	do_commands3(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "rra")))
	{
		rra_rrb(stack_a, 'a', 0);
		return (0);
	}
	if (!(ft_strcmp(line, "rrb")))
	{
		rra_rrb(stack_b, 'b', 0);
		return (0);
	}
	if (!(ft_strcmp(line, "rrr")))
	{
		rrr(stack_a, stack_b);
		return (0);
	}
	return (1);
}

static int	do_commands2(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "pb")))
	{
		pb(stack_a, stack_b, 0);
		return (0);
	}
	if (!(ft_strcmp(line, "ra")))
	{
		ra_rb(stack_a, 'a', 0);
		return (0);
	}
	if (!(ft_strcmp(line, "rb")))
	{
		ra_rb(stack_b, 'b', 0);
		return (0);
	}
	if (!(ft_strcmp(line, "rr")))
	{
		rr(stack_a, stack_b);
		return (0);
	}
	return (do_commands3(line, stack_a, stack_b));
}

int	do_commands(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "sa")))
	{
		sa_sb(stack_a, 'a', 0);
		return (0);
	}
	if (!(ft_strcmp(line, "sb")))
	{
		sa_sb(stack_b, 'b', 0);
		return (0);
	}
	if (!(ft_strcmp(line, "ss")))
	{
		ss(stack_a, stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "pa")))
	{
		pa(stack_a, stack_b, 0);
		return (0);
	}
	return (do_commands2(line, stack_a, stack_b));
}

void	print_checker_res(t_list **stack_a, t_list **stack_b)
{
	if (sorted(*stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	if (*stack_a)
		free_list(*stack_a);
	if (*stack_b)
		free_list(*stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	get_list_stack(argv, stack_a);
	while (get_next_line(0, &line))
	{
		if (do_commands(line, stack_a, stack_b))
		{
			free(line);
			found_error();
			return (-1);
		}
		free(line);
	}
	print_checker_res(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
