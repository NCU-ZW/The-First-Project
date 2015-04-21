#include <stdio.h>
int main()
{
	int ret=0,N;
	scanf("%d",&N);
	while(N)
	{
		ret+=N/5;
		N/=5;
	}
	printf("%d",ret);
	return 0;
} 
