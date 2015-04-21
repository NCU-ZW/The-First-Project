//开灯问题
//有n盏灯，编号为1--n。第一个人把所有灯打开，第二个人按下所有编号为2的倍数的开关（这些灯被关掉），第三个人按下所有编号为3的倍数的
//开关（其中关掉的灯被打开，开着的灯被关掉），以此类推，一共有k个人，问最后有哪些灯开着，输入：n和k,输出开着的灯编号，k<=n<=1000
//2015/3/26 9:21
//有问题，出现输出错误
#include <stdio.h>
#include <string.h>
#define MAXN 1000+10
int a[MAXN];
int main()
{
	int i,j,n,k,first=1;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&k);
	for(i=1;i<k;i++)
	for(j=1;j<=n;j++)
	if(j%i==0)
	a[j]=!a[j];
	for(i=1;i<=n;i++)
	if(a[i])
	{
		if(first)
		first=0;
		else
		printf(" ");
		printf("%d",i);
	}
	printf("\n");
	return 0;
} 
