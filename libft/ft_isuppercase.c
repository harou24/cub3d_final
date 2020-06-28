/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isuppercase.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:19:35 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:19:39 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isuppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
