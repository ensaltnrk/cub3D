#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strdup_gnl(const char *s)
{
	int		i;
	int		ls;
	char	*dup;

	i = 0;
	ls = ft_strlen_gnl(s);
	ls++;
	dup = malloc(ls);
	if (!dup)
		return (NULL);
	while (ls > 0)
	{
		dup[i] = s[i];
		i++;
		ls--;
	}
	return (dup);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)s + ft_strlen_gnl(s));
	while (s[i] != 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	length;

	if (s == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen_gnl(s);
	if (start >= length || !s)
		len = 0;
	else if (length < (start + len))
		len = length - start;
	dest = malloc(len + 1);
	if (dest != NULL)
	{
		while (i < len && s[i])
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = 0;
	}
	return (dest);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s1[++i] != 0)
		dest[i] = s1[i];
	while (s2[j] != 0)
	{
		dest[i + j] = s2[j];
		j++;
	}
	free(s1);
	dest[i + j] = 0;
	return (dest);
}
