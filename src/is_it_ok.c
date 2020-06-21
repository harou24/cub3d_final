/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_it_ok.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 16:09:23 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/19 15:36:28 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		is_empty_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
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

int		is_texture_ok(char *line)
{
	if (!(line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W'))
		return (0);
	if (!(line[1] == ' ' || line[1] == 'O' || line[1] == 'E' || line[1] == 'A'))
		return (0);
	return (is_path_ok(line));
}
