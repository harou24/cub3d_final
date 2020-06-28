/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:14:18 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:14:22 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_camera(t_window *w, double old_dir_x, double old_plane_x)
{
	old_dir_x = w->game.p.dir.x;
	old_plane_x = w->game.plane.x;
	if (w->k.key_state[5] == 1)
	{
		w->game.p.dir.x = w->game.p.dir.x * cos(-ROTATION_SPEED) -
			w->game.p.dir.y * sin(-ROTATION_SPEED);
		w->game.p.dir.y = old_dir_x * sin(-ROTATION_SPEED)
			+ w->game.p.dir.y * cos(-ROTATION_SPEED);
		w->game.plane.x = w->game.plane.x * cos(-ROTATION_SPEED) -
			w->game.plane.y * sin(-ROTATION_SPEED);
		w->game.plane.y = old_plane_x * sin(-ROTATION_SPEED)
			+ w->game.plane.y * cos(-ROTATION_SPEED);
	}
	else
	{
		w->game.p.dir.x = w->game.p.dir.x * cos(ROTATION_SPEED)
			- w->game.p.dir.y * sin(ROTATION_SPEED);
		w->game.p.dir.y = old_dir_x * sin(ROTATION_SPEED)
			+ w->game.p.dir.y * cos(ROTATION_SPEED);
		w->game.plane.x = w->game.plane.x * cos(ROTATION_SPEED)
			- w->game.plane.y * sin(ROTATION_SPEED);
		w->game.plane.y = old_plane_x * sin(ROTATION_SPEED) +
			w->game.plane.y * cos(ROTATION_SPEED);
	}
}

void	move_down(t_window *w)
{
	double	xx;
	double	yy;

	xx = w->game.p.pos.x - w->game.p.dir.x * WALL_LIMIT;
	if (w->conf.map[(int)w->game.p.pos.y][(int)xx] != '1'
			&& w->conf.map[(int)w->game.p.pos.y][(int)xx] != '2')
		w->game.p.pos.x -= w->game.p.dir.x * MOVE_SPEED;
	yy = w->game.p.pos.y - w->game.p.dir.y * WALL_LIMIT;
	if (w->conf.map[(int)yy][(int)w->game.p.pos.x] != '1'
			&& w->conf.map[(int)yy][(int)w->game.p.pos.x] != '2')
		w->game.p.pos.y -= w->game.p.dir.y * MOVE_SPEED;
}

void	move_up(t_window *w)
{
	double	xx;
	double	yy;

	xx = w->game.p.pos.x + w->game.p.dir.x * WALL_LIMIT;
	if (w->conf.map[(int)w->game.p.pos.y][(int)xx] != '1'
			&& w->conf.map[(int)w->game.p.pos.y][(int)xx] != '2')
		w->game.p.pos.x += w->game.p.dir.x * MOVE_SPEED;
	yy = w->game.p.pos.y + w->game.p.dir.y * WALL_LIMIT;
	if (w->conf.map[(int)yy][(int)w->game.p.pos.x] != '1'
			&& w->conf.map[(int)yy][(int)w->game.p.pos.x] != '2')
		w->game.p.pos.y += w->game.p.dir.y * MOVE_SPEED;
}

void	move_left(t_window *w)
{
	double	xx;
	double	yy;

	xx = w->game.p.pos.x - w->game.plane.x * WALL_LIMIT;
	if (w->conf.map[(int)w->game.p.pos.y][(int)xx] != '1'
			&& w->conf.map[(int)w->game.p.pos.y][(int)xx] != '2')
		w->game.p.pos.x -= w->game.plane.x * MOVE_SPEED;
	yy = w->game.p.pos.y - w->game.plane.y * WALL_LIMIT;
	if (w->conf.map[(int)yy][(int)w->game.p.pos.x] != '1'
			&& w->conf.map[(int)yy][(int)w->game.p.pos.x] != '2')
		w->game.p.pos.y -= w->game.plane.y * MOVE_SPEED;
}

void	move_right(t_window *w)
{
	double	xx;
	double	yy;

	xx = w->game.p.pos.x + w->game.plane.x * WALL_LIMIT;
	if (w->conf.map[(int)w->game.p.pos.y][(int)xx] != '1'
			&& w->conf.map[(int)w->game.p.pos.y][(int)xx] != '2')
		w->game.p.pos.x += w->game.plane.x * MOVE_SPEED;
	yy = w->game.p.pos.y + w->game.plane.y * WALL_LIMIT;
	if (w->conf.map[(int)yy][(int)w->game.p.pos.x] != '1'
			&& w->conf.map[(int)yy][(int)w->game.p.pos.x] != '2')
		w->game.p.pos.y += w->game.plane.y * MOVE_SPEED;
}
