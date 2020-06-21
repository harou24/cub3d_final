/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:21:34 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/21 13:57:33 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*ss1 == '\0' && *ss2 == '\0')
			return (0);
		if (*ss1 != *ss2)
		{
			if (*ss1 > *ss2)
				return (1);
			else
				return (-1);
		}
		else
		{
			ss1++;
			ss2++;
		}
		n--;
	}
	return (0);
}
