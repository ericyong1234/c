//�� ���� ���߱� ���� 
#include<conio.h>		//Catch, Putch�� 
#include<windows.h>		//system,Sleep,SetConsoleCursorPosition
#include <stdio.h>		//printf,scanf�� 
#include<time.h>		//time �� 
#include<stdlib.h>	//rand,srand �� 

#define STAR "*"	//Ư�� ��ȣ ���ڿ�"*"�� ��ũ�� ��� 
#define INTERVAL 300//�� ��¦���� �ֱ�(ms) 
#define MIN 5		//�ּ� �� ��¦�� Ƚ�� 
#define MAX 12		//�ִ� �� ��¦�� Ƚ�� 

void gotoxy(int x, int y);//Ŀ���� (x,y)��ǥ�� �̵� 
void draw_rectangle(int, int, int, int);//���� ��Ÿ�� ������ �׵θ� �׸��� 

int main()
{
	int input; //������ �ϴ� ����ڰ� �Է��� �� ��¦�� Ƚ�� 
	int repeats;//���� ���� ��¦�� Ƚ�� 
	int start_x = 10;//�簢�� ���� ���� ��� x ��ǥ 
	int start_y = 3;//�簢�� ���� ���� ��� y ��ǥ 
	int width = 50;//���� ��Ÿ�� �簢�� ������ ���� �� 
	int height = 10;//���� ��Ÿ�� �簢�� ������ ���� ��ǥ 
	int x, y, i;//���� ���� ��Ÿ�� ��ǥ 
	
	printf("���� ��¦�̴� Ƚ���� ���ߴ� �����Դϴ�. �ƹ�Ű�� ������ �����մϴ�.");
	getch();
	
	system("cls");
	Sleep(1000);
	
	srand(time(NULL));
	
	repeats = rand() % (MAX - MIN + 1) + MIN;
	
	draw_rectangle(start_x, start_y, width, height);
	Sleep(1000);
	
	for(i=1;i<=repeats;i++)
	{
		x = start_x + rand()%(width - 2);
		y = start_y + rand()%(height - 1);
		
		gotoxy(x, y);
		printf("%s",STAR);
		Sleep(INTERVAL);
		
		gotoxy(x, y);
		printf("%s"," ");
		Sleep(INTERVAL);
	}
	gotoxy(10,21);
	printf("���� �� ��(%d ~ %d��)��¦�ŷ������?",MIN,MAX);
	scanf("%d",&input);
	
	gotoxy(10,22);
	if (input == repeats) printf("�¾ҽ��ϴ�.\n");
	else printf("Ʋ�Ƚ��ϴ�. ���� %d�Դϴ�.\n",repeats);
	return 0;
}
void draw_rectangle(int start_x, int start_y, int width, int height)
{
	int col, row;
	
	gotoxy(start_x - 1, start_y - 1);
	for(col=0;col<=width+1;col++)
		putch('=');
		
	gotoxy(start_x - 1, start_y + height);
	for(col=0;col<=width+1;col++)
		putch('=');
		
	for(row=0;row<height;row++)
	{
		gotoxy(start_x - 1, start_y + row);
		putch('|');
	}
	
	for(row=0;row<height;row++)
	{
		gotoxy(start_x + width, start_y + row);
		putch('|');
	}
}
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}
