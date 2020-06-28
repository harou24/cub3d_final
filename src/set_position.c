/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_position.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:16:35 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:16:39 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int			is_position_in_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

void		set_position(t_config *conf, char *line, int y)
{
	int		i;

	i = 0;
	if (conf->direction != 'Z')
		print_error("Error\n!!! Direction Already Set !!!\n");
	conf->pos_y = y;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W')
		{
			conf->pos_x = i;
			conf->direction = line[i];
			line[i] = '0';
			break ;
		}
		i++;
	}
}
