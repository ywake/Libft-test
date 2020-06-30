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

void *puls1(void *s)
{
	char *str = strdup((char *)s);
	int i = 0;
	while (str[i])
		str[i++] += 1;
	return (str);
}

void del(void *content)
{
	free(content);
}

void test(t_list *lst)
{
	t_list *new;
	print_list(lst);

	printf(BOLDYELLOW"↓\nft_lstmap(lst, puls1, del)\n↓\n"RESET);
	new = ft_lstmap(lst, puls1, del);

	if (new != NULL)
	{
		printf(BOLD"print new lst\n");
		print_list(new);
		printf(RESET);
	} else {
		printf(BOLD"new is NULL\n"RESET);
	}
	ft_lstclear(&lst, del);
	ft_lstclear(&new, del);
}

int main(void)
{
	t_list *first = ft_lstnew(ft_strdup("First lst"));
	t_list *second = ft_lstnew(ft_strdup("Second lst"));
	first->next = second;

	printf("=================\n");
	printf("== usual input ==\n");
	printf("=================\n");
	test(first);

	printf("\n===================\n");
	printf("== unusual input ==\n");
	printf("===================\n");
	printf("> *lst = NULL\n");
	t_list *nul = NULL;
	test(nul);

	printf("\n↓leakcheck\n\n");
	while(1);
}
