#include "get_next_line.h"
#include <sys/uio.h>
#include <sys/types.h>
int ft_strlen(const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void *ft_memcpy(void *d, const void *s, size_t n)
{
	size_t i;

	i = 1;
	while (i <= n)
	{
		*(char *)d = *(char *)s;
		d++;
		s++;
		i++;
	}
	d -= i - 1;
	return (d);
}
static char *checkstr(const char *s)
{
	char *newstr;

	newstr = malloc(sizeof(char) * 2);
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s, 2);
	return (newstr);
}

char *ft_strjoin(const char *s1, const char *s2)
{
	char *newstr;
	size_t count;

	count = 0;
	if (s1 == NULL)
		return (checkstr(s2));
	if (s2 == NULL)
		return (checkstr(s1));
	count = (ft_strlen(s1) + ft_strlen(s2)) - 1;
	newstr = malloc(sizeof(char) * (count + 2));
	if (!newstr)
		return (NULL);
	newstr[0] = '\0';
	ft_strlcat(newstr, s1, (count + 2));
	ft_strlcat(newstr, s2, (count + 2));
	return (newstr);
}

char *ft_freejoin(char *byte, char *res)
{
	char *tmp;

	tmp = ft_strjoin(byte, res);
	free(byte);
	return (tmp);
}
static char *get_line_after(char *p)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while(p[i] != '\n' && p[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	j = 0;
	while(p[i])
	{
		str[j] = p[i];
		i++;
		j++;
	}
	free(str);
	return (str);
}
static char *get_line(char *p)
{
	int	i;
	char	*str;

	i = 0;
	while(p[i] != '\n' && p[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while(p[i] && p[i] != '\n')
	{
		str[i] = p[i];
		i++;
	}
	if (p[i] && p[i] == '\n')
	{
		i++;
		str[i] = p[i];
	}
	return (str);
}

static char get_read(char *str, int fd)
{
	int i;
	int byte;
	char *res;

	i = 0;
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, res, BUFFER_SIZE);
		if (byte == -1)
		{
			free(res);
			return (NULL);
		}
		str = ft_freejoin(res, str);
		if(str[ft_strlen(str)] == '\n')
			break ;
	}
	free(res);
	return (str);
}

char *get_next_line(int fd)
{
	static char *p;
	char		*str;
	int	i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(0 , 0, fd) < 0)
	p = get_read(p, fd);
	if(!p)
		return(NULL);
	str = get_line(p);
	p = get_line_after(p);
	return (str);
}

