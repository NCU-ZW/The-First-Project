/*猜想：对于任意大于1的自然数n，若n为奇数，则将n变为3n+1，否则变为n的一半，经过若干次变换，n一定为0，求变换的次数*/
//2015/3/26  8:26
#include <stdio.h>
int main()
{
	int n,count=0;
	scanf("%d",&n);
	while(n>1)
	{
		if(n%2==1)
		n=n*3+1;
		else
		n/=2;
		count++;
	}
	printf("%d\n",count);
	return 0;
} 
