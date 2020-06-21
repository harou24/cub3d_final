/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 18:09:02 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/19 14:47:36 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

t_key	init_key(void)
{
	t_key	k;
	int		i;

	k.key_code[0] = ESC;
	k.key_code[1] = LEFT;
	k.key_code[2] = DOWN;
	k.key_code[3] = RIGHT;
	k.key_code[4] = UP;
	k.key_code[5] = C_LEFT;
	k.key_code[6] = C_RIGHT;
	i = 0;
	while (i < 7)
	{
		k.key_state[i] = 0;
		i++;
	}
	return (k);
}

int		key_release(int keycode, void *param)
{
	t_window	*w;

	w = (t_window *)param;
	if (keycode == ESC)
		w->k.key_state[0] = 0;
	if (keycode == LEFT)
		w->k.key_state[1] = 0;
	if (keycode == DOWN)
		w->k.key_state[2] = 0;
	if (keycode == RIGHT)
		w->k.key_state[3] = 0;
	if (keycode == UP)
		w->k.key_state[4] = 0;
	if (keycode == C_LEFT)
		w->k.key_state[5] = 0;
	if (keycode == C_RIGHT)
		w->k.key_state[6] = 0;
	return (0);
}

void	key_listener(t_window *w)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = 0;
	old_plane_x = 0;
	if (w->k.key_state[0] == 1)
		exit(1);
	if (w->k.key_state[6] == 1 || w->k.key_state[5] == 1)
		move_camera(w, old_dir_x, old_plane_x);
	else if (w->k.key_state[2] == 1)
		move_down(w);
	else if (w->k.key_state[4] == 1)
		move_up(w);
	else if (w->k.key_state[1] == 1)
		move_left(w);
	else if (w->k.key_state[3] == 1)
		move_right(w);
	game(w);
}

int		key_pressed(int keycode, void *param)
{
	t_window	*w;

	w = (t_window *)param;
	if (keycode == ESC)
		w->k.key_state[0] = 1;
	if (keycode == LEFT)
		w->k.key_state[1] = 1;
	if (keycode == DOWN)
		w->k.key_state[2] = 1;
	if (keycode == RIGHT)
		w->k.key_state[3] = 1;
	if (keycode == UP)
		w->k.key_state[4] = 1;
	if (keycode == C_LEFT)
		w->k.key_state[5] = 1;
	if (keycode == C_RIGHT)
		w->k.key_state[6] = 1;
	return (0);
}

int		update(t_window *w)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		if (w->k.key_state[i] > 0)
			key_listener(w);
		i++;
	}
	return (0);
}
