/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_it_ok.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 16:09:23 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 18:38:47 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int		is_path_ok(char *str)
{
	char	*s;

	s = ft_strchr(str, ' ');
	if (s == NULL)
		return (-1);
	if (ft_strlen(s) > 4)
		return (1);
	return (0);
}

int				is_texture_ok(char *line, t_config *conf)
{
	if (get_line_id(line) == 'N' && conf->textures[0] != NULL)
		print_error("Error\nNorth Texture already set !\n");
	if (get_line_id(line) == 'S' && conf->textures[1] != NULL)
		print_error("Error\nSouth Texture already set !\n");
	if (get_line_id(line) == 'W' && conf->textures[2] != NULL)
		print_error("Error\nEast Texture already set !\n");
	if (get_line_id(line) == 'E' && conf->textures[3] != NULL)
		print_error("Error\nWest Texture already set !\n");
	if (get_line_id(line) == 'P' && conf->textures[4] != NULL)
		print_error("Error\nSprite Texture already set !\n");
	if (!(line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W'))
		return (0);
	if (!(line[1] == ' ' || line[1] == 'O' || line[1] == 'E' || line[1] == 'A'))
		return (0);
	if (conf == NULL)
		return (0);
	if (is_path_ok(line) == 1)
		return (1);
	return (0);
}

void			set_texture(t_config *conf, char *str)
{
	int		i;

	i = 2;
	if (!is_texture_ok(str, conf))
		print_error("Texture Error !");
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	if (get_line_id(str) == 'N')
		conf->textures[0] = ft_substr(str, i, ft_strlen(str) - i);
	else if (get_line_id(str) == 'S')
		conf->textures[1] = ft_substr(str, i, ft_strlen(str) - i);
	else if (get_line_id(str) == 'W')
		conf->textures[2] = ft_substr(str, i, ft_strlen(str) - i);
	else if (get_line_id(str) == 'E')
		conf->textures[3] = ft_substr(str, i, ft_strlen(str) - i);
	else if (get_line_id(str) == 'P')
		conf->textures[4] = ft_substr(str, i, ft_strlen(str) - i);
}
