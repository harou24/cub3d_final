/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_resolution.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:11:30 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/29 11:37:08 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int		get_width(char *line)
{
	int		i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		return (ft_atoi_at_index(line, i));
	return (-1);
}

static int		get_height(char *line)
{
	int		i;

	i = ft_strlen(line);
	while (line[i] != ' ')
		i--;
	if (line[i] != ' ')
		return (-1);
	if (ft_isdigit(line[i + 1]))
		return (ft_atoi_at_index(line, i + 1));
	return (-1);
}

static int		is_resolution_line_ok(char *line)
{
	int		i;
	int		nb_number;

	i = ft_strlen(line);
	nb_number = 0;
	if (line[0] != 'R')
		print_error("Error\n::Wrond ID for Resolution::\n");
	if (!ft_iswhitespace(line[1]))
		print_error("Error\nResolution\n");
	while (i > 0)
	{
		if (ft_isdigit(line[i]) && line[i - 1] == ' ')
			nb_number++;
		i--;
	}
	if (nb_number == 2)
		return (1);
	return (0);
}

void			set_resolution(t_config *conf, char *str)
{
	int		width;
	int		height;

	if (conf->height != -1 && conf->width != -1)
		print_error("Error\nToo many Resolution !\n");
	if (!is_resolution_line_ok(str))
		print_error("Error\nResolution Error !\n");
	height = get_height(str);
	width = get_width(str);
	conf->width = width;
	conf->height = height;
	if (height < 1)
		print_error("Error\nResolution Error : Invalid Resolution value\n");
	if (width < 1)
		print_error("Error\nResolution Error : Invalid Resolution value\n");
}
