#include <stdio.h>
#include <string.h>
#include "test.h"
#include "../Libft/libft.h"

void test(void *content)
{
	t_list *list;

	list = ft_lstnew(content);
	if (list->content == content && list->next == NULL)
		printf(GREEN);
	else
		printf(BOLDRED);
	printf("list->content: %s\n", list->content);
	printf("list->next   : %p\n", list->next);
	printf(RESET);
	free(list);
}

int main(void)
{
	test("this is test.");

	printf("\n↓leakcheck\n\n");
	while(1);
}