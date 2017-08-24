
#include "../includes/wolf3d.h"

int		wolf_line_checker(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '5')
			i++;
		else
			return(1);
	}
	return (0);	
}

int		parse(t_data *data, char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char 	*temp;

	i = 0;
	
	if (ft_strcmp(filename, ".wolf") == 0)
		err_found("Only .wolf file");
	if (!(fd = open(filename, O_RDONLY)))
		err_found("Unable to read the file");
	if (!get_next_line(fd, &line))
		err_found("get_next_line error");
	data->map_size = ft_strlen(line);
	if(!(data->map = (char **)malloc(sizeof(char*) * (data->map_size + 1))))
		err_found("malloc failure");
	i = 0;
	data->map[i] = ft_strdup(line);
	if(wolf_line_checker(data->map[i]))
		err_found("only ""0"" ""1"" or ""5"", are accepted inside the map");
	temp = NULL;
	if((temp = ft_strchr(data->map[i], '5')))
	{
		data->px = temp - data->map[i];
		data->py = i - 1;
		data->map[i][temp - data->map[i]]= '0';
	}

	free(line);
	i++;
	while (get_next_line(fd, &line))
	{
		if ((int)ft_strlen(line) == data->map_size)
		{
			data->map[i] = ft_strdup(line);
			if(wolf_line_checker(data->map[i]))
				err_found("only ""0"" ""1"" or ""5"", are accepted inside the map");
			temp = NULL;
			if((temp = ft_strchr(data->map[i], '5')))
			{
				data->px = temp - data->map[i];
				data->py = i - 1;
				data->map[i][temp - data->map[i]]= '0';
			}
			free(line);
			i++;
		}
		else
			err_found("map error, the number of arguments in every line is not the same");
	}
	//data->map[i] = 0;
	return (1);
}
