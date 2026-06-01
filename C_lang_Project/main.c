/*
 * ============================================
 *   무인편의점 관리자 - 선택형 시뮬레이션 게임
 *   알고리즘 실습 기말 프로젝트
 * ============================================
 *
 *  사용 언어: C언어
 *  개발 환경: Visual Studio / VS Code + GCC
 *
 *  게임 설명:
 *    플레이어가 무인편의점 관리자가 되어
 *    매장에서 발생하는 상황에 대응하는 게임입니다.
 *    선택에 따라 보안, 매출, 평판, 도난 위험도가 변합니다.
 *
 *  조작 방법: 숫자 1, 2, 3 중 하나를 입력하여 선택
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>    /* printf, scanf, FILE 관련 함수 */
#include <stdlib.h>   /* rand, srand 함수 */
#include <string.h>   /* 문자열 관련 함수 (strcpy 등) */
#include <time.h>     /* time 함수 (랜덤 시드 설정용) */

/* ──────────────────────────────────────────
 *  상수 정의
 * ────────────────────────────────────────── */
#define MAX_TURNS    5       /* 총 게임 턴 수 */
#define TOTAL_EVENTS 8       /* 전체 이벤트(상황) 개수 */
#define RISK_LIMIT   100     /* 도난 위험도 상한 (이상이면 실패) */
#define REP_LIMIT    0       /* 평판 하한 (이하이면 실패) */
#define SAVE_FILE    "highscore.txt"  /* 최고 점수 저장 파일명 */

/* ──────────────────────────────────────────
 *  구조체 정의: 플레이어 상태 관리
 *  - 이름, 보안 점수, 매출, 평판, 도난 위험도, 총점
 *    을 하나로 묶어서 관리합니다.
 * ────────────────────────────────────────── */
typedef struct {
    char name[30];      /* 플레이어 이름(최대 30글자) */
    int security;       /* 보안 점수 */
    int sales;          /* 매출 */
    int reputation;     /* 평판 */
    int risk;           /* 도난 위험도 */
    int score;          /* 최종 점수 */
} Player;

/* ──────────────────────────────────────────
 *  함수 선언 (프로토타입)
 * ────────────────────────────────────────── */
void showMenu();                        /* 메인 메뉴 출력 */
void showGameInfo();                    /* 게임 설명 출력 */
void initPlayer(Player *p);            /* 플레이어 초기 설정 */
void showStatus(Player p);             /* 현재 상태 출력 */
void playGame(Player *p);              /* 게임 진행 (메인 루프) */
void handleEvent(Player *p, int eventNum);  /* 이벤트 처리 */
int  getChoice();                       /* 입력값 검증 (1~3만 허용) */
void shuffleEvents(int arr[], int size);/* 이벤트 순서 섞기 */
void showResult(Player p);             /* 최종 결과 및 등급 출력 */
void saveHighScore(Player p);          /* 최고 점수 파일 저장 */
void loadHighScore();                  /* 최고 점수 파일 불러오기 */

/* ──────────────────────────────────────────
 *  main 함수: 프로그램 시작점
 * ────────────────────────────────────────── */
int main() {
    Player player;  /* 플레이어 구조체 변수 */
    int menu;       /* 메뉴 선택값 */

    /* 랜덤 시드 설정: 매번 다른 랜덤 결과를 얻기 위해
       현재 시간을 시드로 사용합니다 */
    srand((unsigned int)time(NULL));

    /* 메인 메뉴 반복 */
    while (1) {
        showMenu();
        scanf("%d", &menu);

        if (menu == 1) {
            /* 게임 시작 */
            initPlayer(&player); // 이름 입력 + 초기값 설정
            playGame(&player);  // 게임 진행
            showResult(player); // 결과 출력
            saveHighScore(player); // 점수 저장
        }
        else if (menu == 2) {
            /* 게임 설명 보기 */
            showGameInfo();
        }
        else if (menu == 3) {
            /* 최고 점수 확인 */
            loadHighScore();
        }
        else if (menu == 4) {
            /* 종료 */
            printf("\n게임을 종료합니다. 수고하셨습니다!\n");
            break;
        }
        else {
            /* 잘못된 입력 처리 */
            printf("\n[오류] 1~4 사이의 숫자를 입력해주세요.\n");
        }
    }

    return 0;
}

