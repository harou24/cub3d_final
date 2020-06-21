/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 16:13:16 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/20 21:10:24 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/bmp.h"

void	draw(t_window *w, int draw_start, int draw_end, int x)
{
	int		y;
	int		color_floor;
	int		color_ceiling;

	y = draw_start;
	while (y < draw_end)
	{
		my_mlx_pixel_put(w->non_active, x, y, get_color(w));
		y++;
	}
	y = draw_end;
	while (y < w->conf.height)
	{
		color_ceiling = create_trgb(0, w->conf.rgb_ceiling[0],
				w->conf.rgb_ceiling[1], w->conf.rgb_ceiling[2]);
		color_floor = create_trgb(0, w->conf.rgb_floor[0],
				w->conf.rgb_floor[1], w->conf.rgb_floor[2]);
		my_mlx_pixel_put(w->non_active, x, y, color_floor);
		my_mlx_pixel_put(w->non_active, x, w->conf.height - y - 1,
				color_ceiling);
		y++;
	}
}

void	init_sprite2(t_window *w)
{
	if (w->sprite.draw_start_y < 0)
		w->sprite.draw_start_y = 0;
	w->sprite.draw_end_y = w->sprite.spriteHeight / 2
		+ w->conf.height / 2 + w->sprite.vMoveScreen;
	if (w->sprite.draw_end_y >= w->conf.height)
		w->sprite.draw_end_y = w->conf.height - 1;
	w->sprite.width = abs((int)(w->conf.height
				/ (w->sprite.transform.y))) / uDiv;
	w->sprite.draw_start_x = -w->sprite.width / 2 + w->sprite.spriteScreenX;
	if (w->sprite.draw_start_x < 0)
		w->sprite.draw_start_x = 0;
	w->sprite.draw_end_x = w->sprite.width / 2 + w->sprite.spriteScreenX;
	if (w->sprite.draw_end_x >= w->conf.width)
		w->sprite.draw_end_x = w->conf.width - 1;
	w->sprite.stripe = w->sprite.draw_start_x;
}

void	init_sprite(t_window *w, int index)
{
	w->sprite.pos.x = w->conf.sprites_pos[index].x - w->game.p.pos.x + 0.5;
	w->sprite.pos.y = w->conf.sprites_pos[index].y - w->game.p.pos.y + 0.5;
	w->sprite.invDet = 1.0 / (w->game.plane.x *
			w->game.p.dir.y - w->game.p.dir.x * w->game.plane.y);
	w->sprite.transform.x = w->sprite.invDet *
		(w->game.p.dir.y * w->sprite.pos.x - w->game.p.dir.x * w->sprite.pos.y);
	w->sprite.transform.y = w->sprite.invDet *
		(-w->game.plane.y * w->sprite.pos.x +
		w->game.plane.x * w->sprite.pos.y);
	w->sprite.spriteScreenX = (int)((w->conf.width / 2) *
			(1 + w->sprite.transform.x / w->sprite.transform.y));
	w->sprite.spriteHeight =
		abs((int)(w->conf.height / (w->sprite.transform.y))) / vDiv;
	w->sprite.vMoveScreen = (int)(vMove / w->sprite.transform.y);
	w->sprite.draw_start_y = -w->sprite.spriteHeight / 2 +
		w->conf.height / 2 + w->sprite.vMoveScreen;
	init_sprite2(w);
}

void	put_sprite_color(t_window *w)
{
	int		y;
	int		color;

	y = w->sprite.draw_start_y;
	while (y < w->sprite.draw_end_y)
	{
		w->sprite.d = (y - w->sprite.vMoveScreen)
			* 256 - w->conf.height * 128 + w->sprite.spriteHeight * 128;
		w->sprite.y = ((w->sprite.d * w->textures[4].tex.height)
				/ w->sprite.spriteHeight) / 256;
		color = my_mlx_pixel_read(&w->textures[4].tex.data,
				w->sprite.x, w->sprite.y);
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(w->non_active, w->sprite.stripe, y, color);
		y++;
	}
}

void	draw_sprites(t_window *w, double z_buffer[])
{
	int		i;

	i = 0;
	order_sprites(w);
	while (i < w->conf.nb_sprite)
	{
		init_sprite(w, i);
		while (w->sprite.stripe < w->sprite.draw_end_x)
		{
			w->sprite.x =
				(int)((256 * (w->sprite.stripe - (-w->sprite.width / 2 +
									w->sprite.spriteScreenX)) *
							w->textures[4].tex.width / w->sprite.width) / 256);
			if (w->sprite.transform.y > 0 &&
					w->sprite.stripe > 0 &&
					w->sprite.stripe < w->conf.width &&
					w->sprite.transform.y < z_buffer[w->sprite.stripe])
			{
				put_sprite_color(w);
			}
			w->sprite.stripe++;
		}
		i++;
	}
}

void	game(t_window *w)
{
	double	z_buffer[w->conf.width];
	int		x;

	x = 0;
	while (x < w->conf.width)
	{
		init_game(w, x);
		jumpt_to_next_map(w);
		w->game.line_height = (int)((w->conf.height / w->game.perpWallDist));
		w->game.wall_hit = 0;
		if (w->game.side == 0)
			w->game.wall_hit = w->game.p.pos.y + w->game.perpWallDist
				* w->game.rayDir.y;
		else
			w->game.wall_hit = w->game.p.pos.x + w->game.perpWallDist
				* w->game.rayDir.x;
		w->game.wall_hit -= floor(w->game.wall_hit);
		init_each_of_textures_values(w, get_start(w));
		draw(w, get_start(w), get_end(w), x);
		z_buffer[x] = w->game.perpWallDist;
		x++;
	}
	draw_sprites(w, z_buffer);
	swap_img(w);
	/*	
		int fd = open("./screenshot/foo.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		write_data(fd, w);
		close(fd);
	//exit(0);
	*/	
	mlx_put_image_to_window(w->mlx, w->win, w->active->img, 0, 0);
}