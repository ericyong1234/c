//��ǰ �ֹ� ���α׷� 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void display_service(void);
void display_item(void);
void order_sheet(void);
void ordering(void);
void cleaning(void);

#define N 6

char name[N][7] = {"","��Ʈ","����","���찳","��","����"};
int unit_cost[N] = {0,1000,500,300,800,1500};
int number[N] = {0};

int main()
{
	int service;
	
	do
	{
		display_service();
		printf("���ϴ� ���񽺸� �����ϼ���");
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
	printf("���ϴ� ��ǰ�� ��ȣ��?"); scanf("%d", &item);
	printf("%s��(��) �ֹ��� ������?",name[item]); scanf("%d",&n);
	
	number[item]+=n;
	printf("\n�ֹ��Ͻ� %s %d���� �� %d���Դϴ�.\n",name[item],n,n*unit_cost[item]); 
}
void order_sheet()
{
	int i,cost,total_cost = 0;
	
	printf("\n	��ǰ �ֹ� ������  \n");
	printf("=======================\n");
	printf("  ��ǰ��   ����   ����\n");
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
	printf("�Ѿ�      %7d�� \n", total_cost);
}
void display_service()
{
	printf("\n>> ȯ���մϴ�. \n");
	printf("=======================\n");
	printf("==1. ��ǰ �ֹ��ϱ�   ==\n");
	printf("==2. �ֹ��� Ȯ���ϱ� ==\n");
	printf("==3. �����ϱ�        ==\n");
	printf("=======================\n");
}
void display_item()
{
	int i;
	
	printf("\n>> ��ǰ �ֹ� �����Դϴ�.\n");
	printf("=======================\n");
	for(i=1;i<N;i++)
		printf("%d %-7s %7d \n",i, name[i],unit_cost[i]);
	printf("=======================\n");
}

void cleaning()
{
	printf("\n��� ���񽺸� ���Ͻø� �ƹ�Ű�� ��������");
	getch();
	system("cls"); 
}
