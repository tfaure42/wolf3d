/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:21:29 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/20 15:54:07 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*check_fd(t_list **file, int fd)
{
	t_list		*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static int		read_to_buff(t_list *current)
{
	char	*buff;
	int		ret;
	char	*new_string;

	if (!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	ret = read(current->content_size, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		new_string = ft_strjoin(current->content, buff);
		if (!new_string)
		{
			free(buff);
			return (-1);
		}
		free(current->content);
		current->content = new_string;
	}
	if (ret < 0)
		return (-1);
	new_string = NULL;
	free(buff);
	return (ret);
}

static int		ft_endgnl(t_list *curr, char *index)
{
	index = ft_strdup(index + 1);
	if (index == NULL)
		return (-1);
	if (curr->content)
		free(curr->content);
	curr->content = index;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list		*all;
	int					ret;
	t_list				*curr;
	char				*index;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > FD_MAX)
		return (-1);
	if (!(curr = check_fd(&all, fd)))
		return (-1);
	index = ft_strchr(curr->content, '\n');
	while (index == NULL)
	{
		if ((ret = read_to_buff(curr)) == 0)
		{
			if ((index = ft_strchr(curr->content, '\0')) == curr->content)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			index = ft_strchr(curr->content, '\n');
	}
	if (!(*line = ft_strsub(curr->content, 0, index - (char *)curr->content)))
		return (-1);
	return (ft_endgnl(curr, index));
}
