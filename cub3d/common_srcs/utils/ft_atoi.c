/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:54:04 by ijang             #+#    #+#             */
/*   Updated: 2020/11/14 17:28:55 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int result;
	int sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' ||
			str[i] == '\r' || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + str[i++] - '0';
	return (result * sign);
}
