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

void del(void *content)
{
	free(content);
}

void test(t_list *first, t_list *second)
{
	print_list(first);
	printf("\n");

	printf(BOLDYELLOW"↓\nft_lstdelone(first, second)\n↓\n"RESET);
	ft_lstdelone(first, del);

	if (first != NULL)
	{
		if (first->content == NULL)
		{
			printf(GREEN"print first\n");
			print_list(first);
			printf("print second\n");
			print_list(second);
			printf(RESET);
		} else {
			printf(BOLDRED"print first\n");
			print_list(first);
			printf("print second\n");
			print_list(second);
			printf(RESET);
		}
	} else {
		printf("first is NULL\n");
	}
	ft_lstdelone(second, del);
	// if (ft_strncmp((*head)->content, expect, strlen(expect)) == 0 && (*head)->next == expect_next)
	// if (*head)
	// {
	// 		printf(GREEN);
	// 	else
	// 	{
	// 		printf(BOLDRED);
	// 		printf("]] strncmp      : %d\n", ft_strncmp((*head)->content, expect, strlen(expect)));
	// 		printf("]] expect next  :%p\n", expect_next);
	// 		printf("]] (*head)->next:%p\n", (*head)->next);
	// 	}
	// 	printf("print head\n");
	// 	print_list(*head);
	// 	printf(RESET);
	// 	free_list(*head);
	// } else {
	// 	printf("*head is NULL\n");
	// }
}

int main(void)
{
	t_list *first = ft_lstnew(ft_strdup("first lst"));
	t_list *second = ft_lstnew(ft_strdup("second lst"));
	first->next = second;

	printf("=================\n");
	printf("== usual input ==\n");
	printf("=================\n");
	test(first, second);

	printf("\n===================\n");
	printf("== unusual input ==\n");
	printf("===================\n");
	printf("> NULL input\n");
	t_list *nul = NULL;
	t_list *second2 = ft_lstnew(ft_strdup("second lst"));
	test(nul, second2);
	// printf("\n");
	// printf("> new == NULL\n");
	// t_list *head2 = ft_lstnew("null test2");
	// t_list *nul2 = NULL;
	// test(&head2, nul2, NULL, "");
	// printf("\n");
	// printf("> head, new == NULL\n");
	// t_list *nul3 = NULL;
	// t_list *nul4 = NULL;
	// test(&nul3, nul4, NULL, "");

	printf("\n↓leakcheck\n\n");
	while(1);
}
