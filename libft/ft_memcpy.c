/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:14:08 by haachtch      #+#    #+#                 */
/*   Updated: 2019/11/08 11:25:17 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*destptr;
	size_t			i;

	ptr = (unsigned char *)src;
	destptr = (unsigned char *)dest;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		destptr[i] = ptr[i];
		i++;
	}
	return (destptr);
}
