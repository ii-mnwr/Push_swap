/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:11:58 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/06 09:14:30 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	if (!n)
		return (dst);
	if (!src && !dst)
		return (NULL);
	dest2 = dst;
	src2 = (unsigned char *)src;
	while (n != 0)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
		n--;
	}
	return (dst);
}
