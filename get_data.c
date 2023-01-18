#include "cub3D.h"

int	get_map_content(t_map *map, int fd)
{
	char	*s;
	char	*tmp;

	tmp = ft_strdup("");
	s = NULL;
	while (!s)
		if (-1 == get_clear_line(&s, fd, 0))
			return (-1);
	while (s)
	{
		tmp = join_and_free(tmp, s);
		get_clear_line(&s, fd, 0);
	}
	while (!s)
		if (-1 == get_clear_line(&s, fd, 0))
			break ;
	if (s)
	{
		free(s);
		free(tmp);
		return (-1);
	}
	map->content = ft_split(tmp, '\n');
	free(tmp);
	return (0);
}

int	get_clear_line(char **str, int fd, int mode)
{
	int		i;
	char	*s;

	i = -1;
	*str = get_next_line(fd);
	if (!*str)
		return (-1);
	if (mode)
		s = ft_strtrim(*str, " \n\t\v\f\r");
	else
		s = ft_strdup(*str);
	free(*str);
	while (s && s[++i])
	{	
		if (!ft_isspace(s[i]))
		{
			*str = s;
			return (0);
		}
	}
	free(s);
	*str = NULL;
	return (0);
}

int	get_pixel(t_pixel *pixel, char *cmp, char *line)
{
	int		i;
	char	**sp;
	int		f;

	f = -1;
	i = ft_strlen(cmp);
	sp = ft_split(&line[i], ',');
	free(line);
	i = 0;
	while (sp[i])
		i++;
	if (i == 3)
	{
		pixel->r = clear_pixel(sp[0]);
		pixel->g = clear_pixel(sp[1]);
		pixel->b = clear_pixel(sp[2]);
		if (pixel->r >= 0 && pixel->g >= 0 && pixel->b >= 0)
			f = 1;
	}
	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (f);
}

int	get_directories(t_map *map, int fd, char *line)
{
	while ((!map->no || !map->so) || !map->we
		|| !map->ea || !map->f.check || !map->c.check)
	{
		if (-1 == get_clear_line(&line, fd, 1))
			return (-1);
		if (line && !map->no && 0 == ft_strncmp("NO ", line, 3))
			map->no = real_dir("NO ", line);
		else if (line && !map->so && 0 == ft_strncmp("SO ", line, 3))
			map->so = real_dir("SO ", line);
		else if (line && !map->we && 0 == ft_strncmp("WE ", line, 3))
			map->we = real_dir("WE ", line);
		else if (line && !map->ea && 0 == ft_strncmp("EA ", line, 3))
			map->ea = real_dir("EA ", line);
		else if (line && !map->f.check && 0 == ft_strncmp("F ", line, 2))
			map->f.check = get_pixel(&map->f, "F ", line);
		else if (line && !map->c.check && 0 == ft_strncmp("C ", line, 2))
			map->c.check = get_pixel(&map->c, "C ", line);
		else if (line)
		{
			free(line);
			return (-1);
		}
	}
	return (1);
}

t_map	*get_map(int fd)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (get_directories(map, fd, NULL) < 0 || map->c.check == -1
		|| map->f.check == -1)
	{
		write(2, "Error\nInvalid map content\n", 26);
		clear_map(map);
		return (NULL);
	}
	if (get_map_content(map, fd) == -1 || check_map(map, "01NSEW ", "NWES") \
		== -1 || check_wall(map, '0') || check_wall(map, 'N')
		|| check_wall(map, 'S') || check_wall(map, 'W') || check_wall(map, 'E'))
	{
		write(2, "Error\nInvalid map content\n", 26);
		clear_map(map);
		return (NULL);
	}
	return (map);
}
