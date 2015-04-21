//阶乘之和（2）包含计时器
//2015/3/26 8:38
#include <stdio.h>
#include <time.h>
int main()
{
	const int MOD=1000000;
	int i,j,n,S=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int factorial=1;
		for(j=1;j<=i;j++)
		factorial=(factorial*j%MOD);
		S=(S+factorial)%MOD;
	}
	printf("%d\n",S);
	printf("Time used=%.2lf\n",(double)clock()/CLOCK_PER_SEC);//竟然不能用！！！！ 
	return 0;
} 
