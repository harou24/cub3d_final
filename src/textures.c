/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 14:05:34 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/23 20:02:41 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void		load_texture(t_window *w, t_texture *t)
{
	int		fd;
	int		res;
	char	buffer[1];

	fd = open(t->path, O_RDONLY);
	if (fd == -1)
		print_error("File does not exist !\n");
	res = read(fd, buffer, 1);
	if (res == -1)
		print_error("Invalide file for texture !\n");
	char *s = ft_strrchr(t->path, '.');
	if (ft_strncmp(s, ".png", 4) == 0)
	{
	t->tex.data.img = mlx_png_file_to_image(w->mlx, t->path,
				&t->tex.width, &t->tex.height);
	t->tex.data.addr = mlx_get_data_addr(t->tex.data.img,
			&t->tex.data.bits_per_pixel, &t->tex.data.line_length,
				&t->tex.data.endian);
	}
	else if(ft_strncmp(s, ".xpm", 4) == 0)
	{
	t->tex.data.img = mlx_xpm_file_to_image(w->mlx, t->path,
				&t->tex.width, &t->tex.height);
	t->tex.data.addr = mlx_get_data_addr(t->tex.data.img,
			&t->tex.data.bits_per_pixel, &t->tex.data.line_length,
				&t->tex.data.endian);
	}

	else
		print_error("Textures error3\n");

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
	magic_free(w->conf.textures, 5);
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
