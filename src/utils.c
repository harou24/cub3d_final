/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 12:29:21 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/19 15:38:52 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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
}
