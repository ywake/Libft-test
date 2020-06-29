#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libft.h"

void print_list(t_list *lst)
{
	if (!lst)
	{
		printf("(null)\n");
		return ;
	}
	printf("▼▼▼ list elem ▼▼▼\n");
	printf("lst: %p\n", lst);
	printf("%p->content: %s\n", lst, lst->content);
	printf("%p->next   : %p\n", lst, lst->next);
	printf("▲▲▲  list elem  ▲▲▲\n");
	if (lst->next)
		print_list(lst->next);
}

void *free_list(t_list *lst)
{
	if (!lst)
		return NULL;
	free_list(lst->next);
	free(lst);
	return NULL;
}

void test(t_list **head, t_list *new, t_list *expect_next, char *expect)
{
	printf("print head\n");
	print_list(*head);
	printf("\n");
	printf("print new\n");
	print_list(new);

	printf(BOLDYELLOW"↓\nft_lstadd_back(head, new)\n↓\n"RESET);
	ft_lstadd_back(head, new);

	if (*head)
	{
		if (ft_strncmp((*head)->content, expect, strlen(expect)) == 0 && (*head)->next == expect_next)
			printf(GREEN);
		else
		{
			printf(BOLDRED);
			printf("]] strncmp      : %d\n", ft_strncmp((*head)->content, expect, strlen(expect)));
			printf("]] expect next  :%p\n", expect_next);
			printf("]] (*head)->next:%p\n", (*head)->next);
		}
		printf("print head\n");
		print_list(*head);
		printf(RESET);
		free_list(*head);
	} else {
		printf("*head is NULL\n");
	}
}

int main(void)
{
	t_list **head;
	t_list *new;
	head = (t_list **)ft_calloc(1, sizeof(t_list *));
	*head = ft_lstnew("first lst");
	new = ft_lstnew("second lst");

	printf("=================\n");
	printf("== usual input ==\n");
	printf("=================\n");
	test(head, new, new, "first lst");

	printf("\n===================\n");
	printf("== unusual input ==\n");
	printf("===================\n");
	printf("> head == NULL\n");
	t_list *nul = NULL;
	t_list *new2 = ft_lstnew("null test");
	test(&nul, new2, nul, "null test");
	printf("\n");
	printf("> new == NULL\n");
	t_list *head2 = ft_lstnew("null test2");
	t_list *nul2 = NULL;
	test(&head2, nul2, NULL, "");
	printf("\n");
	printf("> head, new == NULL\n");
	t_list *nul3 = NULL;
	t_list *nul4 = NULL;
	test(&nul3, nul4, NULL, "");

	printf("\n↓leakcheck\n\n");
	while(1);
}
