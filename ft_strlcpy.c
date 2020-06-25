#include <stdio.h>
#include <string.h>
#include "test.h"
#include "../Libft/libft.h"

void	test(int dst_buf,char *dst, char *dst_orig, char *src, size_t size){
	char errorFlg = 0b0;

	size_t	rtn_orig = strlcpy(dst_orig, src, size);
	size_t	rtn = ft_strlcpy(dst, src, size);

	if (strcmp(dst_orig,dst) != 0 || rtn_orig != rtn)
		errorFlg = 1;

	printf("> \"%s\" dst_buf:%d size:%zu\n", src, dst_buf, size);
	errorFlg != 1 ? printf(GREEN) : printf(BOLDRED);
	printf("   strlcpy(dst, src:\"%s\", size:%zu ) => rtn:`%zu` dst:`%s`\n",src,size, rtn_orig, dst_orig);
	printf("ft_strlcpy(dst, src:\"%s\", size:%zu ) => rtn:`%zu` dst:`%s`\n",src,size, rtn, dst);
	printf(RESET);
	if (errorFlg)
		printf(YELLOW"strcmp():%d\nrtn_orig == rtn:%d\n"RESET, strcmp(dst_orig,dst), rtn_orig==rtn);
}

int		main(void)
{
	printf("-----------------------------\n");
	printf("--- start test ft_strlcpy ---\n");
	printf("-----------------------------\n");

	int i = 0;
	char *src[] = {
		"test1",
		"test2",
		"test3",
		"test4",
		"test5",
		"test6",
		"test7",
		"test8",
		NULL
	};
	int dst_buf[] = {15, 15, 15, 3, 3, 3, 0, 0};
	size_t size[] = { 5,  1, 15, 3, 5, 0, 1, 0};

	while (src[i])
	{
		char dst[dst_buf[i]];
		char dst_orig[dst_buf[i]];
		test(dst_buf[i], dst, dst_orig, src[i], size[i]);
		i++;
	}

	printf("> size=0 check\n");
	char *dst = "size=0";
	char *dst_orig = "size=0";
	test(7, dst, dst_orig, "write", 0);

	// printf("> dst=NULL check (=>seg fault OK)\n");
	// // strlcpy(NULL,"NULL test", 4);
	// ft_strlcpy(NULL,"dst=NULL", 4);

	// printf("> src=NULL check (=>seg fault OK)\n");
	// // strlcpy("src=NULL", NULL, 4);
	// ft_strlcpy("src=NULL", NULL, 4);

	printf("\n↓leakcheck\n\n");
	while(1);
}
