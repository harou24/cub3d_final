/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:09:36 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:09:42 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_config	new_config(void)
{
	t_config	conf;

	conf.height = -1;
	conf.width = -1;
	conf.max_line = 0;
	conf.nb_line = 0;
	conf.nb_sprite = 0;
	conf.sprites_pos = malloc(sizeof(t_vec2) * 200);
	conf.pos_x = 0;
	conf.pos_y = 0;
	conf.direction = 'Z';
	conf.textures = malloc(sizeof(char **) * 5);
	if (conf.textures == NULL || conf.sprites_pos == NULL)
		print_error("Malloc = NULL");
	conf.textures[0] = NULL;
	conf.textures[1] = NULL;
	conf.textures[2] = NULL;
	conf.textures[3] = NULL;
	conf.textures[4] = NULL;
	conf.rgb_ceiling[0] = -1;
	conf.rgb_floor[0] = -1;
	return (conf);
}

void		get_config(char **file, t_config *conf)
{
	int		i;
	int		j;
	int		map_start;

	i = 0;
	j = 0;
	map_start = 0;
	conf->map = malloc(sizeof(char **) * (conf->nb_line - 8));
	while (i < conf->nb_line)
	{
		if (get_line_id(file[i]) == 'R')
			set_resolution(conf, file[i]);
		else if (get_line_id(file[i]) == 'N' || get_line_id(file[i]) == 'S'
				|| get_line_id(file[i]) == 'E' || get_line_id(file[i]) == 'W'
					|| get_line_id(file[i]) == 'P')
			set_texture(conf, file[i]);
		else if ((get_line_id(file[i]) == 'C' || get_line_id(file[i]) == 'F')
					&& ft_iswhitespace(file[i][1]))
			set_color(conf, file[i]);
		else
			set_map(conf, file[i]);
		i++;
	}
}
