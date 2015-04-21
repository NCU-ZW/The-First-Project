/*����������n(<=16)��������1��2��3��....��n���һ������ʹ��������������֮��
Ϊ���������ʱ������1��ʼ���ֵ�����ʱ�����С�ͬһ����ǡ�����һ�Ρ�
��������6
�������1 4 3 2 5 6
        1 6 5 2 3 4*/ 

#include<stdio.h>
#include<string.h>
#include<math.h>
int vis[100];
int p[100];

void out(int n,int *A)
{
for(int i=0;i<n;i++)
{
printf("%d ",A[i]);
}
printf("\n");
}

int is_prime(int x)
{
if(x<2) return 0;
int m=(int)floor(sqrt(x)+0.5);
for(int i=2;i<=m;i++)
{
if(x%i==0) return 0;
}
return 1;
}

void run(int cur,int n,int *A)
{
if(cur == n)
{	
if(p[1+A[n-1]])
out(n,A);
return;
}

for(int i=2;i<=n;i++)
if(vis[i]==0 && p[A[cur-1]+i])
{
A[cur]=i;
vis[i]++;
run(cur+1,n,A);
vis[i]--;
}
}

int main()
{
int A[100],n;
memset(vis,0,sizeof(vis));
memset(p,0,sizeof(p));
scanf("%d",&n);
int k= n*2-1;
for(int i=3;i<=k;i++)
{
p[i]=is_prime(i);
}
vis[1]=1;
A[0]=1;
run(1,n,A);
return 0;
}
