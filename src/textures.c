/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:17:42 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/29 11:55:47 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void		check_path(char *path)
{
	int		fd;
	int		res;
	char	buffer[1];

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error("Error\nFile does not exist !\n");
	res = read(fd, buffer, 1);
	if (res == -1)
		print_error("Error\nInvalide file for texture !\n");
}

static void		load_texture(t_window *w, t_texture *t)
{
	char	*s;

	check_path(t->path);
	s = ft_strrchr(t->path, '.');
	if (ft_strncmp(s, ".png", 4) == 0)
	{
		t->tex.data.img = mlx_png_file_to_image(w->mlx, t->path,
				&t->tex.width, &t->tex.height);
	}
	else if (ft_strncmp(s, ".xpm", 4) == 0)
	{
		t->tex.data.img = mlx_xpm_file_to_image(w->mlx, t->path,
				&t->tex.width, &t->tex.height);
	}
	else
		print_error("Error\nTextures loading error\n");
	if (t->tex.data.img == NULL)
		print_error("Error\n");
	t->tex.data.addr = mlx_get_data_addr(t->tex.data.img,
			&t->tex.data.bits_per_pixel, &t->tex.data.line_length,
			&t->tex.data.endian);
	ft_putstr_fd("\n\nO----------------Loading---------------->   ", 1);
	ft_putstr_fd(t->path, 1);
	ft_putchar_fd('\n', 1);
}

t_texture		*get_textures(t_window *w)
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

static void		init_texture(t_window *w, t_texture *t, int draw_start)
{
	t->x = w->game.wall_hit * (double)t->tex.width;
	if (w->game.side == 0 && w->game.ray_dir.x > 0)
		t->x = t->tex.width - t->x - 1;
	if (w->game.side == 1 && w->game.ray_dir.y < 0)
		t->x = t->tex.width - t->x - 1;
	t->step = 1.0 * t->tex.height / w->game.line_height;
	t->pos = (draw_start - w->conf.height / 2 + w->game.line_height / 2)
		* t->step;
}

void			init_each_of_textures_values(t_window *w, int draw_start)
{
	int k;

	k = 0;
	while (k < 4)
	{
		init_texture(w, &w->textures[k], draw_start);
		k++;
	}
}
