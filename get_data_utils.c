#include "cub3D.h"

int	clear_pixel(char *s)
{
	char	*ss;
	int		c;
	int		i;

	i = 0;
	ss = ft_strtrim(s, " \n\t\v\f\r");
	while (ss && ss[i])
	{
		if (!ft_isdigit(ss[i]))
		{
			free(ss);
			return (-1);
		}
		i++;
	}
	c = ft_atoi(ss);
	free(ss);
	if (c > 255 || c < 0)
		return (-1);
	return (c);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (tmp);
}

char	*real_dir(char *cmp, char *line)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	if (0 != ft_strncmp(cmp, line, ft_strlen(cmp)))
		return (NULL);
	i = ft_strlen(cmp);
	while (line[i] && ft_isspace(line[i]))
		i++;
	tmp = ft_substr(line, i, ft_strlen(&line[i]));
	free(line);
	return (tmp);
}
