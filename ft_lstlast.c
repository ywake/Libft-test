#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libft.h"

void test(t_list *lst, t_list *expect)
{
	t_list *rtn = ft_lstlast(lst);

	rtn == expect ? printf(GREEN) : printf(BOLDRED);
	printf("expect: %p\n", expect);
	printf("rtn   : %p\n", rtn);
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

	printf("== usual intput ==\n");
	test(*head, new->next);

	printf("== unusual intput ==\n");
	printf("> NULL input\n");
	test(NULL, NULL);

	free((*head)->next);
	free(*head);

	printf("\n↓leakcheck\n\n");
	while(1);
}
