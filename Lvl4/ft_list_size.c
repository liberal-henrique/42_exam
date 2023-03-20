// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c, ft_list.h
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that returns the number of elements in the linked list that's
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure, and turn it in as a file called
// ft_list.h:
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int	index;
	t_list	*curr;

	index = 0;
	curr = begin_list;
	while (curr)
	{
		index++;
		curr = curr->next;
	}
	return (index);
}

// testing

void	insert_end(t_list **root, int value)
{
	t_list	*new_node;
	t_list	*curr;

	curr = *root;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = (void *)(&value);
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	deallocate(t_list **root)
{
	t_list	*curr;
	t_list	*temp;

	curr = *root;
	while (curr->next != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*root = NULL;
}

int	print_list(t_list *root)
{
	t_list	*curr;
	int		index;

	curr = root;
	index = 0;
	while (curr != NULL)
	{
		index++;
		curr = curr->next;
	}
	return (index);
}

int	main(void)
{
	t_list	*list_a = NULL;

	insert_end(&list_a, 5);
	insert_end(&list_a, 5);
	insert_end(&list_a, 5);
	//print_list(list_a);

	printf("%i", ft_list_size(list_a));
	deallocate(&list_a);
	return (0);
}
