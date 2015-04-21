//输入一些整数，求出他们的最小值、最大值和平均值（保留三位小数）
//2015/3/26 8:56
#include <stdio.h>
#define INF 1000000000
int main()
{
	FILE *fin,*fout;
	fin=fopen("data,in","rb");
	fout=fopen("data.out","wb");
	int x,n=0,min=INF,max=-INF,s=0;
	while(fscanf(fin,"%d",&x)==1)
	{
		s+=x;
		if(x<min)
		min=x;
		if(x>max)
		max=x;
		n++; 
	}
	fprintf(fout,"%d %d %.3lf\n",min,max,(double)s/n);
	fclose(fin);
	fclose(fout);
	return 0;
} 
