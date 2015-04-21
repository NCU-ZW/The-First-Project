//7744问题
//枚举平方根x，从而避开开平方操作
//2015/3/26 8:15
//bug记录：无法运行 
#include <stdio.h>
int main()
{
	int x,n,hi,lo;
	for(x=1;;x++)
	{
		n=x*x;
		if(n<1000)
		continue;
		if(n>9999)
		break;
		hi=n/100;
		lo=n%100;
		if(hi/lo==hi%10&&lo/10==lo%10)
		printf("%d\n",n);
	}
	return 0;
} 
