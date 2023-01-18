#include "cub3D.h"

int	clear_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
		free(arg[i++]);
	if (arg)
		free(arg);
	return (0);
}

int	clear_map(t_map *map)
{
	if (!map)
		return (1);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->content)
		clear_arg(map->content);
	free(map);
	return (0);
}
