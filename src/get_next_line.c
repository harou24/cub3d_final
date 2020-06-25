/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 13:03:42 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 14:55:29 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void		clean_buffer(char *buffer)
{
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[j] && buffer[i])
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	while (j < BUFFER_SIZE)
	{
		buffer[j] = '\0';
		j++;
	}
}

static int		read_to_buffer(int fd, char **line, char *buffer)
{
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		if (is_next_line(buffer) == 1)
		{
			line[0] = ft_strnjoin(line[0], buffer, pos_next_line(buffer));
			clean_buffer(buffer);
			return (1);
		}
		else if (is_next_line(buffer) == 0)
			line[0] = ft_strjoin(line[0], buffer);
		clean_buffer(buffer);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0 || ret == 0)
		{
			if (ret < 0)
				*line = NULL;
			return (ret);
		}
		buffer[ret] = '\0';
	}
	return (-1);
}

static int		read_from_the_buffer(int fd, char **line, char *buffer)
{
	if (is_next_line(buffer))
	{
		line[0] = ft_strnjoin(line[0], buffer, pos_next_line(buffer));
		clean_buffer(buffer);
	}
	else
	{
		line[0] = ft_strjoin(line[0], buffer);
		clean_buffer(buffer);
		return (read_to_buffer(fd, line, buffer));
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char buffer[BUFFER_SIZE + 1];

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	line[0] = malloc(BUFFER_SIZE + 1);
	line[0][0] = '\0';
	if (!*buffer)
		return (read_to_buffer(fd, line, buffer));
	else
	{
		return (read_from_the_buffer(fd, line, buffer));
	}
	return (0);
}
