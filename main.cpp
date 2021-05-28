#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define DINO_BOTTOM_Y 29
#define DINO_BOTTOM_X 0
#define DINO_BOTTOM_YH 29
#define TREE_BOTTOM_Y 35
#define TREE_BOTTOM_X 97
#define BIRD_BOTTOM_X 85

 
//콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
    system("mode con:cols=210 lines=50");
	//콘솔에서 커서 안보이게하는 코드
	HANDLE consoleHandle =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible =0;
	ConsoleCursor.dwSize=1;
	SetConsoleCursorInfo(consoleHandle,&ConsoleCursor);
}
 
//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
 
//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}
 
//공룡을 그리는 함수
void DrawDino(int dinoX,int dinoY,bool under)
{
    static bool legFlag = true;

		if(under){
			GotoXY(dinoX, dinoY);
			printf("                       ■■■■■■■■\n");
			GotoXY(dinoX, dinoY+1);
			printf("                     ■■  ■■■■■■■\n");
			GotoXY(dinoX, dinoY+2);
			printf("                     ■■■■■■■■■■\n");
			GotoXY(dinoX, dinoY+3);
			printf("                     ■■■■■■■■■■\n");
			GotoXY(dinoX, dinoY+4);
			printf("                     ■■■■■\n");
			GotoXY(dinoX, dinoY+5);
			printf("                     ■■■■■■■■\n");
			GotoXY(dinoX, dinoY+6);
			printf(" ■                ■■■■■\n");
			GotoXY(dinoX, dinoY+7);
			printf(" ■              ■■■■■■\n");
			GotoXY(dinoX, dinoY+8);
			printf(" ■■        ■■■■■■■■■■\n");
			GotoXY(dinoX, dinoY+9);
			printf(" ■■■    ■■■■■■■■■  ■\n");
			GotoXY(dinoX, dinoY+10);
			printf(" ■■■■■■■■■■■■■■    \n");
			GotoXY(dinoX, dinoY+11);
			printf("   ■■■■■■■■■■■■■    \n");
			GotoXY(dinoX, dinoY+12);
			printf("     ■■■■■■■■■■■\n");
			GotoXY(dinoX, dinoY+13);
			printf("       ■■■■■■■■■■\n");
			GotoXY(dinoX, dinoY+14);
			printf("         ■■■■■■■■\n");
			GotoXY(dinoX, dinoY+15);
			printf("           ■■■  ■■  \n");

			if (legFlag)
			{
				GotoXY(dinoX, dinoY+16);
				printf("           ■■      ■■  \n");
				GotoXY(dinoX, dinoY+17);
				printf("           ■          \n");
				GotoXY(dinoX, dinoY+18);
				printf("           ■■        \n");
				legFlag = false;
			}
			else
			{
				GotoXY(dinoX, dinoY+16);
				printf("               ■■  ■  \n");
				GotoXY(dinoX, dinoY+17);
				printf("                     ■  \n");
				GotoXY(dinoX, dinoY+18);
				printf("                     ■■  \n");
				legFlag = true;
			}
		}
		else
		{
			GotoXY(dinoX, dinoY+7);
			printf("  ■                                    ■■■■■■■■\n");
			GotoXY(dinoX, dinoY+8);
			printf("  ■■■        ■■■■■■■■■    ■■■■■■■■■■\n");
			GotoXY(dinoX, dinoY+9);
			printf("  ■■■■■■■■■■■■■■■■■■■■  ■■■■■■■\n");
			GotoXY(dinoX, dinoY+10);
			printf("    ■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			GotoXY(dinoX, dinoY+11);
			printf("      ■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			GotoXY(dinoX, dinoY+12);
			printf("        ■■■■■■■■■■■■■■■■■■■\n");
			GotoXY(dinoX, dinoY+13);
			printf("            ■■■■■■■■■■■■    ■■■■■■■\n");
			GotoXY(dinoX, dinoY+14);
			printf("             ■■■■■■■■■■■\n");
			if(legFlag)
			{
				GotoXY(dinoX, dinoY+15);
				printf("           ■■■    ■■      ■\n");
				GotoXY(dinoX, dinoY+16);
				printf("           ■■        ■■    ■■\n");
				GotoXY(dinoX, dinoY+17);
				printf("           ■      \n");
				GotoXY(dinoX, dinoY+18);
				printf("           ■■\n");
				legFlag = false;
			}
			else
			{
				GotoXY(dinoX, dinoY+15);
				printf("            ■    ■■■       ■\n");
				GotoXY(dinoX, dinoY+16);
				printf("            ■■  ■■         ■■\n");
				GotoXY(dinoX, dinoY+17);
				printf("                  ■\n");
				GotoXY(dinoX, dinoY+18);
				printf("                  ■■\n");
				legFlag = true;
			}
		}


}
//사용 안함
void DrawDinoUnder(int dinoX,int dinoY)
{
//■                                    ■■■■■■■■
//■■■        ■■■■■■■■■    ■■■■■■■■■■
//■■■■■■■■■■■■■■■■■■■■  ■■■■■■■
//  ■■■■■■■■■■■■■■■■■■■■■■■■■■■
//	■■■■■■■■■■■■■■■■■■■■■■■■■■
//	    ■■■■■■■■■■■■■■■■■■■
//		  ■■■■■■■■■■■■    ■■■■■■■■
//		   ■■■■■■■■■■■
//        ■    ■■■       ■
//        ■■  ■■         ■■
//              ■        
//              ■■
	static bool legFlag = true;
	GotoXY(dinoX, dinoY+7);
	printf("  ■                                    ■■■■■■■■\n");
	GotoXY(dinoX, dinoY+8);
    printf("  ■■■        ■■■■■■■■■    ■■■■■■■■■■\n");
	GotoXY(dinoX, dinoY+9);
    printf("  ■■■■■■■■■■■■■■■■■■■■  ■■■■■■■\n");
	GotoXY(dinoX, dinoY+10);
    printf("    ■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	GotoXY(dinoX, dinoY+11);
	printf("      ■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	GotoXY(dinoX, dinoY+12);
    printf("        ■■■■■■■■■■■■■■■■■■■\n");
	GotoXY(dinoX, dinoY+13);
    printf("            ■■■■■■■■■■■■    ■■■■■■■\n");
	GotoXY(dinoX, dinoY+14);
    printf("             ■■■■■■■■■■■\n");
	if(legFlag)
	{
		GotoXY(dinoX, dinoY+15);
		printf("           ■■■    ■■      ■\n");
		GotoXY(dinoX, dinoY+16);
		printf("           ■■        ■■    ■■\n");
		GotoXY(dinoX, dinoY+17);
		printf("           ■      \n");
		GotoXY(dinoX, dinoY+18);
		printf("           ■■\n");
		legFlag = false;
	}
	else
	{
		GotoXY(dinoX, dinoY+15);
		printf("            ■    ■■■       ■\n");
		GotoXY(dinoX, dinoY+16);
		printf("            ■■  ■■         ■■\n");
		GotoXY(dinoX, dinoY+17);
		printf("                  ■\n");
		GotoXY(dinoX, dinoY+18);
		printf("                  ■■\n");
		legFlag = true;
	}

}
 
//나무를 그리는 함수
void DrawTree(int treeX)
{
    GotoXY(treeX, TREE_BOTTOM_Y);
    printf("      ■■");
    GotoXY(treeX, TREE_BOTTOM_Y + 1);
    printf("      ■■    ■ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 2);
    printf("      ■■    ■");
    GotoXY(treeX, TREE_BOTTOM_Y + 3);
    printf("  ■  ■■    ■");
    GotoXY(treeX, TREE_BOTTOM_Y + 4);
    printf("  ■  ■■■■■");
    GotoXY(treeX, TREE_BOTTOM_Y + 5);
    printf("  ■  ■■■■■");
    GotoXY(treeX, TREE_BOTTOM_Y + 6);
    printf("  ■  ■■");
    GotoXY(treeX, TREE_BOTTOM_Y + 7);
    printf("  ■■■■");
    GotoXY(treeX, TREE_BOTTOM_Y + 8);
    printf("  ■■■■");
    GotoXY(treeX, TREE_BOTTOM_Y + 9);
    printf("      ■■");
    GotoXY(treeX, TREE_BOTTOM_Y + 10);
    printf("      ■■");
    GotoXY(treeX, TREE_BOTTOM_Y + 11);
    printf("      ■■");
    GotoXY(treeX, TREE_BOTTOM_Y + 12);
    printf("      ■■");
}

void DrawBird(int BirdX)
{
	//        ■■
	//      ■■■
	//    ■■■■■
	//  ■■■■■■
	//■■■■■■■■■■■■■■
	//            ■■■■■■■■■
	//			  ■■■■■■■■■■■■■■
	//			    ■■■■■■■■■■
	//				■■■■■■■■■■■■
	//				■■■■■■■■■
	//				■■■■
	//				■■■
	//				■■
	//				■■
	//				■
 //  
 //                 ■
 //                 ■■
 //                 ■■■
	//        ■■    ■■■
	//      ■■■    ■■■■
	//    ■■■■■  ■■■■■
	//  ■■■■■■  ■■■■■■
	//■■■■■■■■■■■■■■
	//            ■■■■■■■■■
	//			  ■■■■■■■■■■■■■■
	//			    ■■■■■■■■■■
	//				  ■■■■■■■■■■■
	//				    ■■■■■■■
	// 번갈아가면 날갯짓
	static bool wing = true;
	if(wing)
	{
		GotoXY(BirdX, TREE_BOTTOM_Y - 19);
		printf("             ■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 18);
		printf("             ■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 17);
		printf("             ■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 16);
		printf("        ■■    ■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 15);
		printf("      ■■■    ■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 14 );
		printf("    ■■■■■  ■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 13);
		printf("  ■■■■■■  ■■■■■■"); 
		GotoXY(BirdX, TREE_BOTTOM_Y - 12);
		printf("■■■■■■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 11);
		printf("            ■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 10);
		printf("            ■■■■■■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 9);
		printf("              ■■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 8);
		printf("                ■■■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 7);
		printf("                  ■■■■■■■");
		wing=false;
	}
	else
	{
		GotoXY(BirdX, TREE_BOTTOM_Y - 16);
		printf("        ■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 15);
		printf("      ■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 14);
		printf("    ■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 13);
		printf("  ■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 12);
		printf("■■■■■■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 11);
		printf("            ■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 10);
		printf("            ■■■■■■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 9);
		printf("              ■■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 8);
		printf("              ■■■■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 7);
		printf("              ■■■■■■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 6);
		printf("              ■■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 5);
		printf("              ■■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 4);
		printf("              ■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 3);
		printf("              ■■");
		GotoXY(BirdX, TREE_BOTTOM_Y - 2 );
		printf("              ■");
		wing=true;
	}

}
 
//(v2.0) 충돌 했을때 게임오버 그려줌
void DrawGameOver(const int score)
{
    system("cls");
    int x = 18;
    int y = 8;
    GotoXY(x, y);
    printf("===========================");
    GotoXY(x, y + 1);
    printf("======G A M E O V E R======");
    GotoXY(x, y + 2);    
    printf("===========================");
    GotoXY(x, y + 5);
    printf("SCORE : %d", score);
 
    printf("\n\n\n\n\n\n\n\n\n");
    while(1)
	{
		if(GetKeyDown() == VK_SPACE){
			break;
		}
	}
}
 
//(v2.0) 충돌했으면 true, 아니면 false
bool isCollision(const int treeX, const int dinoY)
{
    //트리의 X가 공룡의 몸체쪽에 있을때,
    //공룡의 높이가 충분하지 않다면 충돌로 처리
    GotoXY(0, 0);
    printf("treeX : %d, dinoY : %d", treeX, dinoY); //x,y값을 확인하기 위함
    if (treeX <= 8 && treeX >= 6 && dinoY > 12)
    {
        return true;
    }
    return false;
}

bool isCollision2(const int BirdX, const int dinoHY)
{
    //0528 익룡의 X가 공룡의 몸체쪽에 있을때,
    //0528 공룡의 높이가 충분하지 않다면 충돌로 처리
	GotoXY(0, 2);
    printf("BirdX : %d, dinoHY : %d", BirdX, dinoHY); //x,y값을 확인하기 위함
    if (BirdX < 10 && BirdX >= 9 && dinoHY < 36)
    {
        return true;
    }
    return false;
}

void ranking()
{
	system("cls");
    int x = 18;
    int y = 8;
    GotoXY(x, y);
    printf("===========================");
    GotoXY(x, y + 1);
    printf("==========ranking==========");
    GotoXY(x, y + 2);    
    printf("===========================");
 
    printf("\n\n\n\n\n\n\n\n\n");
	getch();
}

void play()
{
	//while (true)        //(v2.0) 게임 루프
 //   {
        //게임 시작시 초기화
        bool isJumping = false;
        bool isBottom = true;
		bool isDown = false;//0528 숙임 판별여부 bool값
		bool isTop = true; //0528 땅 찍었는지 판별여부 bool값

        const int gravity = 5;
		bool  under = true; //0528 x입력시 숙이는거 판별하는 bool값
		
		srand((unsigned int)time(NULL));

		int num = 2; //0528 장애물 초기설정값 1이면 선인장,2이면 익룡 나옴 확인을 위해서 익룡 기본으로 둠
        int dinoX = DINO_BOTTOM_X;
        int dinoY = DINO_BOTTOM_Y;
        int treeX = TREE_BOTTOM_X;
		int BirdX = BIRD_BOTTOM_X; //0528 익룡x값 변수 초기화
		int dinoHY = DINO_BOTTOM_YH; //0528 보이지않는 충돌값 이걸로 익룡에 충돌했는지 안했는지 확인
        
        int score = 0;
        clock_t start, curr;    //점수 변수 초기화
        start = clock();        //시작시간 초기화
		//under2 = clock();
 
        while (true)    //한 판에 대한 루프
        {
			curr = clock();            //현재시간 받아오기

            //충돌체크 트리의 x값과 공룡의 y값으로 판단
            if(isCollision(treeX, dinoY)&&num==1)
                break;
			if(isCollision2(BirdX, dinoHY)&&num==2)
                break;
			/*getKeyDown사용자정의 함수를 while문 안에서 사용하면 키를 동시입력 받지 못하는
			문제가 있어서 kbhit과getche를 사용하였음
			*/
            if (_kbhit())
            {
                char op = _getche();
                //z키가 눌렸고, 바닥이 아닐때 점프
                if (op == 'z' && isBottom)
                {
                    isJumping = true;
                    isBottom = false;
                }
				//0528 x키가 눌렸고 숙인 상태가 아니라면 숙임
                else if (op == 'x'&& isTop)
                {
					isDown = true;
					isTop = false;
                    under = false;
                }
            }
			//0528 숙인상태인지 확인
			if(under == false)
			{
				if (((curr - start) / CLOCKS_PER_SEC) >= 1)	//0528 숙이고 난뒤 1초가 지나면 true값을 줘서 일어남
				{
					under = true;
				}
			}
			//0528 장애물 랜덤 출력 1이면 선인장 출력,2면 익룡 출력
			if(num == 1)
			{
				DrawTree(treeX);
			}
			else if(num == 2)
			{
				DrawBird(BirdX);
			}

            DrawDino(dinoX, dinoY,under);
 


            //점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가
            if (isJumping)
            {
                dinoY -= gravity;
            }
            else
            {
                dinoY += gravity;
            }
            //Y가 계속해서 증가하는걸 막기위해 바닥 지정
            if (dinoY >= DINO_BOTTOM_Y)
            {
                dinoY = DINO_BOTTOM_Y;
                isBottom = true;
            }
            //점프의 맨위를 찍으면 점프가 끝난 상황.
            if (dinoY <= 5)
            {
                isJumping = false;
            }



            //0528 *다운*중 이라면 Y를 증가, 점프가 끝났으면 Y를 감소
            if (isDown)
            {
				dinoHY = 47;
            }
            else
            {
				dinoHY = 29;
            }
            //0528 HY가 계속해서 유지되는걸 막기위해 천장 지정
            if (dinoHY <= DINO_BOTTOM_YH)
            {
                dinoHY = DINO_BOTTOM_YH;
                isTop = true;
            }
            //다운의 땅를 찍으면 다운이 끝난 상황.
            if (dinoHY == 47)
            {
				//0528 1초가 지났는지를 판별하고 지났으면 isDown에 false값 줌
				if (((curr - start) / CLOCKS_PER_SEC) >= 1)
				{
					isDown = false;
				}
			}




			//선인장
			if(num == 1)
			{
				//나무가 왼쪽으로 (x음수) 가도록하고
				//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
				if (score<21 && score>=0)
				{
					treeX -= 2;
					if (treeX <= -1)
					{
					treeX = TREE_BOTTOM_X;
					// 나무가 지나가면 rand로 랜덤값 출력 여기서 이중포인터로 초기화해줘야 오류안남
					int num1 = (rand()%2)+1;
					num = num1;
					}

				}

				if (score<40 && score>=21)
				{
					treeX -= 3;
					if (treeX <= -1)
					{
					treeX = TREE_BOTTOM_X;
					int num1 = (rand()%2)+1;
					num = num1;
					}
				}
			}
			//익룡
			if(num == 2)
			{
				//익룡이 왼쪽으로 (x음수) 가도록하고
				//익룡의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
				if (score<21 && score>=0)
				{
					BirdX -= 2;
					if (BirdX <= -1)
					{
					BirdX = BIRD_BOTTOM_X;
					// 익룡이 지나가면 rand로 랜덤값 출력 여기서 이중포인터로 초기화해줘야 오류안남
					int num1 = (rand()%2)+1;
					num = num1;
					}

				}
				if (score<40 && score>=21)
				{
					BirdX -= 3;
					if (BirdX <= -1)
					{
					BirdX = BIRD_BOTTOM_X;
					int num1 = (rand()%2)+1;
					num = num1;
					}
				}
			}

			//랜덤값 잘 나오는지 테스트
			GotoXY(30, 0);    
			printf("random : %d",num);

            if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1초가 넘었을떄
            {
                score++;    //스코어 UP
                start = clock();    //시작시간 초기화
            }
            Sleep(60);
            system("cls");    //clear
 
            GotoXY(22, 0);    
            printf("Score : %d", score);    //점수 출력
        }
		DrawGameOver(score);
	//}
}




 
int main()
{
    SetConsoleView(); 

	do
	{
		system("cls");
		int x = 24;
		int y = 12;
		GotoXY(x,y);
		printf("1.게임시작");
		GotoXY(x,y+1);
		printf("2.랭킹");
		GotoXY(x,y+2);
		printf("3.종료");

		char op=getch();

		if(op=='1') 
			play();
		else if(op=='2') 
			ranking();
		else if(op=='3') 
			exit(0);

	}while(1);

	return 0;
}
