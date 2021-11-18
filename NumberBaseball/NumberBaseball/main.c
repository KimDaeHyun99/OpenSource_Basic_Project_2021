#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <windows.h> //gotoxy�� ����ϱ� ����
#include <stdlib.h> //����  
#include <time.h> //���尪 �ð����� �α�����

void gotoxy();          //x,y ��ǥ

void menu();


void playgame();
void record();          //��������� �ҷ����� �Լ�
void writing_record();  //��������� �Է��ϴ� �Լ�
void ranking();         //������ �ҷ����� �Լ�
void writing_ranking(); //������ �Է��ϴ� �Լ�
void finding_algorithm(); //computer�� ���� ���߱� �˰���
int k;
int x = 10; //x��ǥ
int y = 5;  //y��ǥ

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main()
{
  
    
    menu();  //�޴�
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
    printf("  1. ���� ����");
	gotoxy(x, y + 1);   
    printf("  2. ������� Ȯ��");
	gotoxy(x, y + 2);   
    printf("  3. ��ŷ Ȯ��");
    gotoxy(x + 2, y + 3);   
    printf("���ڸ� �Է��ϼ��� : "); 
    scanf_s("%d", &k);

    return 0;
}

void playgame()
{
    int i, j;
    int a; //����
    int player_answer[3];               //������ ������ �迭 ���� 
    int player[3];                      //����ڰ� ������ �Է��� �迭 ����  
    int computer_answer[3];             //��ǻ���� ������ ������ �迭 ���� 
    int computer[3];                    //��ǻ�Ͱ� ������ �Է��� �迭



    for (i = 0; i < 3; i++)
    {
        srand(time(NULL)); //���� �ð��� �̿��ؼ� ���� ����
        computer_answer[i] = rand() % 9 + 1; // 1~9 ������ ���ڸ� �������� answer[] �Է� 
        for (j = 0; j < i; j++)
        {
            if (computer_answer[i] == computer_answer[j])
            { //answer[]�迭�� �ߺ��� ���ڸ� �˻�  
                i--;
                break;
            }
        }
    }

    scanf_s("%d %d %d", &player_answer[0], &player_answer[1], &player_answer[2]);  //������� ������ �Է�
    a = rand() % 2; // a�� 0�̸� player ����, a�� 1�̸� computer ����
    
    gotoxy(x, y);
    printf("������� ���� : %d %d %d", player_answer[0], player_answer[1], player_answer[2]);

    //computer�� ���� ã�� �˰���

    //writing_record�� ������ �Է�
    //writing_ranking�� ������ �Է�

    
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



    /*                                          //ranking �Լ� Ȯ�ο� �ҽ��ڵ�
    for (int i = 0; i < 5; i++) {
    
        fputs("test\n", fp); //���ڿ� �Է�
    }
    fputs("end\n", fp);

    fclose(fp); //���� ������ �ݱ�
    */
    return 0;
}

void writing_ranking()
{

}

void finding_algorithm()
{
    // 1-1) ���� ù��° �õ��� ���, ������ 3���� ���ڸ� �Է�
    // 1-1) 
    // 
    // 
    // 2) ���� ((��Ʈ����ũ + ���� ����) == 3)�̸�,
    // 2-1)  
    // 2-2)
    // 3) ���� ((��Ʈ����ũ + ���� ����) == 2)�̸�,
    // 3-1)
    // 3-2)
    // 4) ���� ((��Ʈ����ũ + ���� ����) == 1)�̸�,
    // 4-1) ���� (��Ʈ����ũ)�� ���, 
    // 4-2)
    // 5) ���� ((��Ʈ����ũ + ���� ����) == 0)�̸�,
    // 5-1) 
    //  
    //  �⺻ �ο� Ȯ��
    //  (   0    1   2   3   4   5   6   7   8   9)
    //  {   10  10  10  10  10  10  10  10  10  10}
    //  {   10  10  10  10  10  10  10  10  10  10}
    //  {   10  10  10  10  10  10  10  10  10  10}

}