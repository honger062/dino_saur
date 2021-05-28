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

 
//�ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView()
{
    system("mode con:cols=210 lines=50");
	//�ֿܼ��� Ŀ�� �Ⱥ��̰��ϴ� �ڵ�
	HANDLE consoleHandle =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible =0;
	ConsoleCursor.dwSize=1;
	SetConsoleCursorInfo(consoleHandle,&ConsoleCursor);
}
 
//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
 
//Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}
 
//������ �׸��� �Լ�
void DrawDino(int dinoX,int dinoY,bool under)
{
    static bool legFlag = true;

		if(under){
			GotoXY(dinoX, dinoY);
			printf("                       ���������\n");
			GotoXY(dinoX, dinoY+1);
			printf("                     ���  ��������\n");
			GotoXY(dinoX, dinoY+2);
			printf("                     �����������\n");
			GotoXY(dinoX, dinoY+3);
			printf("                     �����������\n");
			GotoXY(dinoX, dinoY+4);
			printf("                     ������\n");
			GotoXY(dinoX, dinoY+5);
			printf("                     ���������\n");
			GotoXY(dinoX, dinoY+6);
			printf(" ��                ������\n");
			GotoXY(dinoX, dinoY+7);
			printf(" ��              �������\n");
			GotoXY(dinoX, dinoY+8);
			printf(" ���        �����������\n");
			GotoXY(dinoX, dinoY+9);
			printf(" ����    ����������  ��\n");
			GotoXY(dinoX, dinoY+10);
			printf(" ���������������    \n");
			GotoXY(dinoX, dinoY+11);
			printf("   ��������������    \n");
			GotoXY(dinoX, dinoY+12);
			printf("     ������������\n");
			GotoXY(dinoX, dinoY+13);
			printf("       �����������\n");
			GotoXY(dinoX, dinoY+14);
			printf("         ���������\n");
			GotoXY(dinoX, dinoY+15);
			printf("           ����  ���  \n");

			if (legFlag)
			{
				GotoXY(dinoX, dinoY+16);
				printf("           ���      ���  \n");
				GotoXY(dinoX, dinoY+17);
				printf("           ��          \n");
				GotoXY(dinoX, dinoY+18);
				printf("           ���        \n");
				legFlag = false;
			}
			else
			{
				GotoXY(dinoX, dinoY+16);
				printf("               ���  ��  \n");
				GotoXY(dinoX, dinoY+17);
				printf("                     ��  \n");
				GotoXY(dinoX, dinoY+18);
				printf("                     ���  \n");
				legFlag = true;
			}
		}
		else
		{
			GotoXY(dinoX, dinoY+7);
			printf("  ��                                    ���������\n");
			GotoXY(dinoX, dinoY+8);
			printf("  ����        ����������    �����������\n");
			GotoXY(dinoX, dinoY+9);
			printf("  ���������������������  ��������\n");
			GotoXY(dinoX, dinoY+10);
			printf("    ����������������������������\n");
			GotoXY(dinoX, dinoY+11);
			printf("      ���������������������������\n");
			GotoXY(dinoX, dinoY+12);
			printf("        ��������������������\n");
			GotoXY(dinoX, dinoY+13);
			printf("            �������������    ��������\n");
			GotoXY(dinoX, dinoY+14);
			printf("             ������������\n");
			if(legFlag)
			{
				GotoXY(dinoX, dinoY+15);
				printf("           ����    ���      ��\n");
				GotoXY(dinoX, dinoY+16);
				printf("           ���        ���    ���\n");
				GotoXY(dinoX, dinoY+17);
				printf("           ��      \n");
				GotoXY(dinoX, dinoY+18);
				printf("           ���\n");
				legFlag = false;
			}
			else
			{
				GotoXY(dinoX, dinoY+15);
				printf("            ��    ����       ��\n");
				GotoXY(dinoX, dinoY+16);
				printf("            ���  ���         ���\n");
				GotoXY(dinoX, dinoY+17);
				printf("                  ��\n");
				GotoXY(dinoX, dinoY+18);
				printf("                  ���\n");
				legFlag = true;
			}
		}


}
//��� ����
void DrawDinoUnder(int dinoX,int dinoY)
{
//��                                    ���������
//����        ����������    �����������
//���������������������  ��������
//  ����������������������������
//	���������������������������
//	    ��������������������
//		  �������������    ���������
//		   ������������
//        ��    ����       ��
//        ���  ���         ���
//              ��        
//              ���
	static bool legFlag = true;
	GotoXY(dinoX, dinoY+7);
	printf("  ��                                    ���������\n");
	GotoXY(dinoX, dinoY+8);
    printf("  ����        ����������    �����������\n");
	GotoXY(dinoX, dinoY+9);
    printf("  ���������������������  ��������\n");
	GotoXY(dinoX, dinoY+10);
    printf("    ����������������������������\n");
	GotoXY(dinoX, dinoY+11);
	printf("      ���������������������������\n");
	GotoXY(dinoX, dinoY+12);
    printf("        ��������������������\n");
	GotoXY(dinoX, dinoY+13);
    printf("            �������������    ��������\n");
	GotoXY(dinoX, dinoY+14);
    printf("             ������������\n");
	if(legFlag)
	{
		GotoXY(dinoX, dinoY+15);
		printf("           ����    ���      ��\n");
		GotoXY(dinoX, dinoY+16);
		printf("           ���        ���    ���\n");
		GotoXY(dinoX, dinoY+17);
		printf("           ��      \n");
		GotoXY(dinoX, dinoY+18);
		printf("           ���\n");
		legFlag = false;
	}
	else
	{
		GotoXY(dinoX, dinoY+15);
		printf("            ��    ����       ��\n");
		GotoXY(dinoX, dinoY+16);
		printf("            ���  ���         ���\n");
		GotoXY(dinoX, dinoY+17);
		printf("                  ��\n");
		GotoXY(dinoX, dinoY+18);
		printf("                  ���\n");
		legFlag = true;
	}

}
 
