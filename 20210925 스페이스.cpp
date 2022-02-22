//레지스터 변수  
#include <stdio.h>

int main()
{
	register int i, space; //레지스터 변수 선언
	int line;
	
	for(line=0;line<70;line++)
	{
	for(space=1;space<=line;space++)
		printf(" ");
	
	for(i=1;i<=10;i++)
		printf("%d",i);
	printf("\n");
		
	}
	return 0;
}
