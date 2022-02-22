//�ｺ�� ȸ�� ���� ���α׷� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int num;
	char name[20];
	double weight;
}Fitness;

int input_member(Fitness **pary);
double average_weight(Fitness **pary, int cnt);
int max_weight(Fitness **pary, int cnt);
void printf_info(Fitness **pary, int index);
void free_ary(Fitness **pary, int cnt);

int main(void)
{
	Fitness *pary[100];
	double avg;
	int max_index;
	int cnt;
	
	cnt = input_member(pary);
	avg = average_weight(pary, cnt);
	max_index = max_weight(pary, cnt);
	
	printf("# �� ȸ�� �� :%d\n",cnt);
	printf("# ��� ü�� : %.1lf\n",avg);
	printf("#ü���� ���� ���ſ� ȸ����?\n");
	printf_info(pary, max_index);
	
	free_ary(pary, cnt);
	return 0;
}

int input_member(Fitness **pary)
{
	Fitness *tp;
	char name[20];
	double weight;
	int id;
	int i;
	
	for(i = 0;i < 5; i++)
	{
		printf("> ȸ�� ��ȣ :");
		scanf("%d",&id);
		if (id<0) break;
		
		printf("> �̸� �Է� : ");
		scanf("%s" , name);
		printf("> ü�� �Է� : ");
		scanf("%lf",&weight);
		
		tp = (Fitness *)malloc(sizeof(Fitness));
		tp->num = id;
		strcpy(tp->name, name);
		tp->weight = weight;
		pary[i] = tp; 
	}
	return i;
}

double average_weight(Fitness **pary, int cnt)
{
	double tot_weight = 0;
	int i;
	
	for(i = 0;i < cnt; i++)
	{
		tot_weight += pary[i] ->weight;
	}
	
	return (tot_weight / cnt);
}

int max_weight(Fitness **pary, int cnt)
{
	double max = 0;
	int id_save = 0;
	int i;
	
	for(i = 0;i<cnt;i++)
	{
		if(pary[i]->weight > max)
		{
			max = pary[i]->weight;
			id_save = i;
		}
	}
	
	return id_save;
}
void printf_info(Fitness **pary, int index)
{
	printf("> ȸ�� ��ȣ : %d\n", pary[index]->num);
	printf("> �̸� : %s\n", pary[index]->name);
	printf("> ü�� : %1lf\n", pary[index]->weight);
}
void free_ary(Fitness **pary, int cnt)
{
	int i;
	
	for(i=0;i<cnt;i++)
	{
		free(pary[i]);
	}
}
