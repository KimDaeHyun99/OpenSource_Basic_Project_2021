#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <windows.h>

void menu();
void playrame();
void ranking();
void gotoxy();

int main()
{
  
    
    menu();  //메뉴



}


void gotoxy(int x, int y) { //gotoxy함수 
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



void menu()
{
    int k;
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