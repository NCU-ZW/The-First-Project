//��������
//��nյ�ƣ����Ϊ1--n����һ���˰����еƴ򿪣��ڶ����˰������б��Ϊ2�ı����Ŀ��أ���Щ�Ʊ��ص������������˰������б��Ϊ3�ı�����
//���أ����йص��ĵƱ��򿪣����ŵĵƱ��ص������Դ����ƣ�һ����k���ˣ����������Щ�ƿ��ţ����룺n��k,������ŵĵƱ�ţ�k<=n<=1000
//2015/3/26 9:21
//�����⣬�����������
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
