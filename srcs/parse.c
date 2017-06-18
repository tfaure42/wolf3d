/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:16:57 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/18 18:25:12 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		parse(t_data *data, char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	if (!(fd = open(filename, O_RDONLY)))
		err_found("file not fond");
	if (!get_next_line(fd, &line))
		err_found("get_next_line error");
	map = ft_strsplit(line, ':');
	if (ft_strcmp(map[0], "mapsize") == 0)
	{	
		data->map_size = ft_atoi(map[1]);
		free_splited_str(map);
		data->map = malloc(sizeof(char*) * data->map_size);
		while (get_next_line(fd, &line))
			if ((int)ft_strlen(line) == data->map_size)
				data->map[i++] = line;
			else
				err_found("bad align in the map\nplease check if the number you've set as mapsize is correct or if there is a number missing in the map");
	}
	else
		err_found("mapsize needed before the map");
	return(1);
}