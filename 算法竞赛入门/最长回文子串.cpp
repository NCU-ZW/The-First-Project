/*输入一个字符串，求出其中最长的回文子串。子串的含义是：在原串中连续出现的字符串片段。回文的含义：正着看和倒着看相同
在判断时应该忽略所有标点符号和空格，且忽略大小写，但是输出应保持原样（在回文串的首部和尾部不要输出多余字符）。输入字符
串长度不超过5000，且占据单独一行。应该输出最长的回文串，如果有多个，输出起始位置最靠左的*/
//输入：Confuciuss say:Madam,I'm Adam.
//输出：Madam,I'm Adam 
//2015/3/26  21:08
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 5000+10
char buf[MAXN],s[MAXN];
int p[MAXN];
int main()
{
	int n,m=0,max=0,x,y;
	int i,j;
	fgets(buf,sizeof(s),stdin);
	n=strlen(buf);
	for(i=0;i<n;i++)
	if(isalpha(buf[i]))
	{
		p[m]=i;
		s[m++]=toupper(buf[i]);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;i-j>=0&&i+j<m;j++)
		{
			if(s[i-j]!=s[i+j])
			break;
			if(j*2+1>max)
			{
				max=j*2+1;
				x=p[i-j];
				y=p[i+j];
			}
		}
			for(j=0;i-j>=0&&i-j+1<m;j++)
			{
				if(s[i-j]!=s[i-j+1])
				break;
				if(j*2+2>max)
				{
					max=j*2+2;
					x=p[i-j];
					y=p[i+j+1];
				}
			}
	}
			for(i=x;i<=y;i++)
			printf("%c",buf[i]);
			printf("\n");
			return 0;
} 
