/*�ҳ���������abc*de����λ��������λ��������ʽ��ʹ������������ʽ�У��������ֶ�����һ���ض������ּ��ϡ��������ּ��ϣ���������֮��
û�пո񣩣����������ʽ��ÿ����ʽ֮ǰӦ�б�ţ�֮��Ӧ��һ�����С��������������*/
//2015/3/26  13:31
//������ 
#include <stdio.h>
#include <string.h>
int mian()
{
	int i,ok,abc,de,x,y,z,count=0;
	char s[20],buf[99];
	scanf("%s",s);
	for(abc=111;abc<=999;abc++)
	for(de=11;de<=99;de++)
	{
		x=abc*(de%10);
		y=abc*(de/10);
		z=abc*de;
		sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
		ok=1;
		for(i=0;i<strlen(buf);i++)
		if(strchr(s,buf[i])==NULL)
		ok=0;
		if(ok)
		{
			printf("<%d>\n",++count);
			printf("%5d\nX%4d\n------\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
		}
	}
	printf("The number of solutions = %d\n",count);
	return 0;
} 
