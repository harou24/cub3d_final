/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 16:40:02 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/23 18:52:13 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		get_red(char *str)
{
	int		i;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	if (ft_isdigit(str[i]))
		return (ft_atoi_at_index(str, i));
	return (-1);
}

int		get_green(char *str)
{
	int		i;

	i = 0;
	while (str[i] != ',')
		i++;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	return (ft_atoi_at_index(str, i));
}

int		get_blue(char *str)
{
	int		i;

	i = ft_strlen(str);
	while (!ft_isdigit(str[i]) && i > 0)
		i--;
	while (ft_isdigit(str[i]) && i > 0)
		i--;
	return (ft_atoi_at_index(str, i + 1));
}

void	confirm(int tab[])
{
	int		i;

	i = 0;
	while(i < 3)
	{
		if(tab[i] < 0 || tab[i] > 255)
			print_error("COLOR ERROR\n");
		i++;
	}
}

void	set_color(t_config *conf, char *str)
{
	int		i;

	i = 0;
	if (!is_color_ok(str))
		print_error("Color Error !");
	if (str[0] == 'C')
	{
		if (conf->rgb_ceiling[0] != -1)
			print_error("Error\nColor Already Set !\n");
		conf->rgb_ceiling[0] = get_red(str);
		conf->rgb_ceiling[1] = get_green(str);
		conf->rgb_ceiling[2] = get_blue(str);
		confirm(conf->rgb_ceiling);
	}
	else if (str[0] == 'F')
	{
		if (conf->rgb_floor[0] != -1)
			print_error("Error\nColor Already Set !\n");
		conf->rgb_floor[0] = get_red(str);
		conf->rgb_floor[1] = get_green(str);
		conf->rgb_floor[2] = get_blue(str);
		confirm(conf->rgb_floor);
	}
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
