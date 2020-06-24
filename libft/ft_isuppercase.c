/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isuppercase.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 11:46:31 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/24 11:47:57 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isuppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}