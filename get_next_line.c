#include "get_next_line.h"

char	*ft_trim(char *str)
{
	char	*dest;

	dest = ft_strchr_gnl(str, '\n');
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup_gnl(dest + 1);
	else
		dest = NULL;
	free(str);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*dest;
	int			size;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = '\0';
	while (size > 0)
	{
		if (!str)
			str = ft_strdup_gnl(buffer);
		else
			str = ft_strjoin_gnl(str, buffer);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	free(buffer);
	dest = ft_substr_gnl(str, 0, ft_strchr_gnl(str, '\n') - str + 1);
	str = ft_trim(str);
	return (dest);
}
