#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char *, ...);

int main() {
	char *str = "asdf";
//        ft_printf("%-010x\n", str);
        ft_printf("[%-020p]\n", str);
		ft_printf("[%20.14p]\n", str);
		ft_printf("[%20p]\n", str);
		ft_printf("[%-20p]\n", str);
		ft_printf("[%020p]\n", str);
		ft_printf("[%020.p]\n", str);
//		ft_printf("%10.5x\n", str);
//		ft_printf("%10x\n", str);
//		ft_printf("%-10x\n", str);
//		ft_printf("%010x\n", str);
//		ft_printf("%010.x\n", str);
		ft_printf("------------\n");
        printf("[%-020p]\n", str);
		printf("[%20.14p]\n", str);
		printf("[%20p]\n", str);
		printf("[%-20p]\n", str);
		printf("[%020p]\n", str);
		printf("[%020.p]\n", str);
        return (0);
}

