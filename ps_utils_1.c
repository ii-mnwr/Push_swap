/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:26:24 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/07 09:09:07 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	error_zero(int input, char *str)
{
	int	i;

	i = 0;
	if (input == 0)
	{
		while (str[i])
		{
			if ((str[i] == '-' || str[i] == '+')
				&& (str[i + 1] && str[i + 1] >= '0' && str[i + 1] <= '9'))
				i++;
			while (str[i] == '0')
				i++;
			if (str[i])
				return (1);
		}
		return (0);
	}
	return (0);
}

int	duplicate(int input, t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		if (temp->value == input)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	free_list(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

void	exit_pushswap(t_list *head, char **split)
{
	free_split(split);
	free_list(head);
	ft_putstr("Error\n");
	exit(1);
}

int	get_list_stack(char **args, t_list **head)
{
	t_list	*node;
	char	**tmp_splits;
	int		input;
	int		i;
	int		j;

	i = 0;
	*head = NULL;
	while (args[++i])
	{
		tmp_splits = ft_split(args[i], ' ');
		if (!tmp_splits)
			return (0);
		j = -1;
		while (tmp_splits[++j])
		{
			input = ft_atoi(tmp_splits[j]);
			if (error_zero(input, tmp_splits[j]) || duplicate(input, *head))
				exit_pushswap(*head, tmp_splits);
			node = ft_lstnew(input);
			ft_lstadd_back(head, node);
		}
		free_split(tmp_splits);
	}
	return (1);
}
