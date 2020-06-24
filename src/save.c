/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 19:33:46 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/24 17:58:47 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/bmp.h"

static t_header		new_header(t_window *w, t_bmp bmp)
{
	t_header h;

	ft_memset(&h, 0, sizeof(t_header));
	h.type = 0x4d42;
	h.size = w->conf.width * w->conf.height * 4 + 54;
	h.offset = 54;
	h.dib_header_size = 40;
	h.width_px = w->conf.width;
	h.height_px = w->conf.height;
	h.num_planes = 1;
	h.bits_per_pixel = 24;
	h.image_size_bytes = bmp.data_size;
	return (h);
}

static	ssize_t		write_header(int fd, t_header h)
{
	return (write(fd, &h, sizeof(t_header)));
}

static void			init_bmp(t_bmp *bmp, t_window *w)
{
	bmp->padding = w->conf.width % 4;
	bmp->line_size = 3 * w->conf.width + bmp->padding;
	bmp->data_size = bmp->line_size * w->conf.height;
	bmp->data = malloc(bmp->data_size);
	if (bmp->data == NULL)
		print_error("Error");
}

static t_bmp		new_bmp(t_window *w)
{
	t_bmp			bmp;
	unsigned int	color;
	t_counter		read;
	t_counter		write;

	read.y = w->conf.height - 1;
	write.y = 0;
	init_bmp(&bmp, w);
	bmp.header = new_header(w, bmp);
	while (read.y >= 0)
	{
		write.x = 0;
		while (write.x < w->conf.width)
		{
			color = my_mlx_pixel_read(w->active, write.x, read.y);
			my_mlx_pixel_put_rgb(bmp.data, write,
					bmp.line_size, color);
			write.x++;
		}
		read.y--;
		write.y++;
	}
	return (bmp);
}

ssize_t				write_data(int fd, t_window *w)
{
	t_bmp	bmp;

	bmp = new_bmp(w);
	if (write_header(fd, bmp.header) == -1 ||
			write(fd, bmp.data, bmp.data_size) == -1)
	{
		print_error("Error");
		return (-1);
	}
	return (1);
}
