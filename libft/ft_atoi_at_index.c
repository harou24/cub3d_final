/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 12:04:23 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 15:03:30 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_at_index(const char *str, int i)
{
	unsigned long int	nb;
	int					neg;
	int					count;

	neg = 1;
	nb = 0;
	count = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && count < 8)
	{
		nb = nb * 10;
		nb = (nb + str[i]) - 48;
		count++;
		i++;
	}
	if (nb >= 9223372036854775807 && neg == -1)
		return (0);
	return (nb * neg);
}
