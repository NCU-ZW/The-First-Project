//7744问题（1）
//输出所有形如aabb的四位完全平方数（即前两位数字相等，后两位数字也想等）。 
//2015/3/26 8:11
#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,n;
	double m;
	for(a=1;a<=9;a++)
	for(b=0;b<=9;b++)
	{
		n=a*1100+b*11;
		m=sqrt(n);
		if(floor(m+0.5)==m)//注意！！！！ //函数floor(x)返回x的整数部分 
		printf("%d\n",n);
	}
	return 0;
}
