#include <stdio.h>
#include <string.h>
#include "test.h"
#include "../Libft/libft.h"

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

void del(void *content)
{
	free(content);
}

void test(t_list **lst)
{
	print_list(*lst);

	printf(BOLDYELLOW"↓\nft_lstclear(lst, del)\n↓\n"RESET);
	ft_lstclear(lst, del);

	if (*lst != NULL)
	{
		printf(BOLDRED"print lst\n");
		print_list(*lst);
		printf(RESET);
	} else {
		printf(GREEN"lst is NULL\n"RESET);
	}
}

int main(void)
{
	t_list *first = ft_lstnew(ft_strdup("first lst"));
	t_list *second = ft_lstnew(ft_strdup("second lst"));
	first->next = second;

	printf("=================\n");
	printf("== usual input ==\n");
	printf("=================\n");
	test(&first);

	printf("\n===================\n");
	printf("== unusual input ==\n");
	printf("===================\n");
	printf("> *lst = NULL\n");
	t_list *nul = NULL;
	test(&nul);

	printf("\n↓leakcheck\n\n");
	while(1);
}
