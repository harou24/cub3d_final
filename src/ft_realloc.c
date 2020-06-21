/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 12:28:52 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/19 15:32:25 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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
