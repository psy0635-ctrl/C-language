#include <stdio.h>

int main(void)
{

    // 반목문을 이용한 동일한 문장 출력하기

    //int i,j,sum;

    //for (i = 0; i < 5; i++)
    //{
    //    printf("***********\n");
    //}
    //return 0;

    // 반복문을 이용한 합 구하기

    //int i, Sum = 0;

    //for (i = 1; i <= 10; I++)
    //    Sum += i;

    //printf("1부터 10까지의 합은 %d다.\n", Sum);

    //return 0;


    //// 알파벳 출력하기

    //  int i;

    //  for (i = 65; i <= 90; i++)
    //  {
    //      printf("%c", i);
    //  }
    //  printf("\n");

    //  return 0;

    ////  다중 for문을 이용하여 변수 2개의 합 구하기
    // 
    //int sum, i, j;               
    //printf("다중 for문 예제 입니다.\n");

    //for (i = 1; i <= 3; i++)
    //{
    //    for (j = 1; j <= 3; j++)
    //    {
    //        sum = i + j;
    //        printf("%d + %d = %d\n", i, j, sum);
    //    }
    //}

    //return 0;
 
    //바깥 for문이 1번 돌 때
    //    └─ 안쪽 for문이 3번 돈다

    //  바깥이 총 3번 도니까
    //    └─ 전체 반복 횟수 = 3 × 3 = 9번

    // ------------------------------------------------------------
    //    i = 1: j = 0 → j < 1 통과 → 별 1개  → *
    //    i = 2 : j = 0, 1 → j < 2 통과 → 별 2개  → * *
    //    i = 3 : j = 0, 1, 2 → j < 3 통과 → 별 3개  → * **
    //    i = 4 : j = 0, 1, 2, 3 → j < 4 통과 → 별 4개  → * ***
    //    i = 5 : j = 0, 1, 2, 3, 4 → j < 5 통과 → 별 5개  → * ****

    //int i, j;   

    //for (i = 1; i < 6; i++)
    //{
    //    for (j = 0; j < i; j++)
    //    {                                       
    //        printf("*");
    //    }
    //    printf("\n");
    //        
    //}

    //return 0;
// ----------------------------------------------------------------------

    //int i, j, sum;

    //for (i = 1; i <= 9; i++)
    //{
    //    for (j = 1; j <= 9; j++)
    //    {
    //        sum = i * j;
    //        printf("%d * %d = %d\n"i, j, sum);
    //    }
    //}

    //return 0;

// ---------------------------------------------------------------------

    // 2~100 사이의 소수를 찾아서 5개씩 한 줄에 출력

    int i, j,count = 0;    

    for (i = 2; i <= 100; ++i)  // i를 2부터 100까지 1씩 증가시키면서 순회해. 1은 소수가 아니라서 2부터 시작.
    {
        for (j = 2; j < i; ++j) // j를 2부터 i-1까지 하나씩 나눠봄      
        {
            if (i % j == 0)  // i % j == 0 → 나누어 떨어지면 약수가 존재한다는 뜻 → 소수 아님 → break로 즉시 탈출
                break;
        }

        if (j == i)  // j == i이면 소수, j < i이면 소수가 아님
        {
            count++;  // 소수 찾을 때마다 1 증가
            printf("%d%s",i,count % 5 ? "": "\n");  // 5의 배수일 때만 줄바꿈, 나머지는 공백
        }
    }

    return 0;
}

//    i = 2  → j = 2, j < 2 불만족 → 즉시 종료 → j == i → 소수 ✓ count = 1
//    i = 3  → j = 2, j < 3, 3 % 2 = 1 → j = 3, 종료 → j == i → 소수 ✓ count = 2
//    i = 4  → j = 2, 4 % 2 = 0 → break → j = 2 → j≠i → 소수 ✗
//    i = 5  → 소수 ✓ count = 3
//    i = 6  → j = 2, 6 % 2 = 0 → break → 소수 ✗
//    i = 7  → 소수 ✓ count = 4
//    i = 8  → 소수 ✗
//    i = 9  → j = 3, 9 % 3 = 0 → break → 소수 ✗
//    i = 10 → 소수 ✗
//    i = 11 → 소수 ✓ count = 5  ← 여기서 줄바꿈
//    i = 13 → 소수 ✓ count = 6
    
// ---------------------------------------------------------

int i;
int a[] = { 5,10,15 };

for (i = 0; i < 3; i++)
{
	printf("a[%d] = %d\n", i, a[i]);
}



int A[5] = { 1,2,3,4,5 };
int i, sum = 0;
double avg;

for (i = 0; i < 5; i++)
    sum += A[i];

avg = (double)sum / i;

