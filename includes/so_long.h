#ifndef SO_LONG_H
# define SO_LONG_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_data
{
	int height;
	char **map;
}	t_data;


void	parser(char *file, t_data *data);
t_data	init_data();

#endif
