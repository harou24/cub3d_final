/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 12:17:18 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 18:36:03 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		flood_fill(char **str, int x, int y, int nb_line)
{
	const static char	target[2] = {'0', '2'};
	const char			color = 'X';

	if (str[x][y] == '1' || str[x][y] == color)
		return (0);
	if (str[x][y] != target[0] && str[x][y] != target[1])
		return (0);
	str[x][y] = color;
	if (x + 1 < nb_line)
		flood_fill(str, x + 1, y, nb_line);
	if (x - 1 >= 0)
		flood_fill(str, x - 1, y, nb_line);
	if (y - 1 >= 0)
		flood_fill(str, x, y - 1, nb_line);
	if (y + 1 < (int)ft_strlen(str[x]))
		flood_fill(str, x, y + 1, nb_line);
	if (x + 1 < nb_line && y + 1 < (int)ft_strlen(str[x]))
		flood_fill(str, x + 1, y + 1, nb_line);
	if (x + 1 < nb_line && y - 1 >= 0)
		flood_fill(str, x + 1, y + 1, nb_line);
	if (x - 1 >= 0 && y + 1 < (int)ft_strlen(str[x]))
		flood_fill(str, x - 1, y + 1, nb_line);
	if (x - 1 >= 0 && y - 1 >= 0)
		flood_fill(str, x - 1, y - 1, nb_line);
	return (1);
}