/* ──────────────────────────────────────────
 *  showMenu: 메인 메뉴 출력 함수
 * ────────────────────────────────────────── */
void showMenu() {
    printf("\n");
    printf("========================================\n");
    printf("       [ 무인편의점 관리자 ]\n");
    printf("========================================\n");
    printf("  1. 게임 시작\n");
    printf("  2. 게임 설명\n");
    printf("  3. 최고 점수 확인\n");
    printf("  4. 종료\n");
    printf("========================================\n");
    printf("  메뉴 선택: ");
}

/* ──────────────────────────────────────────
 *  showGameInfo: 게임 설명 출력 함수
 * ────────────────────────────────────────── */
void showGameInfo() {
    printf("\n");
    printf("----------------------------------------\n");
    printf("            [ 게임 설명 ]\n");
    printf("----------------------------------------\n");
    printf("  플레이어는 무인편의점 관리자가 되어\n");
    printf("  매장에서 발생하는 여러 상황에 대응합니다.\n");
    printf("\n");
    printf("  선택에 따라 아래 4가지 수치가 변합니다:\n");
    printf("    - 보안 점수  (높을수록 좋음)\n");
    printf("    - 매출       (높을수록 좋음)\n");
    printf("    - 평판       (높을수록 좋음)\n");
    printf("    - 도난 위험도 (낮을수록 좋음)\n");
    printf("\n");
    printf("  도난 위험도가 %d 이상이면 실패합니다.\n", RISK_LIMIT);
    printf("  평판이 %d 이하가 되어도 실패합니다.\n", REP_LIMIT);
    printf("  %d턴을 버티면 최종 등급을 받습니다.\n", MAX_TURNS);
    printf("----------------------------------------\n");
}

/* ──────────────────────────────────────────
 *  initPlayer: 플레이어 초기 설정 함수
 *  - 포인터를 사용하여 구조체 값을 직접 변경합니다
 * ────────────────────────────────────────── */
void initPlayer(Player *p) {
    printf("\n  플레이어 이름을 입력하세요: ");
    scanf("%s", p->name);

    /* 초기 상태값 설정 */
    p->security   = 50;    /* 보안 점수 초기값 */
    p->sales      = 100;   /* 매출 초기값 */
    p->reputation = 50;    /* 평판 초기값 */
    p->risk       = 30;    /* 도난 위험도 초기값 */
    p->score      = 0;     /* 총점 초기값 */

    printf("\n  %s 관리자님, 근무를 시작합니다!\n", p->name);
    printf("  총 %d개의 상황을 해결해야 합니다.\n", MAX_TURNS);
}

/* ──────────────────────────────────────────
 *  showStatus: 현재 상태 출력 함수
 *  - 구조체를 값으로 전달받아 출력만 합니다
 * ────────────────────────────────────────── */
void showStatus(Player p) {
    printf("\n  ┌─────────────────────────┐\n");
    printf("  │     [ 현재 매장 상태 ]    │\n");
    printf("  ├─────────────────────────┤\n");
    printf("  │  보안 점수  : %-10d │\n", p.security);
    printf("  │  매출       : %-10d │\n", p.sales);
    printf("  │  평판       : %-10d │\n", p.reputation);
    printf("  │  도난 위험도: %-10d │\n", p.risk);
    printf("  └─────────────────────────┘\n");
}

/* ──────────────────────────────────────────
 *  getChoice: 입력값 검증 함수
 *  - 1, 2, 3 이외의 값을 입력하면 다시 입력받습니다
 *  - 숫자가 아닌 문자를 입력해도 처리합니다
 * ────────────────────────────────────────── */
