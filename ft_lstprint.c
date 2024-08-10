/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 06:27:42 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/06 06:28:13 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	i;

	if (n > INT_MAX || n < INT_MIN)
		return ;
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	i = (n % 10) + '0';
	write(1, &i, 1);
}

void	ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	write (1, "Stack = ", 8);
	while (lst)
	{
		ft_putnbr(lst->value);
		lst = lst->next;
		if (lst)
			write (1, " -> ", 4);
	}
	write (1, "\n", 1);
}
