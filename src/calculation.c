/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculation.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:08:34 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:08:39 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void		calculate_step_and_side_distance(t_window *w)
{
	if (w->game.ray_dir.x < 0)
	{
		w->game.step_x = -1;
		w->game.side_dist.x = (w->game.p.pos.x - w->game.map_x)
			* w->game.delta_dist.x;
	}
	else
	{
		w->game.step_x = 1;
		w->game.side_dist.x = (w->game.map_x + 1.0 - w->game.p.pos.x)
			* w->game.delta_dist.x;
	}
	if (w->game.ray_dir.y < 0)
	{
		w->game.step_y = -1;
		w->game.side_dist.y = (w->game.p.pos.y - w->game.map_y)
			* w->game.delta_dist.y;
	}
	else
	{
		w->game.step_y = 1;
		w->game.side_dist.y = (w->game.map_y + 1.0 - w->game.p.pos.y)
			* w->game.delta_dist.y;
	}
}

static void		set_perp_wall_dist(t_window *w)
{
	if (w->game.side == 0)
		w->game.perp_wall_dist = (w->game.map_x - w->game.p.pos.x +
				(1 - w->game.step_x) / 2) / w->game.ray_dir.x;
	else
		w->game.perp_wall_dist = (w->game.map_y - w->game.p.pos.y +
				(1 - w->game.step_y) / 2) / w->game.ray_dir.y;
}

void			jumpt_to_next_map(t_window *w)
{
	calculate_step_and_side_distance(w);
	while (w->game.hit == 0)
	{
		if (w->game.side_dist.x < w->game.side_dist.y)
		{
			w->game.side_dist.x = w->game.side_dist.x + w->game.delta_dist.x;
			if (w->game.map_x + w->game.step_x >= 0)
				w->game.map_x = w->game.map_x + w->game.step_x;
			w->game.side = 0;
		}
		else
		{
			w->game.side_dist.y = w->game.side_dist.y + w->game.delta_dist.y;
			if (w->game.map_y + w->game.step_y >= 0)
				w->game.map_y = w->game.map_y + w->game.step_y;
			w->game.side = 1;
		}
		if (w->conf.map[w->game.map_y][w->game.map_x] == '1')
			w->game.hit = 1;
	}
	set_perp_wall_dist(w);
}
