#include <stdio.h>
#include <string.h>
#include "test.h"
#include "../Libft/libft.h"

void test(t_list *lst, int expect)
{
	int rtn = ft_lstsize(lst);

	rtn == expect ? printf(GREEN) : printf(BOLDRED);
	printf("expect: %d\n", expect);
	printf("rtn   : %d\n", rtn);
	printf(RESET);
}

int main(void)
{
	t_list **head;
	t_list *new;
	head = (t_list **)ft_calloc(1, sizeof(t_list *));
	*head = ft_lstnew("first lst");
	new = ft_lstnew("second lst");
	ft_lstadd_front(head, new);

	printf("== usual input ==\n");
	test(*head, 2);

	printf("== usual input ==\n");
	printf("> NULL input\n");
	test(NULL, 0);

	free((*head)->next);
	free(*head);

	printf("\n↓leakcheck\n\n");
	while(1);
}
