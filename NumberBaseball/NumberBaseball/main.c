#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <windows.h> //gotoxy�� ����ϱ� ����
#include <stdlib.h> //����  
#include <time.h> //���尪 �ð����� �α�����

void gotoxy();          //x,y ��ǥ

void menu(); //�޴�


void playgame();
void record();          //��������� �ҷ����� �Լ�
void writing_record();  //��������� �Է��ϴ� �Լ�

void finding_algorithm(); //computer�� ���� ���߱� �˰���

void check_the_answer(); //player�� computer�� ������ �Է��ϸ� ����� Ȯ���Ͽ� ��Ʈ����ũ�� ���� ������ �˷���.

int m[3];
int d[3];
int u = 0;  //�õ�Ƚ��
int k;      //�޴� ���ý�
int x = 10; //x��ǥ
int y = 5;  //y��ǥ
int a, b, c=0;
int player_score[2] = { 1, 1 };  // {��Ʈ����ũ, ��}
int computer_score[2] = { 100, 100 };// {��Ʈ����ũ, ��}

                                    
float number_probability[3][10] = {
//(0    1    2    3    4    5    6    7    8    9)
{ 10,  10,  10,  10,  10,  10,  10,  10,  10,  10 },        //ù��° �ڸ��� �� ���� ���� Ȯ��
{ 10,  10,  10,  10,  10,  10,  10,  10,  10,  10 },        //�ι�° �ڸ��� �� ���� ���� Ȯ��
{ 10,  10,  10,  10,  10,  10,  10,  10,  10,  10 }         //����° �ڸ��� �� ���� ���� Ȯ��
};                 

int player_answer[3];               //������� ������ ������ �迭 ���� 
int player[3];                      //����ڰ� ���� ������ �Է��� �迭 ����  
int computer_answer[3];             //��ǻ���� ������ ������ �迭 ���� 
int computer[3];                    //��ǻ�Ͱ� ���� ������ �Է��� �迭


void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main()
{
    srand(time(NULL));  //���� �ð��� �̿��ؼ� ���� ����
    do
    {
        menu();
        if (k == 1)        playgame();
        else if (k == 2)   record();

    } while (0);
    
     

    return 0;
}



void menu() 
{
    
	x = 10;
	y = 5;
	gotoxy(x , y);
    printf("  1. ���� ����");
	gotoxy(x, y + 1);   
    printf("  2. ������� Ȯ��");
	gotoxy(x+2, y + 2);   
    printf("���ڸ� �Է��ϼ��� : ");
    
    scanf_s("%d", &k);

    return 0;
}

void playgame()
{
    int i, j;
    int a; //����

    for (i = 0; i < 3; i++)
    {
        computer_answer[i] = rand() % 10 + 0; // 0~9 ������ ���ڸ� �������� �Է� 
        for (j = 0; j < i; j++)
        {
            if (computer_answer[i] == computer_answer[j])
            { //answer[]�迭�� �ߺ��� ���ڸ� �˻�  
                i--;
                break;
            }
        }
    }
    printf("��ǻ�Ͱ� ���� ������� ���� : ");
    scanf_s("%d %d %d", &player_answer[0], &player_answer[1], &player_answer[2]);  //������� ������ �Է�
  

    
    for ( u = 0; u < 100; u++)   
    {
        printf("\n�õ�Ƚ�� : %d\n���� �Է��ϼ��� : ", u + 1);
        scanf_s("%d %d %d", &player[0], &player[1], &player[2]);
        finding_algorithm();
        
        if (player_score[0] == 3)
        {
            writing_record(); //player�� �¸� ���
            u = 1000; //for�� Ż��
        }
        if (computer_score[0] == 3)
        {
            writing_record(); //computer�� �¸� ���
            u = 1000; //for�� Ż��
        }
    }
    

 

    
}

