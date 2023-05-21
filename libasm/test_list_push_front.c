typedef struct		s_list
{
	void 			*data;
	struct s_list	*next;
}					t_list;
extern void			*malloc();

void
	ft_list_push_front(t_list **begin_list, void *data)
{
	if (!begin_list)
		return ;
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return ;
	tmp->data = data;
	tmp->next = *begin_list;
	*begin_list = tmp;
}
