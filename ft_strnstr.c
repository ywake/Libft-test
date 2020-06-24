#include <stdio.h>
#include <string.h>
#include "./test.h"
#include "../ft_strnstr.c"
#include "../ft_strncmp.c"
#include "../ft_strlen.c"
#include "../ft_strchr.c"

char *repeat(char *str, char c, int num)
{
	int i = 0;
	while (i < num)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void	test(char *heystack, char *needle, size_t size){
	char errorFlg = 0b0;

	printf(" -- size = %zu --\n", size);
	printf("    \"%s\"\n", heystack);
	char	*org_rtn = strnstr(heystack, needle, size);
	// char	*ft_rtn = strnstr(heystack, needle, size);
	// char	*org_rtn = ft_strnstr(heystack, needle, size);
	char	*ft_rtn = ft_strnstr(heystack, needle, size);
	(org_rtn == NULL && ft_rtn == NULL) ? printf(GREEN) : printf(RED);
	if (org_rtn == NULL)
		printf("orig: NULL\n");
	if (ft_rtn == NULL)
		printf("ft  : NULL\n");
	if (ft_rtn == NULL || org_rtn == NULL){
		printf(RESET);
		return;
	}

	if (org_rtn[0] != ft_rtn[0])
		errorFlg = 1;
	errorFlg ? printf(BOLDRED) : printf(GREEN);
	char tmp[org_rtn-heystack+1];
	char tmp2[ft_rtn-heystack+1];
	for (long i = 0; i < org_rtn-heystack+1; i++)
		tmp[i] = 0;
	for (long i = 0; i < ft_rtn-heystack+1; i++)
		tmp2[i] = 0;
	printf("org: %s^ %ld\n", repeat( tmp,' ', (int)(ft_rtn - heystack)), org_rtn-heystack);
	printf("ft : %s^ %ld\n", repeat( tmp2,' ', (int)(ft_rtn - heystack)), ft_rtn-heystack);
	printf(RESET);
	// if (errorFlg)
	// 	printf(YELLOW"strcmp():%d\nrtn_orig == ft_rtn:%d\n"RESET, strcmp(dst_orig,dst), rtn_orig==rtn);
}

int		main(void)
{
	printf("-----------------------------\n");
	printf("--- start test ft_strnstr ---\n");
	printf("-----------------------------\n");

	char *heystack = "Foo Bar Baz";
	char *needle[] = {
		"Foo",
		"Bar",
		"Baz",
		"",
		NULL
	};
	size_t size[] = {
		0, 1, 3, 4, 5, 7, 11, 15, 999
	};
	int i = 0;
	while (needle[i])
	{
		printf("\n> search '%s' in \"%s\"\n", needle[i], heystack);
		int j = 0;
		while (size[j] != 999)
		{
			test(heystack, needle[i], size[j]);
			j++;
		}
		i++;
	}

	// printf("\n> heystack == NULL\n");
	// test(NULL, needle[1], 15);
	// printf("\n> needle == NULL\n");
	// test(heystack, NULL, 15);
}
