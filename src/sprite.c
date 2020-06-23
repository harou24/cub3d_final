/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 17:03:07 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/22 12:02:01 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		is_sprite_in_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '2')
			return (1);
		i++;
	}
	return (0);
}

void	get_sprites(t_config *conf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < conf->nb_line - 8)
	{
		if (is_sprite_in_line(conf->map[i]))
		{
			j = 0;
			while (j < conf->max_line)
			{
				if (conf->map[i][j] == '2')
				{
					conf->sprites_pos[conf->nb_sprite] = new_vec2((double)j
							, (double)i);
					conf->nb_sprite++;
				}
				j++;
			}
		}
		i++;
	}
}
