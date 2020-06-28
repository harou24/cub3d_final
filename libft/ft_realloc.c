/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:20:17 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:20:20 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *s, size_t n)
{
	void	*copy;

	copy = malloc(n);
	if (s != NULL)
	{
		copy = ft_memcpy(copy, s, n);
		free(s);
	}
	return (copy);
}
