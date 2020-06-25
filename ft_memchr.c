#include <stdio.h>
#include <string.h>
#include "test.h"
#include "../Libft/libft.h"

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

void	test(char *src, char c, size_t len){
	char errorFlg = 0b0;

	printf("> where '%c' in \"%s\"\n", c, src);
	char	*rtn_orig = memchr(src, c, len);
	char	*rtn = ft_memchr(src, c, len);

	if (rtn_orig == NULL && rtn == NULL) {
		printf(GREEN);
		printf("orig: NULL\n");
		printf("ft  : NULL\n");
		printf(RESET);
		return;
	} else if (rtn_orig != NULL && rtn == NULL) {
		char tmp[rtn_orig-src+1];
		memset(tmp,0,rtn_orig-src+1);
		printf(RED);
		printf("orig:           %s^ '%c'%ld\n", repeat( tmp,' ', (int)(rtn_orig - src)), rtn_orig[0], rtn_orig-src);
		printf("ft  : NULL\n");
		printf(RESET);
		return;
	} else if (rtn_orig == NULL && rtn != NULL) {
		char tmp2[rtn-src+1];
		memset(tmp2,0,rtn-src+1);
		printf(RED);
		printf("orig: NULL\n");
		printf("ft  :           %s^ '%c'%ld\n", repeat( tmp2,' ', (int)(rtn - src)), rtn[0], rtn-src);
		printf(RESET);
		return;
	}

	if (rtn_orig[0] != rtn[0])
		errorFlg = 1;
	errorFlg != 1 ? printf(GREEN) : printf(BOLDRED);
	char tmp[rtn_orig-src+1];
	memset(tmp,0,rtn_orig-src+1);
	char tmp2[rtn-src+1];
	memset(tmp2,0,rtn-src+1);
	printf("orig:           %s^ '%c'%ld\n", repeat( tmp,' ', (int)(rtn_orig - src)), rtn_orig[0], rtn_orig-src);
	printf("ft  :           %s^ '%c'%ld\n", repeat( tmp2,' ', (int)(rtn - src)), rtn[0], rtn-src);
	printf(RESET);
	// if (errorFlg)
	// 	printf(YELLOW"strcmp():%d\nrtn_orig == rtn:%d\n"RESET, strcmp(dst_orig,dst), rtn_orig==rtn);
}

int		main(void)
{
	printf("-----------------------------\n");
	printf("--- start test ft_memchr ---\n");
	printf("-----------------------------\n");

	char *src = "let's test with supercalifragilisticexpialidocious.\200";
	char *c = "abcdefghijklmnopqrltuvwxyz .";
	int i = 0;
	size_t len = ft_strlen(src)+1;
	while (c[i])
	{
		test(src, c[i], len);
		i++;
	}

	printf("----- c == '\\200' -----\n");
	test(src, '\200', len);
	printf("----- c == '\\0' -----\n");
	test(src, '\0', len);

	// printf("----- src == empty -----\n");
	// char *src2 = "";
	// i = 0;
	// while (c[i])
	// {
	// 	test(src2, c[i]);
	// 	i++;
	// }
	printf("\n↓leakcheck\n\n");
	while(1);
}