printf("배열 A 원소의 합은 %d입니다.\n", sum);
printf("배열 A 원소의 평균은 %4.2lf 입니다.\n", avg);

return 0;




1.int a[5] = {10,20,30,40,50};

for (int i = 0; i < 5; i++)
{
    printf("%d\n", a[i]);
}


2.int a[5] = { 1,2,3,4,5 };
int sum = 0;

for (int i = 0; i < 5; i++)
{
    sum += a[i];
}
printf("배열 a 원소의 합은 %d입니다.\n", sum);


3.int a[5] = {3,7,2,9,1};
int max = a[0];

for (int i = 0; i < 5; i++)
{
    if(a[i] > max)
    {
        max = a[i];
	}
}
printf("최댓값 : %d\n", max);


4.int a[5] = { 1,2,3,4,5 };

for (int i = 4; i >= 0; i--)
{
    printf("%d\n", a[i]);
}

5. int sum = 0;
int a[2][3] = { {1,2,3,},
                {4,5,6} };

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 3; j++)
    {
        sum += a[i[j];
    }
	
}
printf("전체 합은 %d입니다.\n", sum);


1. #include <stdio.h>

int main(void)
{
    int sum = 0;                          // 합계를 저장할 변수, 0으로 초기화
    int a[6] = { 5, 10, 15, 20, 25, 30 };  // 크기 6인 정수 배열 선언 및 초기화

    for (int i = 0; i < 6; i++)  // i = 0부터 5까지 (6번 반복)
    {
        printf("%d ", a[i]);     // 배열 원소 출력 (공백 포함)
        sum += a[i];             // sum = sum + a[i] (합계 누적)
    }
    // ⚠️ 핵심 : printf는 for문 안에서 해야 a[i]에 접근 가능
    // for문 밖에서 a[i] 쓰면 i가 6이 되어 범위 초과!

    printf("\n합계 : %d\n", sum); // 줄바꿈 후 합계 출력

    return 0;
}



2. #include <stdio.h>

int main(void)
{
    int a[5] = { 8, 3, 6, 1, 9 };  // 크기 5인 정수 배열 선언 및 초기화
    int min = a[0];               // 첫 번째 값(8)을 최솟값으로 가정하고 시작

    for (int i = 1; i < 5; i++)  // i = 1부터 시작 (a[0]은 이미 min에 저장)
    {
        if (a[i] < min)          // 현재 원소가 min보다 작으면
        {
            min = a[i];          // min을 현재 원소로 교체
        }
    }
    // ⚠️ 핵심 : for문이 끝난 후 i = 5 → 범위 초과
    // 배열 출력은 반드시 별도 for문으로!

    // 배열 전체 출력 (별도 for문)
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);     // 배열 원소 순서대로 출력

    printf("\n최솟값 : %d\n", min); // 최솟값 출력

    return 0;
}



3. #include <stdio.h>

int main(void)
{
    int i, j, sum;               // sum 선언 (초기화는 아래 루프 안에서)
    int a[3][3] = { {1, 2, 3},   // 0행 : 1, 2, 3
                   {4, 5, 6},   // 1행 : 4, 5, 6
                   {7, 8, 9} };  // 2행 : 7, 8, 9
    // ⚠️ 핵심 : 2차원 배열은 {{ }} 이중 중괄호 필수!

    for (i = 0; i < 3; i++)     // i = 0~2 (행 반복, 3번)
    {
        sum = 0;                 // ⚠️ 핵심 : 매 행 시작마다 sum 초기화
                                 // 여기 없으면 이전 행 합계가 누적됨!

        for (j = 0; j < 3; j++) // j = 0~2 (열 반복, 3번)
        {
            sum += a[i][j];     // ⚠️ 핵심 : a[i][j] → 행i, 열j의 원소
        }                       // a[[j] 처럼 쓰면 문법 오류!

        printf("%d행 합계 : %d\n", i + 1, sum);
        // i는 0부터 시작이므로 i+1 해야 1행, 2행, 3행으로 출력
    }

    return 0;
}

1.int a[5] = { 1, 2, 3, 4, 5 };
for (int i = 0; i < 5; i++)
{
    printf("%d", a[i]);
}

2.int a[5];

for (int i = 0; i < 5; i++)
{
	printf("정수를 입력하세요", &a[i]);
	scanf("%d", &a[i]);
}

3.int a[5] = { 10, 20, 30, 40, 50};
int sum = 0;

for (int i = 0; i < 5; i++)
{
    sum += a[i];
}

printf("배열 a 원소의 합은 %d입니다.\n", sum);


4. int a[5] = { 5,10,15,20,25 };
int sum = 0;
double avg;

for (int i = 0; i < 5; i++)
{
    sum += a[i];
}

