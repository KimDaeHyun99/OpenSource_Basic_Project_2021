#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <windows.h> //gotoxy를 사용하기 위해
#include <stdlib.h> //난수  
#include <time.h> //씨드값 시간으로 두기위해

void gotoxy();          //x,y 좌표

void menu();


void playgame();
void record();          //대전기록을 불러오는 함수
void writing_record();  //대전기록을 입력하는 함수
void ranking();         //순위를 불러오는 함수
void writing_ranking(); //순위를 입력하는 함수
void finding_algorithm(); //computer의 정답 맞추기 알고리즘
int k;
int x = 10; //x좌표
int y = 5;  //y좌표

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main()
{
  
    
    menu();  //메뉴
    if (k == 1)        playgame();
    else if (k == 2)   record();
    else if (k == 3)   ranking();

    return 0;
}



void menu()
{
    
	int x = 10;
	int y = 5;
	gotoxy(x , y);
    printf("  1. 게임 시작");
	gotoxy(x, y + 1);   
    printf("  2. 대전기록 확인");
	gotoxy(x, y + 2);   
    printf("  3. 랭킹 확인");
    gotoxy(x + 2, y + 3);   
    printf("숫자를 입력하세요 : "); 
    scanf_s("%d", &k);

    return 0;
}

void playgame()
{
    int i, j;
    int a; //순서
    int player_answer[3];               //정답을 저장할 배열 생성 
    int player[3];                      //사용자가 정답을 입력할 배열 생성  
    int computer_answer[3];             //컴퓨터의 정답을 저장할 배열 생성 
    int computer[3];                    //컴퓨터가 정답을 입력할 배열



    for (i = 0; i < 3; i++)
    {
        srand(time(NULL)); //현재 시간을 이용해서 씨드 결정
        computer_answer[i] = rand() % 9 + 1; // 1~9 사이의 숫자를 랜덤으로 answer[] 입력 
        for (j = 0; j < i; j++)
        {
            if (computer_answer[i] == computer_answer[j])
            { //answer[]배열의 중복된 숫자를 검사  
                i--;
                break;
            }
        }
    }

    scanf_s("%d %d %d", &player_answer[0], &player_answer[1], &player_answer[2]);  //사용자의 정답을 입력
    a = rand() % 2; // a가 0이면 player 선공, a가 1이면 computer 선공
    
    gotoxy(x, y);
    printf("사용자의 정답 : %d %d %d", player_answer[0], player_answer[1], player_answer[2]);

    //computer의 정답 찾기 알고리즘

    //writing_record에 데이터 입력
    //writing_ranking에 데이터 입력

    
}

void record()
{
    FILE* fp = NULL;

    fp = fopen("NumberBaseball_record.txt", "a+");


    return 0;
}

void writing_record()
{

}

void ranking()
{
    FILE* fp = NULL;

    fp = fopen("NumberBaseball_ranking.txt", "a+");



    /*                                          //ranking 함수 확인용 소스코드
    for (int i = 0; i < 5; i++) {
    
        fputs("test\n", fp); //문자열 입력
    }
    fputs("end\n", fp);

    fclose(fp); //파일 포인터 닫기
    */
    return 0;
}

void writing_ranking()
{

}

void finding_algorithm()
{
    // 1-1) 제일 첫번째 시도일 경우, 랜덤의 3가지 숫자를 입력
    // 1-1) 
    // 
    // 
    // 2) 만약 ((스트라이크 + 볼의 개수) == 3)이면,
    // 2-1)  
    // 2-2)
    // 3) 만약 ((스트라이크 + 볼의 개수) == 2)이면,
    // 3-1)
    // 3-2)
    // 4) 만약 ((스트라이크 + 볼의 개수) == 1)이면,
    // 4-1) 만약 (스트라이크)일 경우, 
    // 4-2)
    // 5) 만약 ((스트라이크 + 볼의 개수) == 0)이면,
    // 5-1) 
    //  
    //  기본 부여 확률
    //  (   0    1   2   3   4   5   6   7   8   9)
    //  {   10  10  10  10  10  10  10  10  10  10}
    //  {   10  10  10  10  10  10  10  10  10  10}
    //  {   10  10  10  10  10  10  10  10  10  10}

}