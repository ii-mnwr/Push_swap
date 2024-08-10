/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:48:47 by mthodi            #+#    #+#             */
/*   Updated: 2024/08/08 12:15:06 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "push_swap_bonus.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, s1));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

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

static	int	ft_exit(char **line)
{
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
		return (ft_exit(line));
	if (s[fd])
		if (verify_new_line(&(s[fd]), line))
			return (1);
	*line = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = NULL;
	return (1);
}
