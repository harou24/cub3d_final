/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:56:49 by haachtch      #+#    #+#                 */
/*   Updated: 2019/11/16 18:58:40 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	char	*tab;

	ptr = (void*)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	tab = (char*)ptr;
	i = 0;
	while (i < count * size)
	{
		tab[i] = 0;
		i++;
	}
	return (ptr);
}
