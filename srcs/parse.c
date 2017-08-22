/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:16:57 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/22 15:08:25 by ocojeda-         ###   ########.fr       */
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
	free(line);
	if (ft_strcmp(map[0], "mapsize") == 0)
	{
		data->map_size = ft_atoi(map[1]);
		free_splited_str(map);
		data->map = (char **)malloc(sizeof(char*) * (data->map_size));
		i = 0;
		while (get_next_line(fd, &line))
			if ((int)ft_strlen(line) == data->map_size)
				{
					data->map[i] = ft_strdup(line);
					if(ft_strchr(data->map[i], '5'))
					{
						data->px = ft_strchr(data->map[i], '5') - data->map[i];
						data->py = i;
					}
					free(line);
					i++;
				}
			else
				err_found("bad align in the map\nplease check if the number you've set as mapsize is correct or if there is a number missing in the map");
			data->map[i] = 0;
			printf("x = %f et y = %f \n", data->px, data->py);
			//ceci est la modif
	}
	else
		err_found("mapsize needed before the map");
	return(1);
}
