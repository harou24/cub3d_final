/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_it_ok.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 16:09:23 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/22 21:44:50 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		is_empty_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_iswhitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int		is_upper_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		is_path_ok(char *str)
{
	int		i;

	i = 0;
	while (is_upper_case(str[i]) || str[i] == ' ')
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
		i += 2;
	else
		return (0);
	while (str[i])
	{
		if (!(str[i] > '!' && str[i] <= '~'))
			return (0);
		i++;
	}
	return (1);
}

int		is_texture_ok(char *line, t_config *conf)
{
	if (get_line_id(line) == 'N' && conf->textures[0] != NULL)
		print_error ("Error\nNorth Texture already set !\n");
	if (get_line_id(line) == 'S' && conf->textures[1] != NULL)
		print_error ("Error\nSouth Texture already set !\n");
	if (get_line_id(line) == 'E' && conf->textures[2] != NULL)
		print_error ("Error\nEast Texture already set !\n");
	if (get_line_id(line) == 'W' && conf->textures[3] != NULL)
		print_error ("Error\nWest Texture already set !\n");
	if (get_line_id(line) == 'P' && conf->textures[4] != NULL)
		print_error ("Error\nSprite Texture already set !\n");
	if (!(line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W'))
		return (0);
	if (!(line[1] == ' ' || line[1] == 'O' || line[1] == 'E' || line[1] == 'A'))
		return (0);
	if(conf==NULL)
		return (0);
		return (is_path_ok(line));
}
