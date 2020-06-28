/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:17:20 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:17:23 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void		swap(t_vec2 *a, t_vec2 *b)
{
	t_vec2	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void		buble_sort(t_vec2 *tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j].dist < tab[j + 1].dist)
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

void			order_sprites(t_window *w)
{
	int i;

	i = 0;
	while (i < w->conf.nb_sprite)
	{
		w->conf.sprites_pos[i].dist =
			fabs(w->game.p.pos.x - w->conf.sprites_pos[i].x) +
				fabs(w->game.p.pos.y - w->conf.sprites_pos[i].y);
		i++;
	}
	buble_sort(w->conf.sprites_pos, w->conf.nb_sprite);
}
