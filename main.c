#include "cub3D.h"

void	get_position(t_map *map)
{
	int		i;
	int		k;
	int		t;

	t = 0;
	i = -1;
	while (map->content[++i])
	{
		k = -1;
		while (map->content[i][++k])
		{
			if (ft_strchr("WESN", map->content[i][k]))
			{
				while (map->content[i][k] != "ENWS"[t])
					t++;
				map->ang = t * 90;
				map->content[i][k] = '0';
				map->posy = i;
				map->posx = k;
				return ;
			}
		}
	}
}

int	check_file(char *filename, char *format)
{
	int		len;
	char	*extension;

	len = ft_strlen(filename);
	if (len <= 4)
		return (-1);
	extension = &filename[len - 4];
	if (ft_strncmp(extension, format, ft_strlen(format)))
		return (-1);
	return (0);
}

t_map	*init_map(char *filename)
{
	int		fd;
	t_map	*map;

	if (check_file(filename, ".cub") == -1)
	{
		write(2, "Error\nInvalid file format\n", 27);
		exit(2);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nCouldn't open the file", 29);
		exit(3);
	}
	map = get_map(fd);
	if (map)
		get_position(map);
	return (map);
}

int	main(int ac, char **av)
{
	t_cub	data;
	t_map	*map;

	if (ac != 2)
	{
		write(2, "Error\nInvalid arguments\n", 25);
		return (1);
	}
	map = init_map(av[1]);
	if (map == NULL)
		return (2);
	init_mlx(&data);
	init_process(&data, map);
	init_game(&data, map);
	data.keys = ft_calloc(sizeof(t_keys), 1);
	mlx_events(&data);
	mlx_loop(data.mlx);
	return (0);
}
