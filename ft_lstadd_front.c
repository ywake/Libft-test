#include <stdio.h>
#include <string.h>
#include "test.h"
#include "../Libft/libft.h"

void test(t_list **head, t_list *new, char *expect)
{
	t_list *old_head;

	old_head = *head;
	printf("head: %p\n", *head);
	printf("head->content: %s\n", (*head)->content);
	printf("head->next   : %p\n", (*head)->next);
	printf("new: %p\n", new);
	printf("new->content: %s\n", new->content);
	printf("new->next   : %p\n", new->next);

	printf("↓\nft_lstaddfront(head, new)\n↓\n");
	ft_lstadd_front(head, new);
	if (ft_strncmp((*head)->content, expect, strlen(expect)) == 0 && (*head)->next == old_head)
		printf(GREEN);
	else
		printf(BOLDRED);
	printf("head->content: %s\n", (*head)->content);
	printf("head->next   : %p\n", (*head)->next);
	printf("next->content: %s\n", (*head)->next->content);
	printf("next->next   : %p\n", (*head)->next->next);
	printf(RESET);
	free((*head)->next);
	free(*head);
}

int main(void)
{
	t_list **head;
	t_list *new;
	head = (t_list **)ft_calloc(1, sizeof(t_list *));
	*head = ft_lstnew("first lst");
	new = ft_lstnew("second lst");

	printf("== usual input ==\n");
	test(head, new, "second lst");

	printf("== usual input ==\n");
	// printf("head == NULL\n");
	// test(NULL, new, "null");
	printf("new == NULL\n");
	test(head, NULL, "null");
	// printf("head, new == NULL\n");
	// test(NULL, NULL, "null");

	printf("\n↓leakcheck\n\n");
	while(1);
}
