/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 17:12:31 by haachtch      #+#    #+#                 */
/*   Updated: 2019/11/07 22:11:54 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		ft_count_nb_words(char const *str, char c)
{
	int		nb;
	size_t	i;

	i = 0;
	nb = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		nb++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (nb);
}

static char		*ft_next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static void		ft_clean(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	nbword;

	if (!s)
		return (NULL);
	nbword = ft_count_nb_words((char *)s, c);
	tab = (char**)malloc((nbword + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < nbword)
	{
		s = ft_next_word(s, c);
		tab[i] = ft_substr(s, 0, ft_word_length(s, c));
		if (tab[i] == NULL)
		{
			ft_clean(tab);
			return (NULL);
		}
		i++;
		s = s + ft_word_length(s, c);
	}
	tab[nbword] = NULL;
	return (tab);
}
