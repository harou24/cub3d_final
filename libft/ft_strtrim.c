/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:50:12 by haachtch      #+#    #+#                 */
/*   Updated: 2019/11/17 14:52:52 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_in(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_count2(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	while (s1[i])
	{
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		if (ft_is_in(s1[i], (char*)set))
		{
			j++;
			res++;
		}
		else
			break ;
		i--;
	}
	return (res);
}

static int		ft_count(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	while (s1[i])
	{
		if (ft_is_in(s1[i], (char*)set))
		{
			j++;
			res++;
		}
		else
			break ;
		i++;
	}
	return (res);
}

static char		*ft_check(char *ptr, int a, int b, int c)
{
	if (a != b)
		ptr = (char*)malloc((c - (a + b)) + 1);
	else if (a == b)
	{
		ptr = (char*)malloc((c - (a)) + 1);
	}
	else
	{
		ptr = (char*)malloc(1);
		ptr[0] = '\0';
	}
	return (ptr);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		i2;
	int		i3;
	int		j;
	char	*ptr;

	if (!s1)
		return (NULL);
	i = ft_count(s1, set);
	i2 = ft_count2(s1, set);
	i3 = ft_strlen(s1);
	j = 0;
	ptr = NULL;
	ptr = ft_check(ptr, i, i2, i3);
	if (ptr != NULL)
	{
		while (i < i3 - i2)
		{
			ptr[j] = s1[i];
			j++;
			i++;
		}
		ptr[j] = '\0';
	}
	return (ptr);
}
