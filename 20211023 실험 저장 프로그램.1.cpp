//실험 데이터 저장 프로그램 
#include <stdio.h> //scanf,printf함수를 위한 헤더 파일 
#include <string.h>//strcmp함수를 위한 헤더파일 
#include <conio.h>//getch함수를 위한 헤더파일 
#include <stdlib.h>//system함수를 위한 헤더파일 
#define MAX 100

struct experiment //실험 데이터를 저장할 구조체 정의 
{
	int no;//실험 순번 
	char date[6];//실험 월/일 
	int s1, s2, s3;//물질 1, 물질2,물질3의 양 
	int tension;//장력의 세기 
};
typedef struct experiment DATA;//struct experiment를 DATA로 정의 

DATA find_max(DATA test []);//장력이 최대인 실험 데이터 찾기 
void input(DATA test[]);//실험 자료를 배열에 추가하기 
void output_element(DATA e);//실험 자료 배열의 한 원소만 출력하기 
void output_list(DATA test[]);//실험 자료 배열을 출력하기 
void print_title();//출력할 실험 데이터 내용의 제목 출력하기 
void search(DATA test[]);//실험 자료 배열에서 정보 검색하기 
void sort(DATA test[]);//실험 자료 배열 정렬 메뉴 처리 함수 
void sort_no(DATA test[]);//실험 자료 배열을 번호순으로 출력하기 
void sort_tension(DATA test[]);//실험 자료 배열을 장려순으로 정렬하기 

int size;//배열에 저장된 실험 데이터 수, 전역 변수 선언 

int main()
{
	DATA test[MAX];//구조체 배열 선언 struct experiment test{MAX};와 동일 
	int menu;
	
	do
	{ //화면에 메뉴 표시 
		printf(">>실험 데이터 관리 프로그램 <<\n\n");
		printf("1.입력 2.출력 3.조회 4.정렬 5.끝내기\n");
		printf(">>원하는 메뉴를 선택하세요 : ");scanf("%d",&menu);
		
		switch(menu) //메뉴 선택에 따라 함수 호출하기 
		{
			case 1: input(test); break; //실험 데이터 입력 함수 호출 
			case 2: output_list(test); break;//실험 데이터 출력 함수 호출 
			case 3: search(test); break;//실험 데이터 검색 함수 호출 
			case 4: sort(test); break;//실험 데이터 정렬함수 호출 
			case 5: return 0;//프로그램 실행 끝내기 
			default : printf("\n메뉴를 잘못 선택하였습니다.\n\n");
		 } 
		 printf("\n>>계속 하려면 아무키나 누르세요."); getch();
		 system("cls"); //현재 화면 지우기 
	}while(menu != 5); //5끝내기 아닌한 반복하기 
	
	return 0;
}
void input(DATA test[])
{
	test[size].no = size + 1; //데이터 입력 순번 저장하기 
	printf("\n");
	printf(" 날짜(월/일) : "); scanf("%s",test[size].date);
	printf(" 물질1의 양  : "); scanf("%d",&test[size].s1);
	printf(" 물질2의 양  : "); scanf("%d",&test[size].s2); 
	printf(" 물질3의 양  : "); scanf("%d",&test[size].s3);
	printf(" 장력 : "); scanf("%d", &test[size].tension);
	size++; //배열에 저장한 실험 데이터 수를 1증가 
}
void output_list(DATA test[])
{
	int i;
	
	print_title();
	for(i=0;i<size;i++) //출력 제목 출력하기 
		output_element(test[i]); //배열 원소 즉 구조체 출력하기 
	printf("==================================\n");
}
//한 번의 실험 데이터를 출력하는 함수 
void output_element(DATA e)
{
	printf("%3d %-5s %3d  %3d  %3d  %4d\n",e.no,e.date,e.s1,e.s2,e.s3,e.tension);
}
//출력에 자주 사용할 제목을 출력하는 함수 
void print_title()
{
	printf("\n==================================\n");
	printf(" 순번 날짜 물질1 물질2 물질3 장력");
	printf("\n----------------------------------\n");
}
//구조체 배열 TEST에서 필요한 정보를 검색하는 함수 
void search(DATA test[])
{
	int menu,i;
	char input_date[6];
	
	printf("\n [1] 최대 장력 출력  [2]날짜별 데이터 출력");
	printf(" >> 원하는 메뉴를 선택하세요 : "); scanf("%d",&menu);
	
	switch(menu) 
	{
	case 1: print_title(); 
			output_element(find_max(test));
			printf("==================================\n");
			break;
	case 2: printf("\n >> 검색할 실험 날짜 (월/일):"); 
			scanf("%s",input_date);
			print_title();
			for(i=0;i<size;i++)
				if(strcmp(test[i].date, input_date)==0)
					output_element(test[i]);
			printf("==================================\n");
			break;
	default:printf("\n메뉴를 잘못 선택하였습니다.\n\n");	 
	} 
}
//구조체 배열 TEST에서 장력이 가장 큰 실험 데이터를 찾는 함수 
DATA find_max(DATA test[])
{
	int i;
	DATA max;
	
	max = test[0];
	for(i=0;i<size;i++)
		if(max.tension < test[i].tension)
			max = test[i];
	return max;
}
//구조체 배열 TEST의 정렬 요청을 처리하는 함수 
void sort(DATA test[])
{
	int menu;
	
	printf("\n[1]장력(내림차순)  [2]데이터 입력순");
	printf("\n>>원하는 메뉴를 선택하세요 : "); scanf("%d",&menu);
	
	switch(menu) // 메뉴 선택에 따라 함수 호출하기 
	{
		case 1: sort_tension(test); output_list(test); break;//장력 순서대로 정렬 
		case 2: sort_no(test); break;//실험 데이터 입력 순으로 출력 
		default: printf("\n메뉴를 잘못 선택하였습니다.\n\n");
	}
}
//구조체 배열 TEST를 장력이 큰 순서대로 정렬하는 함수 
void sort_tension(DATA test[])
{
	int pass,i;
	DATA temp;
	
	for(pass=1;pass<size;pass++)
		for(i=0;i<size-pass;i++)
			if(test[i].tension < test[i+1].tension) //내림차순 정렬 
			{
				temp = test[i];
				test[i] = test[i+1];
				test[i+1] = temp;
			}
}
//구조체 배열 TEST의 원소를 처음 실험 데이터 입력(순번) 순으로 출력하는 함수 
void sort_no(DATA test[])
{
	int order, i;
	
	//실제로 정렬 안하고 구조체에 저장된 순번 정보를 이용해 출력 
	print_title();
	for(order=1;order<=size;order++)
		for(i=0;i<size;i++)
			if(test[i].no == order)
			{
				output_element(test[i]);
				break; //ORDER번째 데이터를 출력했으므로 뒤의 비교는 생략	 
			}
	printf("==================================\n");
}
