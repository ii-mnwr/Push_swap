/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:18:40 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/08 12:06:53 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	valid_args(char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '\0')
			return (0);
		while (args[i][j] && args[i][j] == ' ')
		{
			if (args[i][j + 1] == '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	found_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int	main(int counts, char **args)
{
	t_list	*a;
	t_list	*b;
	t_list	*clone;

	b = NULL;
	if (counts == 1)
		return (0);
	if (args[1] == NULL || !valid_args(args))
		found_error();
	if (!get_list_stack(args, &a))
		return (free_list(a), 0);
	if (!get_list_stack(args, &clone))
		return (free_list(a), free_list(clone), 0);
	if (!(sorted(a)))
	{
		normal_sorting(&clone);
		make_index_value(a, clone);
		sort_stack(&a, &b);
	}
	free_list(clone);
	free_list(a);
	return (0);
}
