/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:06:35 by ijang             #+#    #+#             */
/*   Updated: 2020/10/31 15:53:03 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' ||
			*str == '\r' || *str == ' ')
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		++str;
	}
	while (*str > 47 && *str < 58)
	{
		result = (result * 10) + *(str++) - '0';
	}
	return (result * sign);
}
