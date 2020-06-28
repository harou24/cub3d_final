/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:14:41 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:14:45 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void		print_error(char *s)
{
	ft_putstr_fd(s, 1);
	exit(0);
}

void		set_map(t_config *conf, char *str)
{
	static int	j;

	if (is_position_in_line(str))
		set_position(conf, str, j);
	if (!is_line_valid(str))
		print_error("Error\n!!!----------Invalid Map----------!!!\n");
	conf->map[j] = ft_strdup2(str, conf->max_line);
	j++;
}

t_config	new_parser(char *argv)
{
	t_config	conf;
	char		**file;

	conf = new_config();
	file = cpy_cube_file(argv, &conf, 0);
	get_config(file, &conf);
	if (conf.nb_line < 9)
		print_error("Error\n!!!----------No map----------!!!\n");
	get_sprites(&conf);
	flood_fill(conf.map, conf.pos_y, conf.pos_x, conf.nb_line - 8);
	if (!is_map_valid(&conf))
		print_error("Error\n!!!----------Invalid map----------!!!\n");
	get_sprites_back(&conf);
	ft_putstr_fd("O---------------------------------------------O\n\n", 1);
	ft_putstr_fd("File : \n", 1);
	print(file, conf.nb_line);
	ft_putstr_fd("O---------------------------------------------O\n\n", 1);
	magic_free(file, conf.nb_line);
	return (conf);
}
