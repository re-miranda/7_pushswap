/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 00:07:44 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/28 00:44:19 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_safe(const char *str, int	*ptr)
{
	int			sign;
	long int	output;

	sign = 1;
	output = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		output *= 10;
		output += (int)(*str) - 48;
		str++;
	}
	output *= sign;
	if (output > 2147483647 || output < -2147483648)
		return (1);
	*ptr = (int)output;
	return (0);
}
