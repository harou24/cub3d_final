/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:11:50 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:11:53 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print(char **file, int nb_line)
{
	int		i;

	i = 0;
	while (i < nb_line)
	{
		ft_putstr_fd(file[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
