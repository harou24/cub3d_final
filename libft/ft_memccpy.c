/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:48:41 by haachtch      #+#    #+#                 */
/*   Updated: 2019/11/16 21:40:47 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*destptr;
	unsigned char	cc;
	size_t			i;
	int				flag;

	ptr = (unsigned char *)src;
	destptr = (unsigned char *)dest;
	cc = (unsigned char)c;
	flag = 0;
	i = 0;
	while (i < n)
	{
		destptr[i] = ptr[i];
		if (ptr[i] == cc)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 1)
		return (destptr + i + 1);
	else
		return (NULL);
}
