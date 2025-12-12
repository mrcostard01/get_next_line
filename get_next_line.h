#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char *get_next_line(int fd);
int ft_strlen(const char *s);
char *ft_strjoin(char *s1, char *s2, int bytes);
char	*ft_strchr(const char *string, int searchedChar);
char     *get_read(char *str, int fd);
char *get_one_line(char *p);
char *get_line_after(char *p);
char *ft_freejoin(char *p, char *res, int bytes);
void	*ft_calloc(size_t elementCount, size_t elementSize);
#endif