#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main() {
	printf("%-00000-----*i\n", 12, 123);
	printf("%---0.*d\n", 12, 123);
	printf("%0-0-0-0-0.*d\n", 12, 123);
	printf("%-0-0-0-0-.*d\n", 12, 123);
	printf("%-----.*d\n", 12, 123);

	ft_printf("%-00000-----*i\n", 12, 123);
	ft_printf("%---0.*d\n", 12, 123);
	ft_printf("%0-0-0-0-0.*d\n", 12, 123);
	ft_printf("%-0-0-0-0-.*d\n", 12, 123);
	ft_printf("%-----.*d\n", 12, 123);

}

/*
int main(void)
{
	char *ptr;
	int ret;
	int myret;

	ret = printf("org d: %d\n", 2147483648);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my d: %d\n", 2147483648);
	printf("{myret: %d}\n", myret);
	printf("\n");

	ret = printf("org u: %u\n", 4294967295);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my u: %u\n", 4294967295);
	printf("{myret: %d}\n", myret);
	printf("\n");

	ret = printf("org u: %u\n", 4294967296);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my u: %u\n", 4294967296);
	printf("{myret: %d}\n", myret);
	printf("\n");

	ret = printf("org x: %x\n", 0xfF1);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my x: %x\n", 0xfF1);
	printf("{myret: %d}\n", myret);
	printf("\n");

	ret = printf("org X: %X\n", 0xfF1);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my X: %X\n", 0xfF1);
	printf("{myret: %d}\n", myret);
	printf("\n");

	ret = printf("org p: %p\n", ptr);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my p: %p\n", ptr);
	printf("{myret: %d}\n", myret);
	printf("\n");
}
*/
/*
int main() {
	int ret;
ft_printf("result : |");
ret = ft_printf("%d", 12345);
	ft_printf("|\nresult : |12345|\n");
	ft_printf("return : 5 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%d", -12345);
	ft_printf("|\nresult : |-12345|\n");
	ft_printf("return : 6 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%3d", 12345);
	ft_printf("|\nresult : |12345|\n");
	ft_printf("return : 5 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%7d", 12345);
	ft_printf("|\nresult : |  12345|\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-7d", 12345);
	ft_printf("|\nresult : |12345  |\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-d", 12345);
	ft_printf("|\nresult : |12345|\n");
	ft_printf("return : 5 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%*d", 7, 12345);
	ft_printf("|\nresult : |  12345|\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%*d", -7, 12345);
	ft_printf("|\nresult : |12345  |\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%.d", 12345);
	ft_printf("|\nresult : |12345|\n");
	ft_printf("return : 5 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%.0d", 12345);
	ft_printf("|\nresult : |12345|\n");
	ft_printf("return : 5 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%.3d", 12345);
	ft_printf("|\nresult : |12345|\n");
	ft_printf("return : 5 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%.7d", 12345);
	ft_printf("|\nresult : |0012345|\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-.7d", 12345);
	ft_printf("|\nresult : |0012345|\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-9.7d", 12345);
	ft_printf("|\nresult : |0012345  |\n");
	ft_printf("return : 9 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%9.7d", 12345);
	ft_printf("|\nresult : |  0012345|\n");
	ft_printf("return : 9 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-7.9d", 12345);
	ft_printf("|\nresult : |000012345|\n");
	ft_printf("return : 9 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-3.7d", 12345);
	ft_printf("|\nresult : |0012345|\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-7.3d", 12345);
	ft_printf("|\nresult : |12345  |\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%.3d", -12345);
	ft_printf("|\nresult : |-12345|\n");
	ft_printf("return : 6 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%.7d", -12345);
	ft_printf("|\nresult : |-0012345|\n");
	ft_printf("return : 8 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-.7d", -12345);
	ft_printf("|\nresult : |-0012345|\n");
	ft_printf("return : 8 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-9.7d", -12345);
	ft_printf("|\nresult : |-0012345 |\n");
	ft_printf("return : 9 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-7.9d", -12345);
	ft_printf("|\nresult : |-000012345|\n");
		ft_printf("eturn : 10 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-3.7d", -12345);
	ft_printf("|\nresult : |-0012345|\n");
	ft_printf("return : 8 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%-7.3d", -12345);
	ft_printf("|\nresult : |-12345 |\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%0d", 12345);
	ft_printf("|\nresult : |12345|\n");
	ft_printf("return : 5 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%07d", 12345);
	ft_printf("|\nresult : |0012345|\n");
	ft_printf("return : 7 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%d", 0);
	ft_printf("|\nresult : |0|\n");
	ft_printf("return : 1 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%3d", 0);
	ft_printf("|\nresult : |  0|\n");
	ft_printf("return : 3 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%3.d", 0);
	ft_printf("|\nresult : |   |\n");
	ft_printf("return : 3 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%03d", 0);
	ft_printf("|\nresult : |000|\n");
	ft_printf("return : 3 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%09.0d", 12345);
	ft_printf("|\nresult : |    12345|\n");
	ft_printf("return : 9 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%09.7d", 12345);
	ft_printf("|\nresult : |  0012345|\n");
	ft_printf("return : 9 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%07.9d", 12345);
	ft_printf("|\nresult : |000012345|\n");
	ft_printf("return : 9 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%.d", 0);
	ft_printf("|\nresult : ||\n");
	ft_printf("return : 0 %d\n\n", ret);
ft_printf("result : |");
ret = ft_printf("%.3d", 0);
	ft_printf("|\nresult : |000|\n");
	ft_printf("return : 3 %d\n\n", ret);
}

*/
/*
int main(void)
{
	char *ptr;
	printf("org d: %d\n", 2147483648);
	ft_printf(" my d: %d\n\n", 2147483648);
	printf("org u: %u\n", 4294967295);
	ft_printf(" my u: %u\n\n", 4294967295);
	printf("org u: %u\n", 4294967296);
	ft_printf(" my u: %u\n\n", 4294967296);
	printf("org x: %x\n", 0xfF1);
	ft_printf(" my x: %x\n\n", 0xfF1);
	printf("org X: %X\n", 0xfF1);
	ft_printf(" my X: %X\n\n", 0xfF1);
	printf("org p: %p\n", ptr);
	ft_printf(" my p: %p\n\n", ptr);
	return (0);
}
*/
