/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec2.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:18:00 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:18:03 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_vec2	new_vec2(double x, double y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}
