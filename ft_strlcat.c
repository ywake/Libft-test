#include <stdio.h>
#include <string.h>
#include "./test.h"
#include "../ft_strlcat.c"
#include "../ft_strlen.c"

void	test(char *dst, char *dst_orig, char *src, size_t size){
	char errorFlg = 0b0;

	printf("> \"%s\" + \"%s\" size:%zu\n", dst, src, size);

	size_t	rtn_orig = strlcat(dst_orig, src, size);
	size_t	rtn = ft_strlcat(dst, src, size);
	if (strcmp(dst_orig,dst) != 0 || rtn_orig != rtn)
		errorFlg = 1;

	errorFlg != 1 ? printf(GREEN) : printf(BOLDRED);
	printf("   strlcat() => rtn:`%zu` dst:`%s`\n", rtn_orig, dst_orig);
	printf("ft_strlcat() => rtn:`%zu` dst:`%s`\n", rtn, dst);
	printf(RESET);
	if (errorFlg)
		printf(YELLOW"strcmp():%d\nrtn_orig == rtn:%d\n"RESET, strcmp(dst_orig,dst), rtn_orig==rtn);
}

int		main(void)
{
	printf("-----------------------------\n");
	printf("--- start test ft_strlcat ---\n");
	printf("-----------------------------\n");

	char *src[] = {
		"nrml",
		"normal",
		"errorerror",
		"",
		NULL
	};
	size_t size[] = {
		4,
		6,
		7,
		8,
		10,
		0,
		666
	};
	int i = 0;
	int j = 0;
	while (src[i])
	{
		while (size[j] != 666)
		{
			char dst[10] = {'d','s','t','\0','X','X','X','X','X','X'};
			char dst_orig[10] = {'d','s','t','\0','X','X','X','X','X','X'};
			test(dst, dst_orig, src[i], size[j]);
			j++;
		}
		j = 0;
		i++;
	}

	// printf("> dst=NULL check (=>seg fault OK)\n");
	// test(NULL, NULL, src[0], 4);
	// strlcpy(NULL,"NULL test", 4);
	// ft_strlcpy(NULL,"dst=NULL", 4);

	char *dest;
	char *dest_org;
	int dest_len = 15;
	if (!(dest = (char *)malloc(sizeof(*dest) * dest_len)))
		return (0);
	if (!(dest_org = (char *)malloc(sizeof(*dest) * dest_len)))
		return (0);
	memset(dest, 0, dest_len);
	memset(dest_org, 0, dest_len);
	memset(dest, 'r', 6);
	memset(dest_org, 'r', 6);
	dest[10] = 'a';
	test(dest, dest_org, "lorem ipsum dolor sit amet",  1);
	// printf("> src=NULL check (=>seg fault OK)\n");
	// test(dst, dst_orig, NULL, 4);
	// // strlcpy("src=NULL", NULL, 4);
	// ft_strlcpy("src=NULL", NULL, 4);
}
