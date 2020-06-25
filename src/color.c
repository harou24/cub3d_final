/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 15:00:37 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 11:04:57 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			my_mlx_pixel_put_rgb(unsigned char *addr, t_counter write,
											int line_size, unsigned int color)
{
	unsigned char	*dst;

	dst = addr + (write.y * line_size + write.x * 3);
	ft_memcpy(dst, &color, 3);
}

unsigned int	my_mlx_pixel_read(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

int				create_trgb(int t, int r, int g, int b)
{
	int		color;

	color = 0x00000000;
	color = color | (t << 24);
	color = color | (r << 16);
	color = color | (g << 8);
	color = color | (b << 0);
	return (color);
}