//������ �׸��� �Լ�
void DrawTree(int treeX)
{
    GotoXY(treeX, TREE_BOTTOM_Y);
    printf("      ���");
    GotoXY(treeX, TREE_BOTTOM_Y + 1);
    printf("      ���    �� ");
    GotoXY(treeX, TREE_BOTTOM_Y + 2);
    printf("      ���    ��");
    GotoXY(treeX, TREE_BOTTOM_Y + 3);
    printf("  ��  ���    ��");
    GotoXY(treeX, TREE_BOTTOM_Y + 4);
    printf("  ��  ������");
    GotoXY(treeX, TREE_BOTTOM_Y + 5);
    printf("  ��  ������");
    GotoXY(treeX, TREE_BOTTOM_Y + 6);
    printf("  ��  ���");
    GotoXY(treeX, TREE_BOTTOM_Y + 7);
    printf("  �����");
    GotoXY(treeX, TREE_BOTTOM_Y + 8);
    printf("  �����");
    GotoXY(treeX, TREE_BOTTOM_Y + 9);
    printf("      ���");
    GotoXY(treeX, TREE_BOTTOM_Y + 10);
    printf("      ���");
    GotoXY(treeX, TREE_BOTTOM_Y + 11);
    printf("      ���");
    GotoXY(treeX, TREE_BOTTOM_Y + 12);
    printf("      ���");
}

