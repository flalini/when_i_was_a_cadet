/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:25:57 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 21:49:59 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

char *g_strings[] = {
	"This is very very very long",
	"This is shorter",
	"Hello",
	"World",
	"From",
	"Biggy\250Char",
	"42",
	"",
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in"
	"malesuada purus. Etiam a scelerisque massa. Ut non euismod elit."
	"Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce"
	"vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam"
	"augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna"
	"ex, mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et"
	"lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere"
	"tortor, sit amet consequat amet.",
	NULL
};

int	main(void)
{
	ft_strlen_test();
	ft_strcpy_test();
	ft_strcmp_test();
	ft_write_test();
	ft_read_test();
	ft_strdup_test();
	ft_atoi_base_test();
	ft_list_push_front_test();
	ft_list_size_test();
	ft_list_sort_test();
	ft_list_remove_if_test();
}
