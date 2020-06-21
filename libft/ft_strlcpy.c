/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 18:01:37 by haachtch      #+#    #+#                 */
/*   Updated: 2019/11/16 18:26:18 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	i;

	if (dst == 0)
		return (0);
	lensrc = ft_strlen(src);
	i = 0;
	while (src[i] && dstsize != 0)
	{
		if (i == dstsize - 1)
			break ;
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	if (dstsize < lensrc)
		return (lensrc);
	return (i);
}
