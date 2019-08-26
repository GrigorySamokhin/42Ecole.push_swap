/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:16:36 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/26 16:16:48 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*gl(t_list **alst, int fd)
{
	t_list			*tmp;

	tmp = *alst;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(alst, tmp);
	return (tmp);
}

char				*ft_strchrdup(const char *s)
{
	char			*dst;
	size_t			i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0' && s[i] != '\n')
			i++;
		if (!(dst = (char *)malloc(sizeof(s) * (i + 1))))
			return (NULL);
		ft_strncpy(dst, s, i);
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}

char				*ft_ifn(char *list, void *tmp)
{
	if (ft_strchr(list, '\n'))
	{
		tmp = list;
		list = ft_strdup(ft_strchr(tmp, '\n') + 1);
		free(tmp);
	}
	else
		ft_strclr(list);
	return (list);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*alst;
	t_list			*list;
	char			buf[BUFF_SIZE + 1];
	int				read_fd;
	void			*tmp;

	if (fd == -1 || line == NULL || read(fd, buf, 0) < 0 ||
		!(list = gl(&alst, fd)))
		return (-1);
	while ((read_fd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_fd] = '\0';
		tmp = list->content;
		list->content = ft_strjoin(list->content, buf);
		free(tmp);
		if ((ft_strchr(buf, '\n')))
			break ;
	}
	if (read_fd < BUFF_SIZE && ft_strlen(list->content) == 0)
		return (0);
	if (!(*line = ft_strchrdup(list->content)))
		return (-1);
	list->content = ft_ifn(list->content, tmp);
	return (1);
}
