#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main() {
	int ret;
//	char *-12 = "asdf";
//        ft_printf("%-010x\n", -12);
        ret = ft_printf("[%-020.2d]", -12);
		ft_printf(" : %d\n", ret);
		ret = ft_printf("[%0.4d]", -12);
		ft_printf(" : %d\n", ret);
		ret = ft_printf("[%20d]", -12);
		ft_printf(" : %d\n", ret);
		ret = ft_printf("[%-20d]", -12);
		ft_printf(" : %d\n", ret);
		ret = ft_printf("[%020p]", -12);
		ft_printf(" : %d\n", ret);
		ret = ft_printf("[%020.p]", -12);
		ft_printf(" : %d\n", ret);
//		ft_printf("%10.5x\n", -12);
//		ft_printf("%10x\n", -12);
//		ft_printf("%-10x\n", -12);
//		ft_printf("%010x\n", -12);
//		ft_printf("%010.x\n", -12);
		ft_printf("------------\n");
        ret = printf("[%-020.2d]", -12);
		printf(" : %d\n", ret);
		ret = printf("[%0.4d]", -12);
		printf(" : %d\n", ret);
		ret = printf("[%20d]", -12);
		printf(" : %d\n", ret);
		ret = printf("[%-20d]", -12);
		printf(" : %d\n", ret);
		ret = printf("[%020p]", -12);
		printf(" : %d\n", ret);
		ret = printf("[%020.p]", -12);
		printf(" : %d\n", ret);
        return (0);
}