void record()   //��������� �ҷ����� �Լ�
{
    FILE* fp = NULL;
    char getstr[100];
    fp = fopen("NumberBaseball_record.txt", "a+");
    
    char line[100];
    char* pLine;
    while (!feof(fp)) {
        pLine = fgets(line, 100, fp);
        printf("%s", pLine);
    }
    fclose(fp);
    return 0;
}

void writing_record()
{
    //�޸��忡 ��¥�� ���и� ��� ex)2021�� 11��20�� 11�� 11�� player win!
    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �����Ͽ� ��������� ��
    t = localtime(&timer); // ����ü�� �ֱ�
    char str[50];

    FILE* fp = NULL;

    fp = fopen("NumberBaseball_record.txt", "a+");

    
    if (player_score[0] == 3)
    {
        fprintf(fp, "%d.%d.%d. %d:%d player win!\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min); //�⵵, ��, ��,�ð�, ��
    }
    else if (computer_score[0] == 3)
    {
        fprintf(fp, "%d.%d.%d. %d:%d computer win!\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min); //�⵵, ��, ��, �ð�, ��
    }
    fclose(fp);
    return 0;
}




void check_the_answer()
{
    player_score[0] = 0;  
    player_score[1] = 0;
    computer_score[0] = 0;
    computer_score[1] = 0;
 

            
            
            for (int i = 0; i < 3; i++)
            {
                if (computer_answer[i] == player[i]) player_score[0] += 1;
                if (player_answer[i] == computer[i]) computer_score[0] += 1;
            
                for (int j = 0; j < 3; j++)
                {
                    if (i != j && computer_answer[i] == player[j]) player_score[1] += 1;
                    if (i != j && player_answer[i] == computer[j]) computer_score[1] += 1;

                }
            }
 
    printf("player   ��Ʈ����ũ : %d  �� : %d\n", player_score[0], player_score[1]);
    printf("computer ��Ʈ����ũ : %d  �� : %d\n", computer_score[0], computer_score[1]);
    if (player_score[0] == 3) printf("player �¸�!");
    if (computer_score[0] == 3) printf("computer �¸�!");
    
}



void finding_algorithm()
{
    int min[3] = {100, 100, 100};
    
    
        for (int i = 0; i < 3; i++)
        {
            int zzz = 0;
            for (int p = 0; p < 10; p++)
            {

                zzz += number_probability[i][p];
            }
            int z = rand() % zzz + 1;



            for (int j = 0; j < 10; j++)
            {
                if (z > 10)
                {
                    z -= number_probability[i][j];
                    computer[i] = j;
                    d[i] = j;

                }

            }

            for (int j = 0; j < i; j++)
            {
                if (computer[i] == computer[j])
                { //answer[]�迭�� �ߺ��� ���ڸ� �˻�  
                    i--;
                    break;
                }
            }
        }

        printf("computer�� �� : %d %d %d\n", computer[0], computer[1], computer[2]);

        check_the_answer();
        //��Ʈ����ũ�� ���� ������ ���� Ȯ�� ����
        if (computer_score[0] == 0 && computer_score[1] == 0)   //out / ���õ� 3���� ���� Ȯ�� 0�� �ο��ϰ�, ������ ���� 14.3�� Ȯ���� �ο�
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (number_probability[i][j] != 0)
                    {
                        number_probability[i][j] += 14.3;
                    }

                }
                number_probability[i][d[0]] = 0;
                number_probability[i][d[1]] = 0;
                number_probability[i][d[2]] = 0;
            }

        }

        if (computer_score[0] == 1 && computer_score[1] == 0)   //1s
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (number_probability[i][j] != 0)
                    {
                        number_probability[i][j] += 12.5;
                    }
                }
            }
            number_probability[0][d[1]] = 0;
            number_probability[0][d[2]] = 0;
            number_probability[1][d[0]] = 0;
            number_probability[1][d[2]] = 0;
            number_probability[2][d[0]] = 0;
            number_probability[2][d[1]] = 0;
        }

        if (computer_score[0] == 0 && computer_score[1] == 1)   //1b
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (number_probability[i][j] != 0)
                    {
                        number_probability[i][j] += 11;
                    }
                }
            }
            number_probability[0][d[1]] += 11.5;
            number_probability[0][d[2]] += 11.5;
            number_probability[1][d[0]] += 11.5;
            number_probability[1][d[2]] += 11.5;
            number_probability[2][d[0]] += 11.5;
            number_probability[2][d[1]] += 11.5;
            number_probability[0][d[0]] = 0;
            number_probability[1][d[1]] = 0;
            number_probability[2][d[2]] = 0;
        }

        if (computer_score[0] == 0 && computer_score[1] == 2)   //2b
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (number_probability[i][j] != 0)
                    {
                        number_probability[i][j] += 10;
                    }
                }
            }
            number_probability[0][d[1]] += 15;
            number_probability[0][d[2]] += 15;
            number_probability[1][d[0]] += 15;
            number_probability[1][d[2]] += 15;
            number_probability[2][d[0]] += 15;
            number_probability[2][d[1]] += 15;
            number_probability[0][d[0]] = 0;
            number_probability[1][d[1]] = 0;
            number_probability[2][d[2]] = 0;
        }

        if (computer_score[0] == 1 && computer_score[1] == 1)   //1s 1b
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (number_probability[i][j] != 0)
                    {
                        number_probability[i][j] += 7;
                    }
                }
            }
            number_probability[0][d[0]] += 17;
            number_probability[0][d[1]] += 17;
            number_probability[0][d[2]] += 17;
            number_probability[1][d[0]] += 17;
            number_probability[1][d[1]] += 17;
            number_probability[1][d[2]] += 17;
            number_probability[2][d[0]] += 17;
            number_probability[2][d[1]] += 17;
            number_probability[2][d[2]] += 17;


        }

        if (computer_score[0] == 2 && computer_score[1] == 0)   //2s
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (number_probability[i][j] != 0)
                    {
                        number_probability[i][j] += 6;
                    }
                }
            }
            number_probability[0][d[0]] += 19;
            number_probability[0][d[1]] += 19;
            number_probability[0][d[2]] += 19;
            number_probability[1][d[0]] += 19;
            number_probability[1][d[1]] += 19;
            number_probability[1][d[2]] += 19;
            number_probability[2][d[0]] += 19;
            number_probability[2][d[1]] += 19;
            number_probability[2][d[2]] += 19;
        }

        if (computer_score[0] == 0 && computer_score[1] == 3)   //3b
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (number_probability[i][j] != 0)
                    {
                        number_probability[i][j] = 0;
                    }
                }
            }

            number_probability[0][d[1]] += 50;
            number_probability[0][d[2]] += 50;
            number_probability[1][d[0]] += 50;
            number_probability[1][d[2]] += 50;
            number_probability[2][d[0]] += 50;
            number_probability[2][d[1]] += 50;
        }

        if (computer_score[0] == 1 && computer_score[1] == 2)   //1s 2b
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (number_probability[i][j] != 0)
                    {
                        number_probability[i][j] = 0;
                    }
                }
            }

            number_probability[0][d[0]] += 33;
            number_probability[0][d[1]] += 33;
            number_probability[0][d[2]] += 33;
            number_probability[1][d[0]] += 33;
            number_probability[1][d[1]] += 33;
            number_probability[1][d[2]] += 33;
            number_probability[2][d[0]] += 33;
            number_probability[2][d[1]] += 33;
            number_probability[2][d[2]] += 33;
        }

       
       
        ///////////////////////////��Ʈ����ũ�� ���� ������ ���� 0~9���� Ȯ�� ��ȭ�� �������� �ڵ�
        /*
        for (int i = 0; i < 3; i++) 
        {
            printf("\n");
            for (int j = 0; j < 10; j++)
            {
                printf("%f / ", number_probability[i][j]);
            }
        }
        */
        /////////////////////////////////////////////////////////////////////////////////
}

