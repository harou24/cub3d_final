/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 12:24:40 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/23 19:36:35 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int				get_start(t_window *w)
{
	int		draw_start;

	draw_start = -w->game.line_height / 2 + w->conf.height / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

int				get_end(t_window *w)
{
	int		draw_end;

	draw_end = w->game.line_height / 2 + w->conf.height / 2;
	if (draw_end >= w->conf.height)
		draw_end = w->conf.height - 1;
	return (draw_end);
}

unsigned int	get_color_if_side(t_window *w)
{
	unsigned int	color;

	if (w->game.rayDir.y < 0)
	{
		w->textures[0].y = (int)w->textures[0].pos;
		w->textures[0].pos += w->textures[0].step;
	//	printf("%d, %d,\n",w->textures[0].x, w->textures[0].y);
		color = my_mlx_pixel_read(&w->textures[0].tex.data,
				w->textures[0].x, w->textures[0].y);
	}
	else
	{
		w->textures[1].y = (int)w->textures[1].pos;
		w->textures[1].pos += w->textures[1].step;
		color = my_mlx_pixel_read(&w->textures[1].tex.data,
				w->textures[1].x, w->textures[1].y);
	}
	return (color);
}

unsigned int	get_color(t_window *w)
{
	unsigned int	color;

	if (w->game.side == 1)
		color = get_color_if_side(w);
	else
	{
		if (w->game.rayDir.x < 0)
		{
			w->textures[2].y = (int)w->textures[2].pos;
			w->textures[2].pos += w->textures[2].step;
			color = my_mlx_pixel_read(&w->textures[2].tex.data,
					w->textures[2].x, w->textures[2].y);
		}
		else
		{
			w->textures[3].y = (int)w->textures[3].pos;
			w->textures[3].pos += w->textures[3].step;
			color = my_mlx_pixel_read(&w->textures[3].tex.data,
					w->textures[3].x, w->textures[3].y);
		}
	}
	return (color);
}
