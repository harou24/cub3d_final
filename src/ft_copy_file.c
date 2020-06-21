/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_copy_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/13 10:45:38 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/19 15:29:57 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	set_line(char **file, t_config *conf, char *line)
{
	char	*tmp;

	if (conf->nb_line < 8)
	{
		tmp = ft_strtrim(line, " ");
		file[conf->nb_line] = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		file[conf->nb_line] = ft_strdup(line);
		if ((int)ft_strlen(line) > conf->max_line)
			conf->max_line = ft_strlen(line);
	}
}

char	**cpy_cube_file(char *argv, t_config *conf)
{
	char	**res;
	char	*line;
	int		ret;
	int		fd;

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
			res = realloc(res, sizeof(char **) * (conf->nb_line + 1));
			set_line(res, conf, line);
			conf->nb_line++;
		}
		free(line);
	}
	return (res);
}