int getChoice() {
    int choice;
    int result;

    while (1) {
        printf("  선택 (1/2/3): ");
        result = scanf("%d", &choice);

        /* scanf가 숫자를 읽지 못한 경우 (문자 입력 등) */
        if (result != 1) {
            /* 입력 버퍼를 비워줍니다 */
            while (getchar() != '\n');
            printf("  [오류] 숫자 1, 2, 3 중 하나를 입력해주세요.\n");
            continue;
        }

        /* 1~3 범위 확인 */
        if (choice >= 1 && choice <= 3) {
            return choice;  /* 정상 입력이면 반환 */
        }

        printf("  [오류] 1, 2, 3 중 하나를 선택해주세요.\n");
    }
}

/* ──────────────────────────────────────────
 *  shuffleEvents: 이벤트 순서 섞기 (Fisher-Yates 알고리즘)
 *  - 같은 상황이 반복되지 않도록 순서를 랜덤으로 섞습니다
 * ────────────────────────────────────────── */
void shuffleEvents(int arr[], int size) {
    int i, j, temp;

    /* 배열을 0, 1, 2, ... 순서로 초기화 */
    for (i = 0; i < size; i++) {
        arr[i] = i;
    }

    /* Fisher-Yates 셔플: 뒤에서부터 랜덤 위치와 교환 */
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/* ──────────────────────────────────────────
 *  playGame: 게임 메인 루프
 *  - MAX_TURNS만큼 반복하면서 이벤트를 처리합니다
 * ────────────────────────────────────────── */
void playGame(Player *p) {
    int turn;
    int eventOrder[TOTAL_EVENTS];  /* 이벤트 순서 배열 */

    /* 이벤트 순서를 랜덤으로 섞습니다 */
    shuffleEvents(eventOrder, TOTAL_EVENTS);

    for (turn = 0; turn < MAX_TURNS; turn++) {
        printf("\n========================================\n");
        printf("         [ %d번째 상황 / %d턴 ]\n", turn + 1, MAX_TURNS);
        printf("========================================\n");

        /* 섞인 순서대로 이벤트 실행 (중복 방지) */
        handleEvent(p, eventOrder[turn]);

        /* 현재 상태 출력 */
        showStatus(*p);

        /* 게임 종료 조건 확인: 도난 위험도가 너무 높을 때 */
        if (p->risk >= RISK_LIMIT) {
            printf("\n  [게임 오버] 도난 위험도가 너무 높아졌습니다!\n");
            printf("  매장 관리에 실패하였습니다...\n");
            break;
        }

        /* 게임 종료 조건 확인: 평판이 너무 낮을 때 */
        if (p->reputation <= REP_LIMIT) {
            printf("\n  [게임 오버] 고객 평판이 너무 낮아졌습니다!\n");
            printf("  매장 운영에 실패하였습니다...\n");
            break;
        }
    }

    /* 최종 점수 계산:
       보안 + 매출 + 평판 - 도난위험도 */
    p->score = p->security + p->sales + p->reputation - p->risk;
}

/* ──────────────────────────────────────────
 *  handleEvent: 이벤트(상황) 처리 함수
 *  - 이벤트 번호에 따라 상황을 출력하고
 *    플레이어의 선택에 따라 상태값을 변경합니다
 *  - 총 8개의 이벤트가 있습니다
 * ────────────────────────────────────────── */
void handleEvent(Player *p, int eventNum) {
    int choice;

    switch (eventNum) {

    /* ── 이벤트 0: 도난 의심 상황 ── */
    case 0:
        printf("\n  [상황] 손님이 상품을 들고 결제하지 않은 채\n");
        printf("         출입구 쪽으로 이동하고 있습니다.\n\n");
        printf("  1. 바로 경찰에 신고한다.\n");
        printf("  2. 경고 방송을 한다.\n");
        printf("  3. 조금 더 지켜본다.\n");
        choice = getChoice();

        if (choice == 1) {
            p->security += 15;
            p->risk -= 15;
            p->reputation -= 10;
            printf("\n  -> 강한 대응으로 도난 위험은 줄었지만 평판이 감소하였습니다.\n");
        }
        else if (choice == 2) {
            p->security += 10;
            p->risk -= 10;
            printf("\n  -> 적절한 경고로 상황을 안정적으로 해결하였습니다.\n");
        }
        else {
            p->risk += 15;
            printf("\n  -> 대응이 늦어져 도난 위험도가 증가하였습니다.\n");
        }
        break;

    /* ── 이벤트 1: 결제 기계 사용법 모르는 손님 ── */
    case 1:
        printf("\n  [상황] 손님이 결제 기계 사용법을 몰라\n");
        printf("         당황하고 있습니다.\n\n");
        printf("  1. 원격으로 안내한다.\n");
        printf("  2. 무시한다.\n");
        printf("  3. 결제를 취소시킨다.\n");
        choice = getChoice();

        if (choice == 1) {
            p->sales += 20;
            p->reputation += 10;
            printf("\n  -> 친절한 안내로 매출과 평판이 증가하였습니다.\n");
        }
        else if (choice == 2) {
            p->reputation -= 15;
            printf("\n  -> 고객이 불편함을 느껴 평판이 감소하였습니다.\n");
        }
        else {
            p->sales -= 10;
            p->reputation -= 5;
            printf("\n  -> 결제가 취소되어 매출이 감소하였습니다.\n");
        }
        break;

    /* ── 이벤트 2: 단체 손님 밀집 ── */
    case 2:
        printf("\n  [상황] CCTV에 여러 명이 한꺼번에 몰려 있는\n");
        printf("         모습이 보입니다.\n\n");
        printf("  1. 경고 방송을 한다.\n");
        printf("  2. 그냥 둔다.\n");
        printf("  3. 출입 제한 안내를 한다.\n");
        choice = getChoice();

        if (choice == 1) {
            p->security += 10;
            p->risk -= 10;
            printf("\n  -> 매장 질서가 유지되었습니다.\n");
        }
        else if (choice == 2) {
            p->risk += 20;
            printf("\n  -> 관리가 부족하여 도난 위험도가 증가하였습니다.\n");
        }
        else {
            p->security += 15;
            p->reputation -= 5;
            printf("\n  -> 보안은 강화되었지만 일부 고객이 불편함을 느꼈습니다.\n");
        }
        break;

    /* ── 이벤트 3: 이중 결제 오류 ── */
    case 3:
        printf("\n  [상황] 결제 오류로 인해 손님이 같은 상품을\n");
        printf("         두 번 결제했습니다.\n\n");
        printf("  1. 환불 안내를 한다.\n");
        printf("  2. 모른 척한다.\n");
        printf("  3. 다음에 오면 할인해준다고 한다.\n");
        choice = getChoice();

        if (choice == 1) {
            p->reputation += 15;
            p->sales -= 10;
            printf("\n  -> 매출은 조금 줄었지만 고객 신뢰가 증가하였습니다.\n");
        }
        else if (choice == 2) {
            p->reputation -= 20;
            printf("\n  -> 고객 불만으로 평판이 크게 감소하였습니다.\n");
        }
        else {
            p->reputation += 5;
            printf("\n  -> 고객 불만을 어느 정도 줄였습니다.\n");
        }
        break;

    /* ── 이벤트 4: 야간 수상한 손님 ── */
    case 4:
        printf("\n  [상황] 야간 시간대에 수상한 손님이\n");
        printf("         오래 머물고 있습니다.\n\n");
        printf("  1. CCTV 확대 확인 후 경고한다.\n");
        printf("  2. 바로 신고한다.\n");
        printf("  3. 아무 조치도 하지 않는다.\n");
        choice = getChoice();

        if (choice == 1) {
            p->security += 10;
            p->risk -= 10;
            printf("\n  -> 신중한 대응으로 위험을 줄였습니다.\n");
        }
        else if (choice == 2) {
            p->security += 20;
            p->reputation -= 10;
            printf("\n  -> 보안은 강화되었지만 과한 대응으로 평판이 감소하였습니다.\n");
        }
        else {
            p->risk += 20;
            printf("\n  -> 수상한 상황을 방치하여 위험도가 증가하였습니다.\n");
        }
        break;

    /* ── 이벤트 5: 매장 내 음식물 섭취 ── */
    case 5:
        printf("\n  [상황] 손님이 계산하지 않은 음료를 매장 안에서\n");
        printf("         마시고 있습니다.\n\n");
        printf("  1. 방송으로 결제를 요청한다.\n");
        printf("  2. 무시하고 넘어간다.\n");
        printf("  3. 경고 후 퇴장 안내를 한다.\n");
        choice = getChoice();

        if (choice == 1) {
            p->sales += 15;
            p->reputation += 5;
            printf("\n  -> 정중한 안내로 결제가 이루어지고 매출이 증가하였습니다.\n");
        }
        else if (choice == 2) {
            p->sales -= 15;
            p->risk += 10;
            printf("\n  -> 매출 손실이 발생하고 도난 위험도가 증가하였습니다.\n");
        }
        else {
            p->security += 10;
            p->reputation -= 10;
            printf("\n  -> 보안은 강화되었지만 고객이 불쾌감을 느꼈습니다.\n");
        }
        break;

    /* ── 이벤트 6: 매장 시설 고장 ── */
    case 6:
        printf("\n  [상황] 매장의 냉장고가 고장나서\n");
        printf("         상품이 상할 위험이 있습니다.\n\n");
        printf("  1. 즉시 수리 업체에 연락한다.\n");
        printf("  2. 일단 다음 날까지 기다린다.\n");
        printf("  3. 해당 상품을 할인 판매한다.\n");
        choice = getChoice();

        if (choice == 1) {
            p->sales -= 10;
            p->reputation += 10;
            p->security += 5;
            printf("\n  -> 수리비가 들었지만 신속한 대응으로 평판이 올랐습니다.\n");
        }
        else if (choice == 2) {
            p->sales -= 25;
            p->reputation -= 10;
            printf("\n  -> 상품이 상해서 매출과 평판 모두 감소하였습니다.\n");
        }
        else {
            p->sales += 10;
            p->reputation += 5;
            printf("\n  -> 할인 판매로 손실을 줄이고 고객 만족도가 올랐습니다.\n");
        }
        break;

    /* ── 이벤트 7: 단골 고객 클레임 ── */
    case 7:
        printf("\n  [상황] 단골 고객이 \"지난번에 산 상품이\n");
        printf("         불량이었다\"며 항의하고 있습니다.\n\n");
        printf("  1. 정중히 사과하고 교환해준다.\n");
        printf("  2. 확인이 어렵다고 거절한다.\n");
        printf("  3. 할인 쿠폰을 제공한다.\n");
        choice = getChoice();

        if (choice == 1) {
            p->sales -= 10;
            p->reputation += 15;
            printf("\n  -> 교환 비용이 들었지만 고객 신뢰가 크게 올랐습니다.\n");
        }
        else if (choice == 2) {
            p->reputation -= 20;
            printf("\n  -> 단골 고객이 크게 실망하여 평판이 급감하였습니다.\n");
        }
        else {
            p->reputation += 10;
            p->sales -= 5;
            printf("\n  -> 쿠폰 제공으로 고객 불만을 줄였습니다.\n");
        }
        break;
    }
}

/* ──────────────────────────────────────────
 *  showResult: 최종 결과 및 등급 출력 함수
 *  - 최종 점수를 기준으로 S, A, B, C 등급을 부여합니다
 * ────────────────────────────────────────── */
void showResult(Player p) {
    printf("\n========================================\n");
    printf("           [ 최종 결과 ]\n");
    printf("========================================\n");
    printf("  관리자 이름 : %s\n", p.name);
    printf("  보안 점수   : %d\n", p.security);
    printf("  매출        : %d\n", p.sales);
    printf("  평판        : %d\n", p.reputation);
    printf("  도난 위험도 : %d\n", p.risk);
    printf("----------------------------------------\n");
    printf("  최종 점수   : %d\n", p.score);
    printf("----------------------------------------\n");

    /* 등급 판정 */
    if (p.score >= 200) {
        printf("  등급: ★ S등급 ★\n");
        printf("  매우 우수한 무인편의점 관리자입니다!\n");
    }
    else if (p.score >= 150) {
        printf("  등급: A등급\n");
        printf("  안정적으로 매장을 관리하였습니다.\n");
    }
    else if (p.score >= 100) {
        printf("  등급: B등급\n");
        printf("  기본적인 관리는 하였지만 보완이 필요합니다.\n");
    }
    else {
        printf("  등급: C등급\n");
        printf("  매장 관리에 어려움이 있었습니다.\n");
    }
    printf("========================================\n");
}

/* ──────────────────────────────────────────
 *  saveHighScore: 최고 점수를 파일에 저장하는 함수
 *  - 기존 최고 점수보다 높을 때만 덮어씁니다
 *  - 파일 입출력(fopen, fprintf, fscanf, fclose) 활용
 * ────────────────────────────────────────── */
void saveHighScore(Player p) {
    FILE *fp;           /* 파일 포인터 */
    int oldScore = 0;   /* 기존 최고 점수 */
    char oldName[30] = "";  /* 기존 최고 점수 플레이어 이름 */

    /* 기존 파일에서 최고 점수 읽기 */
    fp = fopen(SAVE_FILE, "r");
    if (fp != NULL) {
        /* 파일이 존재하면 기존 점수를 읽어옵니다 */
        fscanf(fp, "%s %d", oldName, &oldScore);
        fclose(fp);
    }

    /* 이번 점수가 기존보다 높으면 저장 */
    if (p.score > oldScore) {
        fp = fopen(SAVE_FILE, "w");
        if (fp != NULL) {
            fprintf(fp, "%s %d\n", p.name, p.score);
            fclose(fp);
            printf("\n  [저장] 새로운 최고 점수를 기록하였습니다! (%d점)\n", p.score);
        }
        else {
            printf("\n  [오류] 점수 저장에 실패하였습니다.\n");
        }
    }
    else {
        printf("\n  [기록] 현재 최고 점수: %s님의 %d점\n", oldName, oldScore);
        printf("         이번 점수: %d점 (갱신 실패)\n", p.score);
    }
}

/* ──────────────────────────────────────────
 *  loadHighScore: 최고 점수를 파일에서 불러오는 함수
 *  - 저장된 파일이 없으면 기록 없음을 출력합니다
 * ────────────────────────────────────────── */
void loadHighScore() {
    FILE *fp;
    int score;
    char name[30];

    fp = fopen(SAVE_FILE, "r");

    if (fp == NULL) {
        /* 파일이 없으면 아직 기록이 없는 상태 */
        printf("\n  [기록] 아직 저장된 최고 점수가 없습니다.\n");
        printf("         게임을 플레이해보세요!\n");
        return;
    }

    /* 파일에서 이름과 점수를 읽어옵니다 */
    if (fscanf(fp, "%s %d", name, &score) == 2) {
        printf("\n  ┌─────────────────────────┐\n");
        printf("  │     [ 최고 점수 기록 ]    │\n");
        printf("  ├─────────────────────────┤\n");
        printf("  │  이름 : %-15s │\n", name);
        printf("  │  점수 : %-15d │\n", score);
        printf("  └─────────────────────────┘\n");
    }
    else {
        printf("\n  [오류] 점수 파일을 읽는 데 실패하였습니다.\n");
    }

    fclose(fp);
}
