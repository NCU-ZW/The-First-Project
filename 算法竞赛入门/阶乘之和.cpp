//�׳�֮��
//����n������S=1!+2!+3!+....+n!��ĩ6λ������ǰ��0����n<=1000000
//2015/3/26 8:33
#include <stdio.h>
int main()
{
	int i,j,n,S=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int factorial=1;
		for(j=1;j<=i;j++)
		factorial*=j;
		S+=factorial;
	}
	printf("%d\n",S%1000000);
	return 0;
} 
