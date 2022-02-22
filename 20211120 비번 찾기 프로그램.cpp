#include<stdio.h>

void find_PW();
void find_ID();

int main()
{
	int service;
	
	do
	{
		printf("\n<<< 1. ID찾기 2. PW찾기 3. 종료하기 >>> \n");
		printf(" 원하는 서비스 번호를 입력하세요(1~3)");
		scanf("%d",&service);
		
		switch (service)
		{
			case 1:find_ID(); break;
			case 2:find_PW();
		} 
	} while (service != 3);
	
	return 0;
}
void find_ID()
{
	static int count_ID = 0;
	
	count_ID++;
	printf("\n 총 %d회째 아이디 찾기 요청입니다.\n", count_ID);
}
void find_PW()
{
	int count_PW = 0;
	
	count_PW++;
	printf("\n 총 %d회째 비밀번호 찾기 요청입니다.\n", count_PW);
}
