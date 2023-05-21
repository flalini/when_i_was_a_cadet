typedef struct		s_list
{
	void 			*data;
	struct s_list	*next;
}					t_list;
extern void			free(void *prt);

void
	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(void *, void *), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (!begin_list || !(*begin_list))
		return ;
	current = *begin_list;
	while (current)
	{
		while (current->next && (*cmp)(current->next->data, data_ref) == 0)
		{
			tmp = current->next;
			current->next = tmp->next;
			free_fct(tmp->data);
			free(tmp);
		}
		current = current->next;
	}
	if ((*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = tmp->next;
		free_fct(tmp->data);
		free(tmp);
	}
}
