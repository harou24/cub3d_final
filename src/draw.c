/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 16:13:16 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 12:00:01 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/bmp.h"

static void		draw(t_window *w, int draw_start, int draw_end, int x)
{
	int				y;
	int				color_floor;
	int				color_ceiling;
	unsigned int	color;

	y = draw_start;
	while (y < draw_end)
	{
		color = get_color(w);
		color &= ~(0xFF000000);
		my_mlx_pixel_put(w->non_active, x, y, color);
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

static void		put_sprite_color(t_window *w)
{
	int		y;
	int		color;

	y = w->sprite.draw_start_y;
	while (y < w->sprite.draw_end_y)
	{
		w->sprite.d = (y - w->sprite.v_move_screen)
			* 256 - w->conf.height * 128 + w->sprite.sprite_height * 128;
		w->sprite.y = ((w->sprite.d * w->textures[4].tex.height)
				/ w->sprite.sprite_height) / 256;
		color = my_mlx_pixel_read(&w->textures[4].tex.data,
				w->sprite.x, w->sprite.y);
		color &= ~(0xFF000000);
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(w->non_active, w->sprite.stripe, y, color);
		y++;
	}
}

static void		draw_sprites(t_window *w, double z_buffer[])
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
									w->sprite.sprite_screen_x)) *
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

void			game(t_window *w)
{
	double	z_buffer[w->conf.width];
	int		x;

	x = 0;
	while (x < w->conf.width)
	{
		init_game(w, x);
		jumpt_to_next_map(w);
		w->game.line_height = (int)((w->conf.height / w->game.perp_wall_dist));
		w->game.wall_hit = 0;
		if (w->game.side == 0)
			w->game.wall_hit = w->game.p.pos.y + w->game.perp_wall_dist
				* w->game.ray_dir.y;
		else
			w->game.wall_hit = w->game.p.pos.x + w->game.perp_wall_dist
				* w->game.ray_dir.x;
		w->game.wall_hit -= floor(w->game.wall_hit);
		init_each_of_textures_values(w, get_start(w));
		draw(w, get_start(w), get_end(w), x);
		z_buffer[x] = w->game.perp_wall_dist;
		x++;
	}
	draw_sprites(w, z_buffer);
	swap_img(w);
	mlx_put_image_to_window(w->mlx, w->win, w->active->img, 0, 0);
}
