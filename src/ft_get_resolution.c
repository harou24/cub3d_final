/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_resolution.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 16:17:36 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/24 17:57:44 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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

int				is_resolution_line_ok(char *line)
{
	int		i;
	int		nb_number;

	i = ft_strlen(line);
	nb_number = 0;
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
