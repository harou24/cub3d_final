/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 17:08:21 by haachtch      #+#    #+#                 */
/*   Updated: 2019/11/07 19:26:47 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digitlen(long nb)
{
	size_t	size;

	if (nb == 0)
		return (nb + 1);
	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static int		ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	long	long_n;
	long	len;
	char	*fresh;

	long_n = n;
	len = ft_digitlen(long_n);
	if (len == 0)
		len = 1;
	fresh = (char *)malloc((len + 1) * sizeof(char));
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	len--;
	if (long_n < 0)
		long_n = -long_n;
	while (len >= 0)
	{
		fresh[len] = (long_n % 10) + '0';
		len--;
		long_n /= 10;
	}
	if (ft_sign(n))
		fresh[0] = '-';
	return (fresh);
}
