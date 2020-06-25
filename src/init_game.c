/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 14:20:46 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 12:08:01 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void			init_game(t_window *w, int current_width)
{
	w->game.camera = 2 * current_width / (double)w->conf.width - 1;
	w->game.ray_dir.x = w->game.p.dir.x + w->game.plane.x * w->game.camera;
	w->game.ray_dir.y = w->game.p.dir.y + w->game.plane.y * w->game.camera;
	w->game.map_x = (int)w->game.p.pos.x;
	w->game.map_y = (int)w->game.p.pos.y;
	w->game.side_dist = new_vec2(0.0, 0.0);
	w->game.delta_dist.x = fabs(1 / w->game.ray_dir.x);
	w->game.delta_dist.y = fabs(1 / w->game.ray_dir.y);
	w->game.step_x = 0;
	w->game.step_y = 0;
	w->game.hit = 0;
	w->game.side = 0;
}

static void		init_player(t_window *w)
{
	w->game.p.pos = new_vec2(0.0, 0.0);
	w->game.p.dir = new_vec2(0.0, 0.0);
	w->game.ray_dir = new_vec2(0.0, 0.0);
	w->game.plane = new_vec2(0.0, 0.0);
}

void			init_player_pos(t_window *w)
{
	init_player(w);
	if (w->conf.direction == 'Z')
		print_error("Error\nNo direction set !\n");
	w->game.p.pos = new_vec2(w->conf.pos_x + 0.5, w->conf.pos_y + 0.5);
	if (w->conf.direction == 'E')
	{
		w->game.p.dir = new_vec2(1.0, 0.0);
		w->game.plane = new_vec2(0.0, 0.66);
	}
	else if (w->conf.direction == 'W')
	{
		w->game.p.dir = new_vec2(-1.0, 0.0);
		w->game.plane = new_vec2(0.0, -0.66);
	}
	else if (w->conf.direction == 'S')
	{
		w->game.p.dir = new_vec2(0.0, 1.0);
		w->game.plane = new_vec2(0.66, 0.0);
	}
	else if (w->conf.direction == 'N')
	{
		w->game.p.dir = new_vec2(0.0, -1.0);
		w->game.plane = new_vec2(-0.66, 0.0);
	}
}