avg = (double)sum / 5;
printf("배열 a 원소의 평균은 %4.2lf입니다.\n", avg);

5. int a[5];
int max = a[0];

for (int i = 1; i < 5; i++)
{
    if (a[i] > max)
    {
        max = a[i];
    }
}
printf("배열 a 원소의 최댓값은 %d입니다.\n", max);

6.int a[5];
int min = a[0];

for (int i = 1; i < 5; i++)
{
    if (a[i] < min)
    {
        min = a[i];
    }
}
printf("배열 a 원소의 최솟값은 %d입니다.\n", min);

7. int a[5] = { 1,2,3,4,5 };

for (int i = 4; i >= 0; i--)
{
    printf("%d\n", a[i]);
}

8. int a[2][3] = { {1,2,3},
				  {4,5,6} };

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 3; j++)
    {
		printf("%d ", a[i][j]);
    }
}

9.int a[2][2];
int sum = 0;

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
        printf("정수를 입력하세요 : ");
        scanf("%d", &a[i][j]);
        sum += a[i][j];
    }
}



1.#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main(void)
{
    char ch = 'a';

    printf("%c\n", ch);
    printf("%d\n", (int)ch);

    return 0;

}

2.#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main(void)
{
    int a;

    printf("정수를 입력하세요 : \n");
    scanf("%d", &a);

    if (a > 0)
    {
        if (a % 2 == 0)
        {
            printf("양수 짝수\n");
        }
        else
        {
            printf("양수 홀수\n");
        }
    else if (a < 0)
    {
        printf("음수\n");
    }
    else
    {
        printf("0\n");
    }

   }

    return 0;
}

3.#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 10; i++)
    {
        if (i % 3 == 0)
            continue;
        if (i == 7)
            break;
        printf("%d",i)
    }
    return 0;
}


4.#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main(void)
{
    
    
    return 0;
}

4.#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int num;
    int sum = 0;
    while (1)
    {
        printf("정수를 입력하세요 : ");
        scanf("%d", &num);

        if (num == 0)
            break;

        if (num < 0)
            continue;

        sum += num;
    }
    printf("합계 : %d", sum);

    return 0;
}

1.# include <stdio.h>

int main(void)
{

    char ch = 'A';

    printf("%c\n", ch);
    prinrf("%d\n", (int)ch);

    return 0;
}


2.# include <stdio.h>

int main(void)
{

    printf("Hello\tWorld");

    return 0;
}

3.# include <stdio.h>

int main(void)
{

    printf("\"C언어\"");

        return 0;
}

4.# include <stdio.h>

int main(void)
{
    char ch;

    printf("문자를 입력하세요 : ");
    scanf("%c", &ch);

    printf("%c", ch);
    printf("%d", (int)ch);



        return 0;
}

5.# include <stdio.h>

int main(void)
{
   
    printf("%c\n", 97);
    printf("%d\n", 'b');



    return 0;
}


6.# include <stdio.h>

int main(void)
{

    printf("\\\n");
    printf("%%\n");



    return 0;
}

7.# include <stdio.h>

int main(void)
{

    printf("%c\n", 'a' - 32);
 



    return 0;
}


8.# include <stdio.h>

int main(void)
{

    char c;
    scanf("%c\n", &c);
    printf("%c\n", c + 1);





    return 0;
}

10.# include <stdio.h>

int main(void)
{
    for (char c = 'A'; c <= 'Z'; c++)
    {
        printf("%c", c)
    }

    printf("\n");




    return 0;
}


1.# include <stdio.h>

int main(void)
{
    float f = 3.7;

    printf("%d", (int)f);


    return 0;
}

2.# include <stdio.h>

int main(void)
{

    printf("%f\n",((float)10/3);


    return 0;
}

3.# include <stdio.h>

int main(void)
{

    printf("%d\n", (int)'A');


    return 0;
}

4.# include <stdio.h>

int main(void)
{

    int a, b;

    printf("두 정수를 입력하세요 : ");
    scanf("%d %d", &a, % b);

    printf("%f\n", (float)(a+b) / 2);

    return 0;
}

5.# include <stdio.h>

int main(void)
{
    float f;
    scanf("%f", &f);

    printf("%d\n", (int)f);
    

    return 0;
}

6.# include <stdio.h>

int main(void)
{
    char c;
    scanf("%c", &c);

    printf("%d\n", (int)c);

    return 0;
}

7.# include <stdio.h>

int main(void)
{
    int a;
    scanf("%d", &a);

    printf("%c\n", (char)a);

    return 0;
}

8.# include <stdio.h>

int main(void)
{
    printf("%d", 5 / 2);
    printf("%f", (float)5 / 2);

    return 0;
}


9.# include <stdio.h>

int main(void)
{
    printf("%c\n", (char)('a' - 32));

    return 0;
}

1.# include <stdio.h>

int main(void)
{
    int a;
    printf("정수를 입력하세요 :");
    scanf("%d\n",&)

        if (a > 0)
        {
            printf("양수\n");
        }

    return 0;
}

2.# include <stdio.h>

int main(void)
{
    
    int a;
    scanf("%d", &a);

    if (a % 2 == 0)
    {
        printf("짝수\n");
    }
    else 
    {
        printf("홀수\n");
    }

    return 0;
}

3.# include <stdio.h>

int main(void)
{
    int a;
    scanf("%d", &a);

    if (a > 0)
    {
        if (a % 2 == 0)
            printf("양수\n");
        else
            printf("홀수\n");
        
    }
    else 
    {
        printf("0 또는 음수\n");
    }
 
   
    return 0;
}


4.# include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 5; i++)
    {
        printf("%d", i);
   }
  

    return 0;
}


