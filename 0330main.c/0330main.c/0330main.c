#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{	
	////논리 연산자 &&(AND), ||(OR) 2개 이상 사용하기
	//int a = 0, b = 1, c = 1;

	//printf("논리 연산 1 && 1 || 0의 결과 : %d\n", 1 && 1 || 0);
	//printf("논리 연산 1 && 0 || 1의 결과 : %d\n", 1 && 0 || 1);
	//printf("논리 연산 1 && 0 || 0의 결과 : %d\n", 1 && 0 || 0);

	//printf("논리 연산 1 && 0 || 0 && 1의 결과 : %d\n", b && a || a && c);
	//printf("논리 연산 <1 && 0> || <0 && 1>의 결과 : %d\n", (b && a) || (a && c));

	//return 0;


	//// 논리 연산자와 관계연산자 함께 사용하기
	//int a = 0, b = 1, c = 1;

	//printf("a < b && c > a의 결과 : %d\n", a < b && c > a);
	//printf("a > b && c > a의 결과 : %d\n", a > b && c > a);
	//printf("a > b || c > a의 결과 : %d\n", a > b || c > a);

	//printf("괄호를 사용하는 것이 더 좋음\n");
	//printf("(a > b) || (c > a)의 결과 : %d\n", (a > b) || (c > a));

	//return 0;

	//// 대입 연산자 사용하기
	//int a, b = 0;

	//a = 4;
	//printf("a = 4 문장을 실행한 후의 a의 값 : %d\n", a);

	//a = a + 3;
	//printf("a = a + 3 문장을 실행한 후의 a의 값 : %d\n", a);

	//b = a + 2;
	//printf("b = a + 2 문장을 실행한 후의 b의 값 : %d\n", b);

	//return 0;

	// 전치 연산과 후치 연산  --> ++ 는 나중에 1씩 증가

	//int a, b, c;
	//a = 10; b = 20; c = 30;   

	//a = ++b;	// a = 21, b = 21,

	//c = b++;	// c = 21, b = 22
	//printf("a = %d, b = %d, c = %d\n\n", a, b, c);	// a = 21, b = 22, c = 21

	//a = ++b + ++c;	// a = 23 + 22, b = 23, c = 22 / a = 45
	//printf("a = ++b + ++c 문장 실행 후\n");
	//printf("a = %d, b = %d, c = %d\n\n", a, b, c);

	//a = b++ + c++;	// a = 23 + 22, b = 24, c = 23 / a = 45
	//printf("a = b++ + c++ 문장 실행 후\n");
	//printf("a = %d,b = %d,c = %d\n", a , b, c);

	//return 0;


	////이항 연산자 /, % 사용하기
	//int a = 20, b = 3, c = 7, d, e;
	//float f = 15.0, g;

	//d = a / b;		// d = 6, a = 20, b = 3
	//printf("d = a / b 를 실행한 후 d의 값은 %d\n", d);

	//e = a % c;		// e = 6, a = 20, c = 7
	//printf("e = a %% c 를 실행한 후 e의 값은 %d\n", e);

	//g = f / c;		// g = 2.142857, f = 15.0, c = 7
	//printf("g = f /c 를 실행한 후 g의 값은 %f\n", g);

	//return 0;

	//// 정사각형의 넓이 구하기
	//int length, area;
	//printf("정사각형 한 변의 길이를 입력하시오.\n");
	//scanf("%d", &length);

	//area = length * length;
	//printf("정사각형의 넓이는 %d다.\n", area);

	//return 0;

	// 합격 불합격 판별하기
//	int score, grade;
//	
//	printf("점수를 입력하세요 : ");
//	scanf("%d", &score);
//	
//	grade = score >= 90;
//
// if (grade == 1)
//	printf("결과는 %d, 합격\n", grade);
// else
//	printf("결과는 %d, 불합격\n", grade);
//		
//return 0;

//int a = 0, b = 1;
//
// printf("논리 연산 1 && 2의 결과 : %d\n", 1 && 2);   // 1
// printf("논리 연산 0 && 2의 결과 : %d\n\n", 0 && 2);	// 0
//
// printf("논리 연산 0 | | 2의 결과 : %d\n", 0 || 2);		// 1
// printf("논리 연산 0 | | 0의 결과 : %d\n\n", 0 || 0);	// 0
//
// printf("논리 연산 !a의 결과 : %d\n", !a);	// 1
// printf("논리 연산 !b의 결과 : %d\n", !b);	// 0
//
// return 0;

unsigned char lastmask = 1; // 2의 0승 위치 : 00000001
unsigned char firstmask = 128; // 2의 7승 위치 : 10000000

unsigned char input;

printf("값을 입력하시오.\n");
scanf("%d", &input);

printf("입력한 값 %d의 첫 번째 비트는 %d이다.\n", input, input & firstmask);

printf("입력한 값 %d의 마지막 비트는 %d이다.\n", input, input & lastmask);

return 0;
	
}
	
