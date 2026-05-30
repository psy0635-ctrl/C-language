#include <stdio.h>

int main(void)
{
	int a = 10, b = 20, c;
	float d = 5.6, e = 8.4, f;

	c = d + e;
	printf("c = d + e의 연산결과는 %.2f입니다.\n", (float)c);
	
	f = d + e;
	printf("f = d + e의 연산결과는 %.2f입니다.\n", f);

	f = d + (int)e;
	printf("f = d + (int)e의 연산결과는 %.2f입니다.\n", f);

	return 0;
<<<<<<< HEAD

	
=======
>>>>>>> 0c557d270a6a391cbd9fe97ac8a6edc7d081d047
	
}