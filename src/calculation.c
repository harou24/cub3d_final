/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   caluclation.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 13:31:48 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/23 18:52:23 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static void		calculate_step_and_side_distance(t_window *w)
{
	if (w->game.rayDir.x < 0)
	{
		w->game.stepX = -1;
		w->game.sideDist.x = (w->game.p.pos.x - w->game.mapX)
			* w->game.deltaDist.x;
	}
	else
	{
		w->game.stepX = 1;
		w->game.sideDist.x = (w->game.mapX + 1.0 - w->game.p.pos.x)
			* w->game.deltaDist.x;
	}
	if (w->game.rayDir.y < 0)
	{
		w->game.stepY = -1;
		w->game.sideDist.y = (w->game.p.pos.y - w->game.mapY)
			* w->game.deltaDist.y;
	}
	else
	{
		w->game.stepY = 1;
		w->game.sideDist.y = (w->game.mapY + 1.0 - w->game.p.pos.y)
			* w->game.deltaDist.y;
	}
}

static void		set_perp_wall_dist(t_window *w)
{
	if (w->game.side == 0)
		w->game.perpWallDist = (w->game.mapX - w->game.p.pos.x +
				(1 - w->game.stepX) / 2) / w->game.rayDir.x;
	else
		w->game.perpWallDist = (w->game.mapY - w->game.p.pos.y +
				(1 - w->game.stepY) / 2) / w->game.rayDir.y;
}

void	jumpt_to_next_map(t_window *w)
{
	calculate_step_and_side_distance(w);
	while (w->game.hit == 0)
	{
		if (w->game.sideDist.x < w->game.sideDist.y)
		{
			w->game.sideDist.x = w->game.sideDist.x + w->game.deltaDist.x;
			if (w->game.mapX + w->game.stepX >= 0)
				w->game.mapX = w->game.mapX + w->game.stepX;
			w->game.side = 0;
		}
		else
		{
			w->game.sideDist.y = w->game.sideDist.y + w->game.deltaDist.y;
			if (w->game.mapY + w->game.stepY >= 0)
				w->game.mapY = w->game.mapY + w->game.stepY;
			w->game.side = 1;
		}
		if (w->conf.map[w->game.mapY][w->game.mapX] == '1')
			w->game.hit = 1;
	}
	set_perp_wall_dist(w);
}
