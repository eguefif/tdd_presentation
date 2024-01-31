#include "so_long.h"

t_data	init_data()
{
	t_data retval;

	retval.height = 0;
	retval.map = 0;
	return (retval);
}

void	parser(char *file, t_data *data)
{
	int fd;
	int i;
	char *line;

	fd = open(file, O_RDONLY);

	line = get_next_line(fd);
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	data->map = (char **) malloc(sizeof(char *) * data->height);
	i = 0;
	while (i < data->height)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}
