#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <windows.h>

void menu();
void playrame();
void ranking();
void gotoxy();

int main()
{
  
    
    menu();  //�޴�



}


void gotoxy(int x, int y) { //gotoxy�Լ� 
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



void menu()
{
    int k;
	int x = 10;
	int y = 5;
	gotoxy(x , y);      
    printf("  1. ���� ����");
	gotoxy(x, y + 1);   
    printf("  2. ������� Ȯ��");
	gotoxy(x, y + 2);   
    printf("  3. ��ŷ Ȯ��");
    gotoxy(x + 2, y + 3);   
    printf("���ڸ� �Է��ϼ��� : "); 
    scanf_s("%d", &k);
}


void ranking()
{
    FILE* fp = NULL;

    fp = fopen("NumberBaseball_ranking.txt", "a+");



    /*                                          //ranking �Լ� Ȯ�ο� �ҽ��ڵ�
    for (int i = 0; i < 5; i++) {
    
        fputs("test\n", fp); //���ڿ� �Է�
    }
    fputs("end\n", fp);

    fclose(fp); //���� ������ �ݱ�
    */
    return 0;
}