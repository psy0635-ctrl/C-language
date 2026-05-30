#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	// 입력 받은 양수가 홀수인지 짝수인지 확인하기
	
	//int input;
	//printf("양수를 입력하세요 : ");
	//scanf("%d", &input);

	//if (input % 2 == 0)
	//	printf("입력한 수 %d는 짝수 입니다.\n", input);
	//else
	//	printf("입력한 수 %d는 홀수입니다.\n", input);
	//
	//return 0;


	//// 성적을 입력받아 학점 출력하기

	//int score;

	//printf("0점에서 100점 사이의 점수를 입력하세요\n");
	//scanf("%d", &score);

	//if (score >= 0 && score <= 100)
	//{
	//	printf("입력한 점수는 %d점 입니다.\n",score);
	//}
	//else
	//{
	//	printf("0점에서 100점 사이를 입력하셔야 합니다.\n");
	//	return 0;
	//}

	//if (score >= 0 && score < 60)
	//{
	//	printf("%d점은 F학점입니다.\n",score);
	//}
	//else if (score >= 60 && score < 70)
	//{
	//	printf("%d점은 D학점입니다.\n", score);
	//}
	//else if (score >= 70 && score < 80)
	//{
	//	printf("%d점은 C학점입니다.\n", score);
	//}
	//else if (score >= 80 && score < 90)
	//{
	//	printf("%d점은 B학점입니다.\n", score);
	//}
	//else if (score >= 90 && score <= 100)
	//{
	//	printf("%d점은 A학점입니다.\n", score);

	//	return 0;
	//}


	////if문 사용해서 홀수의 합 구하기
	//int n;
	//int sum;

	//printf("정수를 입력하세요 : ");
	//scanf("%d", &n);

	////짝수면 -1 해서 홀수로 만들기
	//if (n % 2 == 0)
	//{
	//	n = n - 1;
	//}

	//// 홀수 개수 구하기
	//int m = (n + 1) / 2;

	////홀수의 합 공식 m * m
	//sum = m * m;

	//printf("홀수의 합 : %d\n", sum);

	//return 0;



	//int n;
	//int sum;

	//printf("정수를 입력하세요 : ");
	//scanf("%d", &n);

	//if (n % 2!=0)
	//{
	//	n = n - 1;
	//}

	//// 짝수 개수 구하기
	//int m = n / 2;

	//sum = m * (m + 1);

	//printf("짝수의 합 공식은 %d입니다.\n", sum);

	//	
	//return 0;

	int num, input;

	printf("숫자를 입력하세요\n");
	scanf("%d", &input);

	num = input / 2;

	if (input % 2 == 1) {
		num++;
		printf("입력한%d홀수의 홀수의 개수는 %d이다.\n", input, num);
	}
	else printf("입력한%d짝수의 홀수의 개수는 %d이다.\n", input, num);
	
	return 0;

}