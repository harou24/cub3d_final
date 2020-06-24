/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 12:28:52 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/24 13:13:27 by haachtch      ########   odam.nl         */
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
