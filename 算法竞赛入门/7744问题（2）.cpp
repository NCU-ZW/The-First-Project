//7744����
//ö��ƽ����x���Ӷ��ܿ���ƽ������
//2015/3/26 8:15
//bug��¼���޷����� 
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