5.# include <stdio.h>

int main(void)
{
    int sum = 0;
    
    for (int i = 1; i <= 10; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);


    return 0;
}


6.# include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
            printf("%d\n", i);
    }


    return 0;
}


7..# include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 10; i++)
    {
        if (i == 5)
            break;
        printf("%d\n", i);
    }

    return 0;
}

8.# include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 1)
            continue;
        printf("%d\n", i);
    }

    return 0;
}

9.# include <stdio.h>

int main(void)
{
    int i = 1;

    while (i <= 5) {
        printf("%d\n", i)
            i++;
    }
      

    return 0;
}

9.# include <stdio.h>

int main(void)
{
    int i = 1;

    while (i <= 5) {
        printf("%d\n", i)
            i++;
    }
      

    return 0;
}

10.# include <stdio.h>

int main(void)
{
    int i = 1;
    int sum = 0;

    while (i <= 10) {
        sum += i;
        i++;
    }
    printf("%d", sum);

    return 0;
}

11.# include <stdio.h>

int main(void)
{
    int n, sum = 0;
  
    while (1)
    {
        scanf("%d", &n);
        if (i == 0)
            break;
        sum += n;
    }
    printf("%d\n", sum);

    return 0;
}


12.# include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 10; i++)
    {
        if (i % 3 == 0)
            printf("%d\n", i);
    }

    return 0;
}


2.# include <stdio.h>

int main(void)
{
    int a;
    scanf("%d", &a);

    if (a > 0)
    {
        if (a % 3 == 0)
            printf("양수 3의 배수\n");
        else
            printf("양수\n");
    }
    else if (a < 0)
    {
        printf("음수\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}

3.# include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 20; i++)
    {
        if (i == 15)
            break;
        if (i % 2 == 0)
            continue;
  
            printf("%d\n", i);
    }
    return 0;
}

4.# include <stdio.h>

int main(void)
{
    int i, sum = 0;

    while (1)
    {
        scanf("%d", &i);

        if (i == 0)
            break;
        if (i < 0)
            continue;
        sum += i;
    }
    printf("%d\n", sum);

    return 0;
}

1, 5 / 6

2.# include <stdio.h>

int main(void)
{
    int a;
    scanf("%d", &a);

    if (a > 0)
    {
        if (a % 2 == 0)
            printf("양수 짝수\n");
        else
            printf("양수 홀수\n");

    }
    else if (a < 0)
        printf("음수\n");

    else
        printf("0\n");


    return 0;
}

3.# include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 20; i++)
    {
        if (i % 3 == 0)
            continue;
        if (i == 10)
            break;

        printf("%d\n", i);
    }


    return 0;
}

4.# include <stdio.h>

int main(void)
{
    int n, sum = 0;

    while (1)
    {
        scanf("%d", &n);

        if (n == 0)
            break;
        if (n < 0)
            continue;
        sum += n;
    }
    printf("%d\n", sum);

    return 0;
}


#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}


#include <stdio.h>

int main(void)
{
    for (int i = 5; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
  }

    return 0;
}

#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 5; i++)  // 몇 층까지 쌓을지
    {
        for (int j = 1; j <= 5 - i; j++) // 왼쪽에서 얼마나 밀까? (공백)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) // 별을 몇 개 찍을까?
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}


#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 20; i++)
    {
        if (i % 2 == 0)
            printf("%d", i);
    }
    
    return 0;
}

#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 30; i++)
    {
        if ((i % 2 == 0) && (i % 3 != 0))
        {
            printf("%d\n", i);
        }
    }
       
    return 0;
}

int sum = 0;
for (int i = 1; i <= 100; i++)
{
    if ((i % 3 == 0) || (i % 5 == 0)
    {
        sum += i;
        
    }
}

printf("%d", i);







