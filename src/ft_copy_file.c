/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_copy_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/13 10:45:38 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/23 21:15:49 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	set_line(char **file, t_config *conf, char *line)
{
	if (conf->nb_line < 8)
	{
		file[conf->nb_line] = ft_strtrim(line, " ");
	}
	else
	{
		file[conf->nb_line] = ft_strdup(line);
		if ((int)ft_strlen(line) > conf->max_line)
			conf->max_line = ft_strlen(line);
	}
}

int check(char *line)
{
	int i = 0;
	int count = 0;
	while(line[i])
	{
		if(line[i] == '1')
			count++;
		if(line[i] == '2')
			count++;
		if(line[i] == '0')
			count++;
		if(line[i] != '0' && line[i] != '1' && line[i] != '2' 
				&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
				&& line[i] != 'W')
			count -= 10;
		i++;
	}
	return (count);
}
char	**cpy_cube_file(char *argv, t_config *conf)
{
	char	**res;
	char	*line;
	int		ret;
	int		fd;
	int max = 0;
	int space = 0;
	res = malloc(sizeof(char **));
	line = NULL;
	ret = 1;
	fd = open(argv, O_RDONLY);
	if (fd < 0 || res == NULL)
		return (NULL);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (!is_empty_line(line))
		{
			res = ft_realloc(res, sizeof(char **) * (conf->nb_line + 1));
			set_line(res, conf, line);
			conf->nb_line++;
			max = check(line);
			if(space == 1 && max > 1 && conf->nb_line > 9)
				print_error("Map_failure\n");
			space = 0;
		}
		else if(is_empty_line(line))
			space = 1;
		free(line);
	}
	close(fd);
	return (res);
}
