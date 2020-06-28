/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:23:28 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:23:32 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strnjoin(char *s1, char const *s2, size_t pos);
int		is_next_line(char *buffer);
size_t	pos_next_line(char *buffer);
#endif
