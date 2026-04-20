#define CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main() {

	int year;
	scanf("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		printf("1");
	}
	else {
		printf("0");
	}

	int a, b, c;
	int min, max;

	printf("세 정수를 입력하세요 : ");
	scanf("%d %d %d", &a, &b, &c);


	min = a;

	if (b < min)
	{
		min = b;
	}
	if (c < min)
	{
		min = c;
	}

	max = a;

	if (b > max)
	{
		max = b;
	}
	if (c > max)
	{
		max = c;
	}
	printf("최솟값 : %d\n", min);
	printf("최댓값 : %d\n", max);

	printf("최솟값 + 최댓값 : %d\n", min + max);

	return 0;

}





