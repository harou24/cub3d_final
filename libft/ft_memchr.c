/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:48:45 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/21 14:05:29 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;
	int				find;

	ptr = (unsigned char*)s;
	find = 0;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			find = 1;
			break ;
		}
		i++;
	}
	if (find == 1)
		return (ptr + i);
	else
		return (NULL);
}
