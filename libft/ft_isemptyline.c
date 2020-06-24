/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isemptyline.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 11:56:22 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/24 11:58:07 by haachtch      ########   odam.nl         */
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
