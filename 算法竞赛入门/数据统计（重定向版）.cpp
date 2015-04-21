//输入一些整数，求出他们的最小值、最大值和平均值（保留三位小数）
//2015/3/26 8:48
#define LOCAL
#include <stdio.h>
#define INF 1000000000
int main()
{
	#ifdef LOCAL
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	#endif
	int x,n=0,min=INF,max=-INF,s=0;
	while(scanf("%d",&x)==1)
	{
		s+=x;
		if(x<min)
		min=x;
		if(x>max)
		max=x;
		/*
		printf("x=%d,min=%d,max=%d\n",x,min,max);
		*/
		n++;
	}
	printf("%d %d %.3lf\n",min,max,(double)s/n);
	return 0;
} 
