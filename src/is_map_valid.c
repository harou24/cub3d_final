/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_map_valid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:13:51 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/29 11:41:12 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int		are_bounderies_ok(char *line)
{
	int		i;

	i = 0;
	if (line[i] == 'X' || line[ft_strlen(line) - 1] == 'X')
		return (0);
	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] == 'X')
			return (0);
		if (line[i] == 'X' && line[i + 1] == ' ')
			return (0);
		i++;
	}
	return (1);
}

static int		is_first_line_ok(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'X')
			return (0);
		i++;
	}
	return (1);
}

static int		is_map_line_ok(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' && line[i] != 'N'
				&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int				is_line_valid(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
				&& line[i] != '2' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int				is_map_valid(t_config *conf)
{
	int		i;

	i = 0;
	if (!is_first_line_ok(conf->map[0]))
		return (0);
	if (!is_map_line_ok(conf->map[conf->nb_line - 9]))
		return (0);
	while (i < conf->nb_line - 8)
	{
		if (!are_bounderies_ok(conf->map[i]))
			return (0);
		i++;
	}
	return (1);
}
