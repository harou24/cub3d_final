/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/13 13:45:59 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/19 14:47:02 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

t_config	new_config(void)
{
	t_config	conf;

	conf.height = 0;
	conf.width = 0;
	conf.max_line = 0;
	conf.nb_line = 0;
	conf.nb_sprite = 0;
	conf.sprites_pos = malloc(sizeof(t_vec2) * 200);
	conf.map = malloc(sizeof(char **) * 1);
	conf.posX = 0;
	conf.posY = 0;
	conf.direction = 'Z';
	conf.textures = malloc(sizeof(char **) * 5);
	if (conf.textures == NULL || conf.sprites_pos == NULL || conf.map == NULL)
		print_error("Malloc = NULL");
	conf.textures[0] = NULL;
	conf.textures[1] = NULL;
	conf.textures[2] = NULL;
	conf.textures[3] = NULL;
	conf.textures[4] = NULL;
	return (conf);
}

void		get_config(char **file, t_config *conf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	conf->map = malloc(sizeof(char **) * (conf->nb_line - 8));
	conf->textures = malloc(sizeof(char **) * 5);
	while (i < conf->nb_line)
	{
		if (get_line_id(file[i]) == 'R')
			set_resolution(conf, file[i]);
		else if (get_line_id(file[i]) == 'N' || get_line_id(file[i]) == 'S'
				|| get_line_id(file[i]) == 'E' || get_line_id(file[i]) == 'W'
					|| get_line_id(file[i]) == 'P')
			set_texture(conf, file[i]);
		else if (get_line_id(file[i]) == 'C' || get_line_id(file[i]) == 'F')
			set_color(conf, file[i]);
		else
			set_map(conf, file[i]);
		i++;
	}
}
