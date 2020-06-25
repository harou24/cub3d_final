/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 12:29:21 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 14:59:07 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

char	get_line_id(char *line)
{
	if (line[0] == 'S' && line[1] == ' ')
		return ('P');
	else
		return (line[0]);
	return ('Z');
}

int		get_next_map_value(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

int		get_last_map_value(char *line)
{
	int		i;

	i = ft_strlen(line);
	while (i > 0)
	{
		if (line[i] == 'X' || line[i] == '0'
				|| line[i] == '1' || line[i] == '2')
			break ;
		i--;
	}
	return (i);
}

void	magic_free(char **file, int nb_line)
{
	int		i;

	i = 0;
	while (i < nb_line)
	{
		free(file[i]);
		i++;
	}
	free(file);
}

int		is_color_ok(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	i = ft_strlen(line);
	count = 0;
	while (i > 0)
	{
		if (ft_isdigit(line[i]) && (line[i - 1] == ' ' || line[i - 1] == ','))
			count++;
		i--;
	}
	if (count == 3)
		return (1);
	return (0);
}
