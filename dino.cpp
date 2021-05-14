//[C/C++ game] very simple google dinosaur. (by. BlockDMask)
//2019.12.03 (v2.0)���� �߰�, �浹ó�� �߰�.
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define DINO_BOTTOM_Y 29
#define DINO_BOTTOM_X 0
#define TREE_BOTTOM_Y 35
#define TREE_BOTTOM_X 97
 
//�ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView()
{
    system("mode con:cols=210 lines=50");
    system("Dinosaurs.");
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
void DrawDino(int dinoX,int dinoY)
{
    GotoXY(dinoX, dinoY);
    static bool legFlag = true;
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
    system("pause");
}
 
//(v2.0) �浹������ true, �ƴϸ� false
bool isCollision(const int treeX, const int dinoY)
{
    //Ʈ���� X�� ������ ��ü�ʿ� ������,
    //������ ���̰� ������� �ʴٸ� �浹�� ó��
    GotoXY(0, 0);
    printf("treeX : %d, dinoY : %d", treeX, dinoY); //�̷������� ������ X, Y�� ã���ϴ�.
    if (treeX <= 8 && treeX >= 5 && dinoY > 12)
    {
        return true;
    }
    return false;
}
 
int main()
{
    SetConsoleView();
 
    while (true)        //(v2.0) ���� ����
    {
        //���� ���۽� �ʱ�ȭ
        bool isJumping = false;
        bool isBottom = true;
        const int gravity = 4;

        int dinoX = DINO_BOTTOM_X;
        int dinoY = DINO_BOTTOM_Y;
        int treeX = TREE_BOTTOM_X;
        
        int score = 0;
        clock_t start, curr;    //���� ���� �ʱ�ȭ
        start = clock();        //���۽ð� �ʱ�ȭ
 
        while (true)    //�� �ǿ� ���� ����
        {
            //(v2.0) �浹üũ Ʈ���� x���� ������ y������ �Ǵ�
            if(isCollision(treeX, dinoY))
                break;
 
            //spaceŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
            if (GetKeyDown() == VK_SPACE && isBottom)
            {
                isJumping = true;
                isBottom = false;
            }
 
            //�������̶�� Y�� ����, ������ �������� Y�� ����.
            if (isJumping)
            {
                dinoY -= gravity;
            }
            else
            {
                dinoY += gravity;
            }
 
            //Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
            if (dinoY >= DINO_BOTTOM_Y)
            {
                dinoY = DINO_BOTTOM_Y;
                isBottom = true;
            }
 
            //������ �������� (x����) �������ϰ�
            //������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
            if (score<21 && score>=0)
			{
				treeX -= 2;
				if (treeX <= -1)
				{
                treeX = TREE_BOTTOM_X;
				}
			}

            if (score<40 && score>=21)
			{
				treeX -= 3;
				if (treeX <= -1)
				{
                treeX = TREE_BOTTOM_X;
				}
			}


 
            //������ ������ ������ ������ ���� ��Ȳ.
            if (dinoY <= 5)
            {
                isJumping = false;
            }
			
            DrawDino(dinoX,dinoY);        //draw dino
            DrawTree(treeX);        //draw Tree
 
            //(v2.0)
            curr = clock();            //����ð� �޾ƿ���
            if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1�ʰ� �Ѿ�����
            {
                score++;    //���ھ� UP
                start = clock();    //���۽ð� �ʱ�ȭ
            }
            Sleep(60);
            system("cls");    //clear
 
            //(v2.0) ��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ���ݴϴ�.
            GotoXY(22, 0);    //Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
            printf("Score : %d ", score);    //���� �������.
        }
 
        //(v2.0) ���� ���� �޴�
        DrawGameOver(score);
    }
    return 0;
}