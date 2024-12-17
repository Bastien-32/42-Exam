typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
