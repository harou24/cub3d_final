/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_it_ok3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 17:29:47 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/19 15:36:56 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		are_bounderies_ok(char *line)
{
	int		i;

	i = 0;
	if (line[i] == 'X' || line[ft_strlen(line) - 1] == 'X')
		return (0);
	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] == 'X')
			return (0);
		if (line[i] == 'X' && line[i + 1] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int		is_map_valid(t_config *conf)
{
	int		i;

	i = 0;
	while (i < conf->nb_line - 8)
	{
		if (!are_bounderies_ok(conf->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int		is_column_ok(t_config *conf)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < conf->nb_line - 8)
	{
		j = 0;
		while (j < conf->max_line)
		{
			if (conf->map[i][j] == 'X' && conf->map[i + 1][j] == ' ')
				printf("NO|%c|", conf->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
