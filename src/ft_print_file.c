/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 16:05:48 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/20 19:15:14 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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