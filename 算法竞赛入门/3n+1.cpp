/*���룺�����������1����Ȼ��n����nΪ��������n��Ϊ3n+1�������Ϊn��һ�룬�������ɴα任��nһ��Ϊ0����任�Ĵ���*/
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
