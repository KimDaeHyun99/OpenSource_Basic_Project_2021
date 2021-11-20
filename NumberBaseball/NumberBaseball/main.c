#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <windows.h> //gotoxy를 사용하기 위해
#include <stdlib.h> //난수  
#include <time.h> //씨드값 시간으로 두기위해

void gotoxy();          //x,y 좌표

void menu(); //메뉴


void playgame();
void record();          //대전기록을 불러오는 함수
void writing_record();  //대전기록을 입력하는 함수

void finding_algorithm(); //computer의 정답 맞추기 알고리즘

void check_the_answer(); //player와 computer가 정답을 입력하면 결과를 확인하여 스트라이크와 볼의 개수를 알려줌.

int m[3];
int d[3];
int u = 0;  //시도횟수
int k;      //메뉴 선택시
int x = 10; //x좌표
int y = 5;  //y좌표
int a, b, c=0;
int player_score[2] = { 1, 1 };  // {스트라이크, 볼}
int computer_score[2] = { 100, 100 };// {스트라이크, 볼}

                                    
float number_probability[3][10] = {
//(0    1    2    3    4    5    6    7    8    9)
{ 10,  10,  10,  10,  10,  10,  10,  10,  10,  10 },        //첫번째 자리의 각 수에 대한 확률
{ 10,  10,  10,  10,  10,  10,  10,  10,  10,  10 },        //두번째 자리의 각 수에 대한 확률
{ 10,  10,  10,  10,  10,  10,  10,  10,  10,  10 }         //세번째 자리의 각 수에 대한 확률
};                 

int player_answer[3];               //사용자의 정답을 저장할 배열 생성 
int player[3];                      //사용자가 맞출 정답을 입력할 배열 생성  
int computer_answer[3];             //컴퓨터의 정답을 저장할 배열 생성 
int computer[3];                    //컴퓨터가 맞출 정답을 입력할 배열


void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main()
{
    srand(time(NULL));  //현재 시간을 이용해서 씨드 결정
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
    printf("  1. 게임 시작");
	gotoxy(x, y + 1);   
    printf("  2. 대전기록 확인");
	gotoxy(x+2, y + 2);   
    printf("숫자를 입력하세요 : ");
    
    scanf_s("%d", &k);

    return 0;
}

void playgame()
{
    int i, j;
    int a; //순서

    for (i = 0; i < 3; i++)
    {
        computer_answer[i] = rand() % 10 + 0; // 0~9 사이의 숫자를 랜덤으로 입력 
        for (j = 0; j < i; j++)
        {
            if (computer_answer[i] == computer_answer[j])
            { //answer[]배열의 중복된 숫자를 검사  
                i--;
                break;
            }
        }
    }
    printf("컴퓨터가 맞출 사용자의 정답 : ");
    scanf_s("%d %d %d", &player_answer[0], &player_answer[1], &player_answer[2]);  //사용자의 정답을 입력
  

    
    for ( u = 0; u < 100; u++)   
    {
        printf("\n시도횟수 : %d\n수를 입력하세요 : ", u + 1);
        scanf_s("%d %d %d", &player[0], &player[1], &player[2]);
        finding_algorithm();
        
        if (player_score[0] == 3)
        {
            writing_record(); //player의 승리 기록
            u = 1000; //for문 탈출
        }
        if (computer_score[0] == 3)
        {
            writing_record(); //computer의 승리 기록
            u = 1000; //for문 탈출
        }
    }
    

 

    
}

void record()   //대전기록을 불러오는 함수
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
    //메모장에 날짜와 승패를 기록 ex)2021년 11월20일 11시 11분 player win!
    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 구조체에 넣기
    char str[50];

    FILE* fp = NULL;

    fp = fopen("NumberBaseball_record.txt", "a+");

    
    if (player_score[0] == 3)
    {
        fprintf(fp, "%d.%d.%d. %d:%d player win!\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min); //년도, 월, 일,시간, 분
    }
    else if (computer_score[0] == 3)
    {
        fprintf(fp, "%d.%d.%d. %d:%d computer win!\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min); //년도, 월, 일, 시간, 분
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
 
    printf("player   스트라이크 : %d  볼 : %d\n", player_score[0], player_score[1]);
    printf("computer 스트라이크 : %d  볼 : %d\n", computer_score[0], computer_score[1]);
    if (player_score[0] == 3) printf("player 승리!");
    if (computer_score[0] == 3) printf("computer 승리!");
    
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
                { //answer[]배열의 중복된 숫자를 검사  
                    i--;
                    break;
                }
            }
        }

        printf("computer의 수 : %d %d %d\n", computer[0], computer[1], computer[2]);

        check_the_answer();
        //스트라이크와 볼의 개수에 따른 확률 조정
        if (computer_score[0] == 0 && computer_score[1] == 0)   //out / 선택된 3개의 수에 확률 0을 부여하고, 나머지 수에 14.3의 확률을 부여
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

       
       
        ///////////////////////////스트라이크와 볼의 개수에 따른 0~9값의 확률 변화를 보기위한 코드
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

