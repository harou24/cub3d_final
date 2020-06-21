/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:01:36 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/21 17:39:51 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char*)str;
	while (*ptr != c)
	{
		if (!*ptr)
			return (NULL);
		ptr++;
	}
	return (ptr);
}
