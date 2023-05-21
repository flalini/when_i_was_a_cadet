/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:54:19 by ijang             #+#    #+#             */
/*   Updated: 2020/12/15 22:34:34 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_list
{
	void 			*data;
	struct s_list	*next;
}					t_list;

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*find;

	if (!begin_list || !(*begin_list))
		return ;
	tmp = *begin_list;
	while (tmp->next)
	{
		if ((*cmp)(tmp->data, tmp->next->data) > 0)
		{
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			if ((*cmp)((*begin_list)->data, tmp2->data) > 0)
			{
				tmp2->next = *begin_list;
				*begin_list = tmp2;
			}
			else
			{
				find = *begin_list;
				while ((*cmp)(tmp2->data, find->next->data) > 0)
					find = find->next;
				tmp2->next = find->next;
				find->next = tmp2;
			}
		}
		else
			tmp = tmp->next;
	}
}