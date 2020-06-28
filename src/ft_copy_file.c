/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_copy_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:11:06 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:11:10 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void			set_line(char **file, t_config *conf, char *line)
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

static int			check(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '1')
			count += 2;
		if (line[i] == '2')
			count++;
		if (line[i] == '0')
			count++;
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
				&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
				&& line[i] != 'W' && line[i] != ' ')
			count -= 10;
		i++;
	}
	return (count);
}

static int			get_fd(char *argv, char **res)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0 || res == NULL)
		print_error("Error\nCopy Fatal Error\n");
	return (fd);
}

static int			get_max(char *line, int space, t_config *conf)
{
	int		max;

	max = check(line);
	if (space == 1 && max > 1 && conf->nb_line > 9)
		print_error("Map_failure\n");
	return (max);
}

char				**cpy_cube_file(char *argv, t_config *conf, int space)
{
	char	**res;
	char	*line;
	int		tab[2];

	res = malloc(sizeof(char **));
	line = NULL;
	tab[0] = 1;
	tab[1] = get_fd(argv, res);
	while (tab[0] > 0)
	{
		tab[0] = get_next_line(tab[1], &line);
		if (!ft_isemptyline(line))
		{
			res = ft_realloc(res, sizeof(char **) * (conf->nb_line + 1));
			set_line(res, conf, line);
			conf->nb_line++;
			get_max(line, space, conf);
			space = 0;
		}
		else if (ft_isemptyline(line))
			space = 1;
		free(line);
	}
	close(tab[1]);
	return (res);
}
