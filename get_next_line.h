#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(const char *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *s);
size_t	ft_strlen_gnl(const char *s);

#endif
