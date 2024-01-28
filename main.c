#include <libft.h>

typedef struct s_data
{
	char **map;
	int width;
	int height;
}		t_data;

int get_lines_number(char *file);
void get_map(char *file, t_data *data);
void parser(char *file, t_data *data);

int main(int argc, char **argv)
{
	t_data	data;
	int		i;
	(void) argc;

	parser(argv[1], &data);
	i = 0;
	while (i < data.height)
	{
		ft_printf("%s", data.map[i]);
		i++;
	}

	i = -1;
	while (++i < data.height)
		free(data.map[i]);
	free(data.map);
}

void parser(char *file, t_data *data)
{
	 data->height = get_lines_number(file);
	 get_map(file, data);
	 data->width = ft_strlen(data->map[0]);
}

int get_lines_number(char *file)
{
	int fd = open(file, O_RDONLY);
	int counter;
	char *line;

	counter = 0;
	while ((line = get_next_line(fd)))
	{
		free(line);
		counter++;
	}
	close(fd);
	return counter;
}

void get_map(char *file, t_data *data)
{
	int i = 0;
	int fd = open(file, O_RDONLY);

	data->map = (char **) malloc(sizeof(char *) * data->height);
	while (i < data->height)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	i++;
	close(fd);
}
