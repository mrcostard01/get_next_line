#include "get_next_line.h"
int ft_strlen(const char *s)
{
    int i;

    i = 0;
	if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}
char *ft_strjoin( char *s1, char *s2, int bytes)
{
    int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1)
	{
    	s1 = ft_calloc(1, 1);
    	if (!s1)
        	return (NULL);
	}
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < bytes && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}
char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;
	int	length;

	i = 0;
	if (!string)
		return (NULL);
	length = ft_strlen(string);
	while (i <= length)
	{
		if (string[i] == (char)searchedChar)
			return ((char *)&string[i]);
		i++;
	}
	string = 0;
	return ((char *)string);
}
static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	ft_bzero(res, elementSize * elementCount);
	return (res);
}