void DrawBird(int BirdX)
{
	//        ���
	//      ����
	//    ������
	//  �������
	//���������������
	//            ����������
	//			  ���������������
	//			    �����������
	//				�������������
	//				����������
	//				�����
	//				����
	//				���
	//				���
	//				��
 //  
 //                 ��
 //                 ���
 //                 ����
	//        ���    ����
	//      ����    �����
	//    ������  ������
	//  �������  �������
	//���������������
	//            ����������
	//			  ���������������
	//			    �����������
	//				  ������������
	//				    ��������
	// �����ư��� ������
	static bool wing = true;
	if(wing)
	{
		GotoXY(BirdX, TREE_BOTTOM_Y - 19);
		printf("             ��");
		GotoXY(BirdX, TREE_BOTTOM_Y - 18);
		printf("             ���");
		GotoXY(BirdX, TREE_BOTTOM_Y - 17);
		printf("             ����");
		GotoXY(BirdX, TREE_BOTTOM_Y - 16);
		printf("        ���    ����");
		GotoXY(BirdX, TREE_BOTTOM_Y - 15);
		printf("      ����    �����");
		GotoXY(BirdX, TREE_BOTTOM_Y - 14 );
		printf("    ������  ������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 13);
		printf("  �������  �������"); 
		GotoXY(BirdX, TREE_BOTTOM_Y - 12);
		printf("���������������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 11);
		printf("            ����������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 10);
		printf("            ���������������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 9);
		printf("              �����������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 8);
		printf("                ������������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 7);
		printf("                  ��������");
		wing=false;
	}
	else
	{
		GotoXY(BirdX, TREE_BOTTOM_Y - 16);
		printf("        ���");
		GotoXY(BirdX, TREE_BOTTOM_Y - 15);
		printf("      ����");
		GotoXY(BirdX, TREE_BOTTOM_Y - 14);
		printf("    ������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 13);
		printf("  �������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 12);
		printf("���������������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 11);
		printf("            ����������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 10);
		printf("            ���������������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 9);
		printf("              �����������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 8);
		printf("              �������������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 7);
		printf("              ����������");
		GotoXY(BirdX, TREE_BOTTOM_Y - 6);
		printf("              �����");
		GotoXY(BirdX, TREE_BOTTOM_Y - 5);
		printf("              ����");
		GotoXY(BirdX, TREE_BOTTOM_Y - 4);
		printf("              ���");
		GotoXY(BirdX, TREE_BOTTOM_Y - 3);
		printf("              ���");
		GotoXY(BirdX, TREE_BOTTOM_Y - 2 );
		printf("              ��");
		wing=true;
	}

}
 
//(v2.0) �浹 ������ ���ӿ��� �׷���
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
 
//(v2.0) �浹������ true, �ƴϸ� false
bool isCollision(const int treeX, const int dinoY)
{
    //Ʈ���� X�� ������ ��ü�ʿ� ������,
    //������ ���̰� ������� �ʴٸ� �浹�� ó��
    GotoXY(0, 0);
    printf("treeX : %d, dinoY : %d", treeX, dinoY); //x,y���� Ȯ���ϱ� ����
    if (treeX <= 8 && treeX >= 6 && dinoY > 12)
    {
        return true;
    }
    return false;
}

bool isCollision2(const int BirdX, const int dinoHY)
{
    //0528 �ͷ��� X�� ������ ��ü�ʿ� ������,
    //0528 ������ ���̰� ������� �ʴٸ� �浹�� ó��
	GotoXY(0, 2);
    printf("BirdX : %d, dinoHY : %d", BirdX, dinoHY); //x,y���� Ȯ���ϱ� ����
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
	//while (true)        //(v2.0) ���� ����
 //   {
        //���� ���۽� �ʱ�ȭ
        bool isJumping = false;
        bool isBottom = true;
		bool isDown = false;//0528 ���� �Ǻ����� bool��
		bool isTop = true; //0528 �� ������� �Ǻ����� bool��

        const int gravity = 5;
		bool  under = true; //0528 x�Է½� ���̴°� �Ǻ��ϴ� bool��
		
		srand((unsigned int)time(NULL));

		int num = 2; //0528 ��ֹ� �ʱ⼳���� 1�̸� ������,2�̸� �ͷ� ���� Ȯ���� ���ؼ� �ͷ� �⺻���� ��
        int dinoX = DINO_BOTTOM_X;
        int dinoY = DINO_BOTTOM_Y;
        int treeX = TREE_BOTTOM_X;
		int BirdX = BIRD_BOTTOM_X; //0528 �ͷ�x�� ���� �ʱ�ȭ
		int dinoHY = DINO_BOTTOM_YH; //0528 �������ʴ� �浹�� �̰ɷ� �ͷ濡 �浹�ߴ��� ���ߴ��� Ȯ��
        
        int score = 0;
        clock_t start, curr;    //���� ���� �ʱ�ȭ
        start = clock();        //���۽ð� �ʱ�ȭ
		//under2 = clock();
 
        while (true)    //�� �ǿ� ���� ����
        {
			curr = clock();            //����ð� �޾ƿ���

            //�浹üũ Ʈ���� x���� ������ y������ �Ǵ�
            if(isCollision(treeX, dinoY)&&num==1)
                break;
			if(isCollision2(BirdX, dinoHY)&&num==2)
                break;
			/*getKeyDown��������� �Լ��� while�� �ȿ��� ����ϸ� Ű�� �����Է� ���� ���ϴ�
			������ �־ kbhit��getche�� ����Ͽ���
			*/
            if (_kbhit())
            {
                char op = _getche();
                //zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
                if (op == 'z' && isBottom)
                {
                    isJumping = true;
                    isBottom = false;
                }
				//0528 xŰ�� ���Ȱ� ���� ���°� �ƴ϶�� ����
                else if (op == 'x'&& isTop)
                {
					isDown = true;
					isTop = false;
                    under = false;
                }
            }
			//0528 ���λ������� Ȯ��
			if(under == false)
			{
				if (((curr - start) / CLOCKS_PER_SEC) >= 1)	//0528 ���̰� ���� 1�ʰ� ������ true���� �༭ �Ͼ
				{
					under = true;
				}
			}
			//0528 ��ֹ� ���� ��� 1�̸� ������ ���,2�� �ͷ� ���
			if(num == 1)
			{
				DrawTree(treeX);
			}
			else if(num == 2)
			{
				DrawBird(BirdX);
			}

            DrawDino(dinoX, dinoY,under);
 


            //�������̶�� Y�� ����, ������ �������� Y�� ����
            if (isJumping)
            {
                dinoY -= gravity;
            }
            else
            {
                dinoY += gravity;
            }
            //Y�� ����ؼ� �����ϴ°� �������� �ٴ� ����
            if (dinoY >= DINO_BOTTOM_Y)
            {
                dinoY = DINO_BOTTOM_Y;
                isBottom = true;
            }
            //������ ������ ������ ������ ���� ��Ȳ.
            if (dinoY <= 5)
            {
                isJumping = false;
            }



            //0528 *�ٿ�*�� �̶�� Y�� ����, ������ �������� Y�� ����
            if (isDown)
            {
				dinoHY = 47;
            }
            else
            {
				dinoHY = 29;
            }
            //0528 HY�� ����ؼ� �����Ǵ°� �������� õ�� ����
            if (dinoHY <= DINO_BOTTOM_YH)
            {
                dinoHY = DINO_BOTTOM_YH;
                isTop = true;
            }
            //�ٿ��� ���� ������ �ٿ��� ���� ��Ȳ.
            if (dinoHY == 47)
            {
				//0528 1�ʰ� ���������� �Ǻ��ϰ� �������� isDown�� false�� ��
				if (((curr - start) / CLOCKS_PER_SEC) >= 1)
				{
					isDown = false;
				}
			}




			//������
			if(num == 1)
			{
				//������ �������� (x����) �������ϰ�
				//������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
				if (score<21 && score>=0)
				{
					treeX -= 2;
					if (treeX <= -1)
					{
					treeX = TREE_BOTTOM_X;
					// ������ �������� rand�� ������ ��� ���⼭ ���������ͷ� �ʱ�ȭ����� �����ȳ�
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
			//�ͷ�
			if(num == 2)
			{
				//�ͷ��� �������� (x����) �������ϰ�
				//�ͷ��� ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
				if (score<21 && score>=0)
				{
					BirdX -= 2;
					if (BirdX <= -1)
					{
					BirdX = BIRD_BOTTOM_X;
					// �ͷ��� �������� rand�� ������ ��� ���⼭ ���������ͷ� �ʱ�ȭ����� �����ȳ�
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

			//������ �� �������� �׽�Ʈ
			GotoXY(30, 0);    
			printf("random : %d",num);

            if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1�ʰ� �Ѿ�����
            {
                score++;    //���ھ� UP
                start = clock();    //���۽ð� �ʱ�ȭ
            }
            Sleep(60);
            system("cls");    //clear
 
            GotoXY(22, 0);    
            printf("Score : %d", score);    //���� ���
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
		printf("1.���ӽ���");
		GotoXY(x,y+1);
		printf("2.��ŷ");
		GotoXY(x,y+2);
		printf("3.����");

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
