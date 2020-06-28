/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isemptyline.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:19:13 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:19:17 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isemptyline(char *line)
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
