/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 10:30:33 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/23 21:30:22 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void		print_error(char *s)
{
	ft_putstr_fd(s, 1);
	exit(0);
}

void		set_texture(t_config *conf, char *str)
{
	int		i;

	i = 2;
	if (!is_texture_ok(str, conf))
		print_error("Texture Error !");
	while(str[i] && ft_iswhitespace(str[i]))
		i++;
	if (get_line_id(str) == 'N')
		conf->textures[0] = ft_substr(str, i, ft_strlen(str) - i);
	else if (get_line_id(str) == 'S')
		conf->textures[1] = ft_substr(str, i, ft_strlen(str) - i);
	else if (get_line_id(str) == 'E')
		conf->textures[2] = ft_substr(str, i, ft_strlen(str) - i);
	else if (get_line_id(str) == 'W')
		conf->textures[3] = ft_substr(str, i, ft_strlen(str) - i);
	else if (get_line_id(str) == 'P')
		conf->textures[4] = ft_substr(str, i, ft_strlen(str) - i);
}

void		set_position(t_config *conf, char *line, int y)
{
	int		i;

	i = 0;
	if(conf->direction != 'Z')
		print_error("Error\n!!! Direction Already Set !!!\n");
	conf->posY = y;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W')
		{
			conf->posX = i;
			conf->direction = line[i];
			line[i] = '0';
			break ;
		}
		i++;
	}
}

void		set_map(t_config *conf, char *str)
{
	static int	j;

	if (is_position_in_line(str))
		set_position(conf, str, j);
	if (!is_line_valid(str))
		print_error("Invalid Map");
	printf("ligne : - > %s\n",str);
	conf->map[j] = ft_strdup2(str, conf->max_line);
	j++;
}


t_config	parse_map(char *argv)
{
	t_config	conf;
	char		**file;

	conf = new_config();
	file = cpy_cube_file(argv, &conf);
	get_config(file, &conf);
	if(conf.nb_line < 9)
		print_error("Error\nNo map\n");
	get_sprites(&conf);
	flood_fill(conf.map, conf.posY, conf.posX, conf.nb_line - 8);
	if (!is_map_valid(&conf))
		print_error("invalid map !!!! \n");
	printf("MAP : \n");
	print(file,conf.nb_line);
	printf("-------------------\n\n");
	print(conf.map, conf.nb_line - 8);
	magic_free(file, conf.nb_line);
	printf("%d\n", conf.max_line);
	return (conf);
}
