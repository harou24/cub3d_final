/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/21 19:15:38 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/23 21:01:37 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup2(const char *s, int max)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char*)malloc(ft_strlen(s) + max);
	if (ptr != NULL)
	{
		while (s[i])
		{
			ptr[i] = s[i];
			if (ptr[i] == ' ')
				ptr[i] = '0';
			i++;
		}
		while (i < max)
		{
			ptr[i] = '0';
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
