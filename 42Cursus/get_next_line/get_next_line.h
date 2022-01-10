#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 99
# endif

# define TYPE_NEW_LINE 1
# define TYPE_NULL 0

typedef struct s_length
{
	int		type;
	size_t	len;
}	t_length;

char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_my_strlen(const char *s, t_length *result);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memset(void *b, int c, size_t len);
int			read_data_subsidiary(int fd, char **pending, char **buffer);
char		*read_data(int fd, char **pending, char *buffer);
char		*get_next_line(int fd);

#endif