/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 13:37:19 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 18:37:16 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int		is_next_line(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	pos_next_line(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	if (ptr != NULL)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			ptr[i] = s2[j];
			i++;
			j++;
		}
		ptr[i] = '\0';
	}
	free(s1);
	return (ptr);
}

char	*ft_strnjoin(char *s1, char const *s2, size_t pos_max)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	if (ptr != NULL)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		while (j < pos_max)
		{
			ptr[i] = s2[j];
			i++;
			j++;
		}
		ptr[i] = '\0';
	}
	free(s1);
	return (ptr);
}
