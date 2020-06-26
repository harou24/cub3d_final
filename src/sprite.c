/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 17:03:07 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 18:39:45 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int		is_sprite_in_line(char *line)
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

void			get_sprites(t_config *conf)
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

void			get_sprites_back(t_config *conf)
{
	int		i;

	i = 0;
	while (i < conf->nb_sprite)
	{
		conf->map[(int)conf->sprites_pos[i].y][(int)conf->sprites_pos[i].x] =
			'2';
		i++;
	}
}

static void		init_sprite2(t_window *w)
{
	if (w->sprite.draw_start_y < 0)
		w->sprite.draw_start_y = 0;
	w->sprite.draw_end_y = w->sprite.sprite_height / 2
		+ w->conf.height / 2 + w->sprite.v_move_screen;
	if (w->sprite.draw_end_y >= w->conf.height)
		w->sprite.draw_end_y = w->conf.height - 1;
	w->sprite.width = abs((int)(w->conf.height
				/ (w->sprite.transform.y))) / U_DIV;
	w->sprite.draw_start_x = -w->sprite.width / 2 + w->sprite.sprite_screen_x;
	if (w->sprite.draw_start_x < 0)
		w->sprite.draw_start_x = 0;
	w->sprite.draw_end_x = w->sprite.width / 2 + w->sprite.sprite_screen_x;
	if (w->sprite.draw_end_x >= w->conf.width)
		w->sprite.draw_end_x = w->conf.width - 1;
	w->sprite.stripe = w->sprite.draw_start_x;
}

void			init_sprite(t_window *w, int index)
{
	w->sprite.pos.x = w->conf.sprites_pos[index].x - w->game.p.pos.x + 0.5;
	w->sprite.pos.y = w->conf.sprites_pos[index].y - w->game.p.pos.y + 0.5;
	w->sprite.inv_det = 1.0 / (w->game.plane.x *
			w->game.p.dir.y - w->game.p.dir.x * w->game.plane.y);
	w->sprite.transform.x = w->sprite.inv_det *
		(w->game.p.dir.y * w->sprite.pos.x - w->game.p.dir.x * w->sprite.pos.y);
	w->sprite.transform.y = w->sprite.inv_det *
		(-w->game.plane.y * w->sprite.pos.x +
			w->game.plane.x * w->sprite.pos.y);
	w->sprite.sprite_screen_x = (int)((w->conf.width / 2) *
			(1 + w->sprite.transform.x / w->sprite.transform.y));
	w->sprite.sprite_height =
		abs((int)(w->conf.height / (w->sprite.transform.y))) / V_DIV;
	w->sprite.v_move_screen = (int)(V_MOVE / w->sprite.transform.y);
	w->sprite.draw_start_y = -w->sprite.sprite_height / 2 +
		w->conf.height / 2 + w->sprite.v_move_screen;
	init_sprite2(w);
}
