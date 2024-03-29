/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:13:03 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/29 11:39:33 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_data		*make_more_images(t_window *w)
{
	t_data	*array;
	int		i;

	array = malloc(sizeof(t_data) * 100);
	i = 0;
	w->array_index = 0;
	w->non_active = &array[0];
	while (i < 100)
	{
		array[i].img = mlx_new_image(w->mlx, w->conf.width, w->conf.height);
		array[i].addr = mlx_get_data_addr(array[i].img,
				&array[i].bits_per_pixel, &array[i].line_length,
					&array[i].endian);
		i++;
	}
	return (array);
}

void		swap_img(t_window *w)
{
	w->active = &w->array[w->array_index];
	if (w->array_index == 99)
		w->array_index = 0;
	w->non_active = &w->array[w->array_index + 1];
	w->array_index++;
}
