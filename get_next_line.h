/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:47:34 by wipion            #+#    #+#             */
/*   Updated: 2025/12/13 22:48:15 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, int bytes);
char	*ft_strchr(const char *string, int searchedChar);
char	*get_read(char *str, int fd);
char	*get_one_line(char *p);
char	*get_line_after(char *p);
char	*ft_freejoin(char *p, char *res, int bytes);
void	*ft_calloc(size_t elementCount, size_t elementSize);
#endif
