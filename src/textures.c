/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 14:05:34 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/20 19:24:01 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void		load_texture(t_window *w, t_texture *t)
{
	t->tex.data.img = mlx_png_file_to_image(w->mlx, t->path,
				&t->tex.width, &t->tex.height);
	t->tex.data.addr = mlx_get_data_addr(t->tex.data.img,
			&t->tex.data.bits_per_pixel, &t->tex.data.line_length,
				&t->tex.data.endian);
	ft_putstr_fd(t->path, 1);
	ft_putchar_fd('\n', 1);
}

t_texture	*get_textures(t_window *w)
{
	t_texture	*textures;
	int			count;

	textures = malloc(sizeof(t_texture) * 5);
	count = 0;
	while (count < 5)
	{
		textures[count].path = w->conf.textures[count];
		load_texture(w, &textures[count]);
		count++;
	}
	return (textures);
}

void		init_each_of_textures_values(t_window *w, int draw_start)
{
	int k;

	k = 0;
	while (k < 4)
	{
		init_texture(w, &w->textures[k], draw_start);
		k++;
	}
}

void		init_texture(t_window *w, t_texture *t, int draw_start)
{
	t->x = w->game.wall_hit * (double)t->tex.width;
	if (w->game.side == 0 && w->game.rayDir.x > 0)
		t->x = t->tex.width - t->x - 1;
	if (w->game.side == 1 && w->game.rayDir.y < 0)
		t->x = t->tex.width - t->x - 1;
	t->step = 1.0 * t->tex.height / w->game.line_height;
	t->pos = (draw_start - w->conf.height / 2 + w->game.line_height / 2)
		* t->step;
}
