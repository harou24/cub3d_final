/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_resolution.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 16:17:36 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/20 19:11:46 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		get_width(char *line)
{
	int		i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		return (ft_atoi_at_index(line, i));
	return (-1);
}

int		get_height(char *line)
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

void	set_resolution(t_config *conf, char *str)
{
	int		width;
	int		height;

	if (!is_resolution_line_ok(str))
		print_error("Resolution Error !");
	height = get_height(str);
	if (height < 1)
		print_error("Resolution Error : invalid height value");
	width = get_width(str);
	if (width < 1)
		print_error("Resolution Error : invalid width value");
	conf->width = width;
	conf->height = height;
}

int		is_resolution_line_ok(char *line)
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
