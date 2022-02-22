//별 개수 맞추기 게임 
#include<conio.h>		//Catch, Putch용 
#include<windows.h>		//system,Sleep,SetConsoleCursorPosition
#include <stdio.h>		//printf,scanf용 
#include<time.h>		//time 용 
#include<stdlib.h>	//rand,srand 용 

#define STAR "*"	//특수 기호 문자열"*"의 매크로 상수 
#define INTERVAL 300//별 반짝임의 주기(ms) 
#define MIN 5		//최소 별 반짝임 횟수 
#define MAX 12		//최대 별 반짝임 횟수 

void gotoxy(int x, int y);//커서를 (x,y)좌표로 이동 
void draw_rectangle(int, int, int, int);//별이 나타날 영역의 테두리 그리기 

int main()
{
	int input; //게임을 하는 사용자가 입력한 별 반짝임 횟수 
	int repeats;//실제 별의 반짝임 횟수 
	int start_x = 10;//사각형 영역 왼쪽 상단 x 좌표 
	int start_y = 3;//사각형 영역 왼쪽 상단 y 좌표 
	int width = 50;//별이 나타날 사각형 영역의 가로 폭 
	int height = 10;//별이 나타날 사각형 영역의 세로 좌표 
	int x, y, i;//현재 별이 나타날 좌표 
	
	printf("별이 반짝이는 횟수를 맞추는 게임입니다. 아무키나 누르면 시작합니다.");
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
	printf("별은 몇 번(%d ~ %d번)반짝거렸을까요?",MIN,MAX);
	scanf("%d",&input);
	
	gotoxy(10,22);
	if (input == repeats) printf("맞았습니다.\n");
	else printf("틀렸습니다. 답은 %d입니다.\n",repeats);
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
