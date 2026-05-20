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

	//int num, input;

	//printf("숫자를 입력하세요\n");
	//scanf("%d", &input);

	//num = input / 2;

	//if (input % 2 == 1) {
	//	num++;
	//	printf("입력한%d홀수의 홀수의 개수는 %d이다.\n", input, num);
	//}
	//else printf("입력한%d짝수의 홀수의 개수는 %d이다.\n", input, num);
	//
	//return 0;

	int input;

	printf("평점이4.2 이상 4.3 미만이면 1번을 누르세요.\n");
	printf("평점이4.3 이상 4.4 미만이면 2번을 누르세요.\n");
	printf("평점이4.4 이상 4.5 미만이면 3번을 누르세요.\n");

	scanf("%d", &input);

	switch (input)
	{
	case 3:
		printf("해외 연수 기회가 주어집니다.\n");
		
	case 2:
		printf("장학금이 지급됩니다.\n");
		
	case 1:
		printf("겨울 특강 수강 자격을 받습니다.\n");
		break;
	default:
		printf("잘못 입력했습니다. 1~3 사이의 숫자를 입력하세요.\n");
		

	}

	return 0;


1. a[5] = {10,20,30,40,50};

for(int i = 4; i >= 0; i--)
{
	printf("%d",a[i]);

}

2. int a[2][3]= {{10,20,30},
                {40,50,60}};
int row_sum = 0;
for (int i =0;i < 2; i++)
{
	row_sum = 0;
	for (int j =0; j < 3; j++)
	{
		row_sum += a[i][j];	
	}
	printf("%d행의 합계 : %d\n", i + 1, row_sum);

} 		

#include <stdio.h>

int main(void)
{
    int arr[5];         // 5개의 정수를 담을 배열 선언
    int max;            // 최댓값을 저장할 변수
    int i;              // 반복문을 위한 변수

    // 1. 사용자로부터 5개의 정수 입력받기
    printf("5개의 정수를 입력하세요:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d번째 숫자: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // 2. 최댓값 찾기 알고리즘 시작
    // 우선 배열의 첫 번째 원소(index 0)를 가장 크다고 가정합니다.
    max = arr[0];

    // 두 번째 원소(index 1)부터 마지막 원소까지 차례대로 비교합니다.
    for (i = 1; i < 5; i++)
    {
        if (arr[i] > max)   // 현재 max보다 더 큰 값을 발견하면
        {
            max = arr[i];   // 그 값을 새로운 max로 업데이트합니다.
        }
    }

    // 3. 최종 결과 출력
    printf("\n------------------------------\n");
    printf("입력한 값 중 가장 큰 값은 %d입니다.\n", max);
    printf("------------------------------\n");

    return 0;
}