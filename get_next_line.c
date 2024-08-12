/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:48:47 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/12 16:11:12 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "push_swap_bonus.h"

static int	verify_new_line(char **stack, char **line)
{
	char		*tmp_stack;
	char		*strchr_stack;
	int			i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
	{
		if (!strchr_stack[i++])
			return (0);
	}
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = *stack;
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

static void	add_heap_to_static(char **s, char *buf)
{
	char		*tmp;

	tmp = *s;
	if (!tmp)
		*s = ft_strdup(buf);
	else
	{
		*s = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
	}
}

static	int	ft_exit(char **line, char **stack)
{
	if (*stack)
	{
		free(*stack);
		*stack = NULL;
	}
	*line = NULL;
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[1024];
	char		heap[BUFFER_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd >= 1024 || (read(fd, s[fd], 0) < 0))
		return (-1);
	ret = read(fd, heap, BUFFER_SIZE);
	while (ret > 0)
	{
		heap[ret] = '\0';
		add_heap_to_static(&s[fd], heap);
		if (verify_new_line(&s[fd], line))
			return (1);
		ret = read(fd, heap, BUFFER_SIZE);
	}
	if (!s[fd] || s[fd][0] == '\0')
		return (ft_exit(line, &s[fd]));
	if (s[fd])
		if (verify_new_line(&(s[fd]), line))
			return (1);
	*line = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = NULL;
	return (1);
}
