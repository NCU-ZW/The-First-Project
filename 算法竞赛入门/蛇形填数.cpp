//蛇形填数
//在n*n方阵中填入1,2,...,n*n,要求填成蛇形，例如n=4时方阵为：
//10  11  12  1
//9   16  13  2
//8   15  14  3
//7   6   5   4

//n<=8
//2015/3/26  13:18
#include <stdio.h>
#include <string.h>
#define MAXN 10
int a[MAXN][MAXN];
int main()
{
	int n,x,y,tot=0;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	tot=a[x=0][y=n-1]=1;
	while(tot<n*n)
	{
		while(x+1<n&&!a[x+1][y])
		a[++x][y]=++tot;
		while(y-1>=0&&!a[x][y-1])
		a[x][--y]=++tot;
		while(x-1>=0&&!a[x-1][y])
		a[--x][y]=++tot;
		while(y+1<n&&!a[x][y+1])
		a[x][++y]=++tot;
	}
	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)
		printf("%3d",a[x][y]);
		printf("\n");
	}
	return 0;
} 
