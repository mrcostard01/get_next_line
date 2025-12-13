#include "get_next_line.h"


char *ft_freejoin(char *p, char *res, int bytes)
{
	char	*str;

	str = ft_strjoin(p, res, bytes);
	if (!str)
		return (NULL);
	if (p)
		free(p);
	return (str);
}

char *get_line_after(char *p)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	if (!p)
		return (NULL);
	while(p[i] != '\n' && p[i])
		i++;
	if (!p[i])
	{
		free(p);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(p) - i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
    i++;
	j = 0;
	while(p[i])
	{
		str[j] = p[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(p);
	return (str);
}
char *get_one_line(char *p)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	if (!p || !p[0])
    	return (NULL);
	if (ft_strlen(p) == 1)
		return(p);
	while(p[i] != '\n' && p[i])
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (str == NULL)
		return (NULL);
	j = 0;
    while (j < i)
    {
        str[j] = p[j];
        j++;
    }
	if (p[i] == '\n')
		str[j++] = '\n';
	return (str);
}

char *get_read(char *str, int fd)
{
	int byte;
	char *res;


	if (!str)
		str = ft_calloc(1, 1);
	res = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!res)
		return (NULL);
	byte = 1;
	while (!ft_strchr(str, '\n')&& byte > 0 )
	{

		byte = read(fd, res, BUFFER_SIZE);
			if (byte <= 0)
			{
				free(res);
				free(str);
				return (str);
			}
		else {
			res[byte] = '\0';
			str = ft_freejoin(str, res, byte);
		}
	}
	free(res);
	return (str);
}

char *get_next_line(int fd)
{
	static char *p;
	char		*str;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0|| fd < 0 || fd >= 1024)
	{
		free(p);
		p = NULL;
		return(p);
	}
	p = get_read(p, fd);q
	if(!p)
		return(NULL);
	str = get_one_line(p);
	p = get_line_after(p);
	return (str);
}

#include <fcntl.h>
#include <stdio.h>
int		main() {
	char *line;
	int fd = open("1char.txt", O_RDWR);
	while (1) {
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd);
}

