#include "cub3D.h"

int	check_map(t_map *map, char *s, char *s2)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	while (map->content[++i])
	{
		j = -1;
		while (map->content[i][++j])
		{
			if (!ft_strchr(s, map->content[i][j]))
				return (-1);
			if (ft_strchr(s2, map->content[i][j]))
				k++;
		}
	}
	if (k != 1)
		return (-1);
	return (0);
}

int	check_wall(t_map *map, char c)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (map->content[i] && map->content[i + 1])
	{
		s = map->content[i];
		j = 0;
		while (s[j])
		{
			if (s[j] == c && ((!j || s[j - 1] == ' '
						|| !s[j + 1] || s[j + 1] == ' ')
					|| ((size_t)j + 1 > ft_strlen(map->content[i - 1])
						|| map->content[i - 1][j] == ' ')
				|| ((size_t)j + 1 > ft_strlen(map->content[i + 1])
					|| map->content[i + 1][j] == ' ')))
				return (-1);
			j++;
		}	
		i++;
	}
	if (ft_strchr(map->content[i], c) || ft_strchr(map->content[0], c))
		return (-1);
	return (0);
}
