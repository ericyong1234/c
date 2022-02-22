//상품 주문 프로그램 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void display_service(void);
void display_item(void);
void order_sheet(void);
void ordering(void);
void cleaning(void);

#define N 6

char name[N][7] = {"","노트","연필","지우개","자","볼펜"};
int unit_cost[N] = {0,1000,500,300,800,1500};
int number[N] = {0};

int main()
{
	int service;
	
	do
	{
		display_service();
		printf("원하는 서비스를 선택하세요");
		scanf("%d",&service);
		
		system("cls");
		switch(service)
		{
			case 1: ordering(); break;
			case 2: order_sheet(); break;
			case 3: exit(0);
		}
		cleaning();
	}while(service != 3);
	return 0;
}
void ordering()
{
	int item, n;
	
	display_item();
	printf("원하는 상품의 번호는?"); scanf("%d", &item);
	printf("%s을(를) 주문할 갯수는?",name[item]); scanf("%d",&n);
	
	number[item]+=n;
	printf("\n주문하신 %s %d개는 총 %d원입니다.\n",name[item],n,n*unit_cost[item]); 
}
void order_sheet()
{
	int i,cost,total_cost = 0;
	
	printf("\n	상품 주문 내역서  \n");
	printf("=======================\n");
	printf("  상품명   개수   가격\n");
	printf("-----------------------\n");
	
	for(i=1;i<N;i++)
	{
		if(number[i] > 0)
		{
			cost=unit_cost[i]*number[i];
			printf("  %-7s %3d %7d \n",name[i],number[i],cost);
			total_cost += cost;
		}
	}
	printf("=======================\n");
	printf("총액      %7d원 \n", total_cost);
}
void display_service()
{
	printf("\n>> 환영합니다. \n");
	printf("=======================\n");
	printf("==1. 상품 주문하기   ==\n");
	printf("==2. 주문서 확인하기 ==\n");
	printf("==3. 종료하기        ==\n");
	printf("=======================\n");
}
void display_item()
{
	int i;
	
	printf("\n>> 상품 주문 서비스입니다.\n");
	printf("=======================\n");
	for(i=1;i<N;i++)
		printf("%d %-7s %7d \n",i, name[i],unit_cost[i]);
	printf("=======================\n");
}

void cleaning()
{
	printf("\n계속 서비스를 원하시면 아무키나 누르세요");
	getch();
	system("cls"); 
}
