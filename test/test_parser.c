#include "libft.h"
#include <stdio.h>
#include "so_long.h"

void display_map(t_data data);

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		dprintf(2, "Error\n");
	else
	{
		data = init_data();
		parser(argv[1], &data);
		if (data.height)
			display_map(data);
		else
			printf("Empty file\n");
	}
}

void display_map(t_data data)
{
	int	i;

	i = -1;
	while (++i < data.height)
		printf("%s\n", data.map[i]);
}
