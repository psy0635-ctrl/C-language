//# include <stdio.h>
//
//int main(void)
//{
	//int a = 10;
	//float b = 3.0;

	//printf("결과:%f\n", a / b);
	//printf("결과:%.2f\n", a / b);

//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//
//1.	int num;
//
//	scanf("%d", &num);
//
//	if (num > 0)
//	{
//		if (num % 2 == 0)
//		{
//			printf("양수 짝수\n");
//		}
//		else
//		{
//			printf("양수 홀수\n");
//		}
//	}
//	else if (num < 0)
//	{
//		printf("음수\n");
//	}
//	else
//	{
//		printf("0\n");
//	}
//	return 0;
//
//	2.int num;
//	scanf("%d", &num);
//
//	if (num >=90 && num <= 100)
//	{
//		printf("학점 : A\n");
//	}
//	else if (num >= 80 && num < 90)
//	{
//		printf("학점 : B\n");
//	}
//	else if (num >= 70 && num < 80)
//	{
//		printf("학점 : C\n");
//	}
//	else if (num >= 60 && num < 70)
//	{
//		printf("학점 : D\n");
//	}
//	else if (num >= 0 && num < 60)
//	{
//		printf("학점 : F\n");
//	}
//	else
//	{
//		printf("0에서 100 사이의 점수를 입력하세요.\n");
//	}
//	return 0;
//
//	3.int a, b;
//	char op;
//
//	printf("두 정수와 연산자를 입력하세요(예: 3 4 +) : ");
//	scanf("%d %c %d ", &a, &op ,&b);
//
//	switch (op)
//	{
//	case '+':
//		printf("%d + %d = %d\n", a, b, a + b);
//		break;
//	case '-':
//		printf("%d - %d = %d\n", a, b, a - b);
//		break;
//	case'*':
//		printf("%d *%d = %d\n", a, b, a * b);
//		break;
//	case '/':
//		if (b == 0)
//			printf("오류 : 0으로 나눌 수 없습니다.\n");
//
//		else
//			printf("%d / %d = %d\n", a, b, a / b);
//		break;
//
//	default:
//		printf("유효하지 않은 연산자입니다.\n");
//	}
//			
//	return 0;
//
//
//	4. int a, b;
//
//	printf("두 정수를 입력하세요 : ");
//	scanf("%d %d", &a, &b);
//
//	int max = (a > b) ? a : b;
//
//	printf("큰 수는 %d입니다.\n", max);
//
//	return 0;
//
//
//
//
//	5.int menu;
//
//	printf("1.아침\n");
//	printf("2.점심\n");
//	printf("3.저녁\n");
//
//	scanf("%d", &menu);
//
//	switch (menu)
//	{
//	case 1:
//		printf("Good Morning\n");
//		break;
//	case 2:
//		printf("Good Afternoon\n");
//		break;
//	case 3:
//		printf("Good Night\n");
//		break;
//	default:
//		printf("잘못된 입력입니다.\n");
//		break;
//	}
//	return 0;


	1. int num;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	if (num > 0)
	{
		if (num % 2 == 0)
		{
			printf("양수 짝수\n");
		}
		else
		{
			printf("양수 홀수\n");
		}
	}
	else if (num < 0)
	{
		printf("음수\n");
	}
	else
	{
		printf("0입니다.\n");
	}

	return 0;

	2. int score;

	printf("점수를 입력하세요 : ");
	scanf("%d", &score);

	if (score >= 90 && score <= 100)
	{
		printf("학점 : A\n");
	}
	else if (score >= 80 && score < 90)
	{
		printf("학점 : B\n");
	}
	else if (score >= 70 && score < 80)
	{
		printf("학점 : C\n");
	}
	else if (score >= 60 && score < 70)
	{
		printf("학점 : D\n");
	}
	else if (score >= 0 && score < 60)
	{
		printf("학점 : F\n");
	}
	else
	{
		printf("잘못된 점수\n");
	}

	return 0;


	3.int a, b;
	char op;

	printf("두 정수와 연산자를 입력하세요(예: 3 4 +) : ");

	scanf("%d %c %d", &a, &op, &b);

	switch (op)
	{
		case '+':
			printf("%d + %d = %d\n", a, b, a + b);
			break;
		case '-':
			printf("%d - %d = %d\n", a, b, a - b);
			break;
		case '*':
			printf("%d * %d = %d\n", a, b, a * b);
			break;
		case '/':
			if (b == 0)
				printf("오류 : 0으로 나눌 수 없습니다."\n);
			else
				printf("%d / %d = %d\n", a, b, a / b);
			break;
		default:
			printf("유효하지 않은 연산자입니다.\n");
	}
	
	return 0;

	4.int num;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	if (num > 0 && num % 3 == 0)
	{
		printf("양수 3의 배수\n");
	}
	else if (num > 0 && num % 3 != 0)
	{
		printf("양수 3의 배수 아님\n");
	}
	else if (num < 0)
	{
		printf("음수\n");
	}
	else
	{
		printf("0입니다.\n");
	}


	5. int num;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	switch (num)
	{
	case 1:
		printf("%c\n", 'A');
	case 2:
		printf("%c\n", 'B');
	case 3:
		printf("%c\n", 'C');
		break;
	default:
		printf("Error\n");
		break;
	}

	return 0;


	1. int i;

	for (i = 1; i <= 5; i++)
	{
		printf("%d ", i);
	}

	2.int i, j;

	for (i = 1; i <= 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
		
	}

	3.int i, sum = 0;

	for (i = 1; i <= 10; i++)
	{
		sum += i;
	}

	printf("1부터 10까지의 합은 %d입니다.\n", sum);

	4. int i;

	for (i = 5; i>=1; i--)
	{
		printf("%d ", i);
	}

	5.int i;

	for (i = 1; i <= 10; i++)
	{
		if (i % 2 != 0) continue;
		{
			printf("%d ", i);
		}
	}

	6.int i;

	for (i = 1; i <= 10; i++)
	{
		if (i % 2 == 0) continue;
		{
			printf("%d ", i);
		}
	}

	7. int i = 1;

	while (i <= 5)
	{
		printf("%d ", i);
		i++;
	}

	8.int i = 1;

	do
	{
		printf("%d ", i);
		i++;
	} while (i <= 5);

	9.int i;

	for (i = 1; i <= 10; i++)
	{
		printf("%d ", i);
		if (i == 5) break;

	}

	10. int i;
	for (i = 1; i <= 10; i++)
	{
		if (i == 3) continue;
		printf("%d ", i);
	}

	11. int i,j;

	for (i = 1; i <= 3; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("*");
			printf("\n");
		}
	}
	12. int i, j;

	for (i = 3; i >= 1; i--)
	{
		for (j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	13.int i;

	for (i = 1; i <= 5; i++)
	{
		printf("%d ", i);
	}

	14.int i, sum = 0;

	for (i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			sum += i;
		}
		
	}

	printf("1부터 10까지의 2의 배수의 합은 %d입니다.\n", sum);


	15. int i;

	for (i = 1; i <= 10; i++)
	{
		if (i % 3 == 0)
			printf("3의 배수 : %d ", i);
		
	}
		16. int n;

		printf("정수를 입력하세요 : ");	
		scanf("%d", &n);

		for (i = 1; i <= n; i++)
		{
			printf("%d ", i);
		}

		17. int n, sum = 0;

		printf("정수를 입력하세요 : ");
		scanf("%d", &n);

		for (i = 1; i <= n; i++)
		{
			sum += i;
		}
		printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);


		18. int i;
		for (i = 0; i <= 2; i++)
		{
			printf("1 2 \n");
		}

		19.int i;
		for (i = 1; i <= 3; i++)
		{
			printf("%d\n ", i);
		}

		20. int i;

		for (i = 1; i <= 10; i++)
		{
			if (i % 2 == 0 && i % 3 == 0) continue;
			printf("%d ", i);

		}


		1.int start, end, sum = 0;

		printf("시작 정수와 끝 정수를 입력하세요 : ");
		scanf("%d %d", &start, &end);

		for (int i = start; i <= end; i++)
		{
			sum += i;
		}
		printf("%d부터 %d까지의 합은 %d입니다.\n", start, end, sum);


		2. int num, sum = 0, count = 0;
		double avg;

		while (true)
		{
			printf("정수를 입력하세요 (0 입력 시 종료) : ");
			scanf("%d", &num);

			if (i == 0) break;

			sum += num;
			count++;
		}
			if (count > 0)
			{
				avg = (double)sum / count;
				printf("현재까지의 합 : %d, 평균 : %.2f\n", sum, avg);

			}
			else
			{
				printf("아직 입력된 정수가 없습니다.\n");

			}
		

		3.int i, j;	

			for (i = 1; i <= 5; i++)
			{
				for (j = 0; j < i; j++)
				{
					printf("*");
				}
				printf("\n");
			}





}


