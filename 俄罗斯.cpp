 /*-----------------俄罗斯方块C语言版 V0.13beta---------------*/ 
//V0.1 buid080807 程序大致成型 发现一些bug 
//V0.11 build080815 修复部分bug 优化代码 加入下落 加入欢迎界面 
//V0.12b builf080830 加入插砖块代码 有待测试 
//V0.13b build080906 继续优化代码 修复部分bug 插砖块还需测试 




#include <stdio.h> 
#include <windows.h> 
#include <stdlib.h> 
#include <time.h> 
#include <conio.h> 




int r,p,q=0,score=0,speed=25; 
int b[20][10]; 

int block[7][3][2]	={{-1,0,0,-1,1,-1}, 
					{-1,-1,0,-1,1,0}, 
					{-1,0,-1,1,1,0}, 
					{-1,-1,-1,0,1,0}, 
					{0,-1,1,0,1,-1}, 
					{-2,0,-1,0,1,0}, 
					{0,-1,0,1,-1,0}}; 
void Display(void); 
void Block_Random(void); 
void GotoXY(int x, int y); 
void Fill_Block(void); 
void Clean_Block(void); 
void Move_Left(void); 
void Move_Right(void); 
void Move_Down(void); 
void Fast_Down(void); 
void End(void); 
void Check_Block(void); 
void Check_Line(void); 
void Clean_Line(int); 
void Change_Block(void); 
void Swap(int *,int *); 
void Welcome(void); 
void Pause(void); 





int main(void) 
{
	system("title 俄罗斯方块 ——周东旭/王浩制作");//设置标题
	system("mode con cols=24 lines=14");//设置窗口大小
	system("color E0");//设置颜色
	int i,j,k; 
	char d; 
	p=1; 
	for(i=0;i<20;i++) 
	for(j=0;j<10;j++) 
	b[i][j]=0; 
	Block_Random(); 
	Welcome(); 
	Display(); 
	while(1) 
	{ 
		for(k=0;k<20;k++) 
		{ 
			if(kbhit()) 
			{
				d=getch(); 
				switch(d) 
				{
					case 'a':case '4':Move_Left();break; 
					case 'd':case '6':Move_Right();break; 
					case 'w':case '8':Clean_Block();Change_Block();Display();break; 
					case 's':case '5':Fast_Down();break; 
					case 'x':case '2':Move_Down();break; 
					case 'p':Pause();break; 
					case 'q':GotoXY(1,24);printf("Game Over"); 
					GotoXY(1,25);printf("Press any key to ESC..."); 
					d=getch(); 
					exit(1);break; 
				}
			} 
			
			Sleep(speed);
		} 
		Move_Down(); 
	} 
	return 0;
} 




void Display() 
{
	int i,j; 
	Fill_Block(); 
	GotoXY(1,1); 
	for(i=0;i<20;i++) 
	{
		printf("■"); 
		for(j=0;j<10;j++) 
		{
			switch(b[i][j]) 
			{
				case 0:printf("  ");break; 
				case 1:printf("□");break; 
				case 2:printf("■");break;
			}
		} 
		printf("■\n");
	} 
	for(i=0;i<12;i++) 
	printf("■"); 
	GotoXY(1,22);printf("SCORE:%d",score); 
	GotoXY(1,23);printf("LEVEL=%d",score/100); 
} 





void GotoXY(int x, int y) 
{ 
	COORD c; 
	c.X = x-1; 
	c.Y = y-1; 
	SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c); 
} 





void Block_Random() 
{ 
	int k,rr,i;
	srand((unsigned)(time(NULL))); 
	k=rand()%7;rr=rand()%4; 
	r=k; 
	for (i=0;i<=rr;i++) 
	Change_Block(); 
} 




void Fill_Block() 
{
	int i,x,y; 
	for(i=0;i<3;i++) 
	{
		x=block[r][i][0]; 
		y=block[r][i][1]; 
		if(b[x+p][5+y+q]!=2)
		b[x+p][5+y+q]=1; 
		else
		{
			p--;Clean_Block();
			Fill_Block();
			Check_Block();
			return;
		} 
		if(5+y+q>9) Move_Left(); 
		if(5+y+q<0) Move_Right(); 
	} 
	if(b[p][5+q]!=2) 
	b[p][5+q]=1; 
	else 
	{
		p--;
		Clean_Block();
		Fill_Block();
		Check_Block();
		return;
	} 
} 





void Clean_Block(void) 
{
	int i,x,y; 
	for(i=0;i<3;i++) 
	{
		x=block[r][i][0]; 
		y=block[r][i][1]; 
		b[x+p][5+y+q]=0; 
	} 
	b[p][5+q]=0; 
} 

 

void Move_Left(void) 
{
	int i,x,y;
	if(p==0)
		return; 
	for(i=0;i<20;i++) 
	if(b[i][0]==1) 
		return; 
	for(i=0;i<3;i++) 
	{
		x=block[r][i][0]; 
		y=block[r][i][1]; 
		if(b[x+p][4+y+q]==2) 
		return;
	} 
	Clean_Block(); 
	q--; 
	Fill_Block(); 
	
	if(5+y+q>9) Move_Left(); 
	if(5+y+q<0) Move_Right(); 
	
	Display(); 

} 






void Move_Right(void) 
{
	int i,x,y; 
	if(p==0) 
		return; 
	
	for(i=0;i<20;i++) 
	if(b[i][9]==1) 
		return; 
	for(i=0;i<3;i++) 
	{
		x=block[r][i][0]; 
		y=block[r][i][1]; 
		if(b[x+p][6+y+q]==2) 
		return;
	} 
	Clean_Block(); 
	q++; 
	Fill_Block(); 
	
	if(5+y+q>9) Move_Left(); 
	if(5+y+q<0) Move_Right(); 
	
	Display(); 

} 





void Move_Down(void) 
{ 
	Clean_Block(); 
	p++; 
	Display(); 
	Check_Block(); 
 } 
 
 
 
 

void End() 
{
	char c=0; 
	int i,j,x,y; 
	for(i=0;i<3;i++) 
	{
		x=block[r][i][0]; 
		y=block[r][i][1]; 
		b[x+p][5+y+q]=2; 
	} 
	b[p][5+q]=2; 
	GotoXY(1,1); 
	for(i=0;i<20;i++) 
	{
		printf("■"); 
		for(j=0;j<10;j++) 
		{
			switch(b[i][j]) 
			{
				case 0:printf(" ");break; 
				case 1:printf("□");break; 
				case 2:printf("■");break;
			}
		} 
		printf("■\n");
	} 
	for(i=0;i<12;i++) 
	printf("■"); 
	GotoXY(1,22);printf("SCORE:%d",score); 
	GotoXY(1,23);printf("LEVEL=%d",score/100); 
	//Display(); 
	GotoXY(1,24);printf("Game Over"); 
	GotoXY(1,25);printf("Press Q to ESC..."); 
	do 
	{c=getch();} 
	while(c!='q'); 
	exit(1); 
} 





void Check_Block() 
{
	int i,x,y,k; 
	char d; 
	Display(); 
	for(i=0;i<10;i++) 
	if(b[0][i]==1&&b[1][i]==2) End(); 
	
	for(i=0;i<3;i++) 
	{
		x=block[r][i][0]; 
		y=block[r][i][1]; 
		if(b[x+p+1][5+y+q]==2||b[p+1][5+q]==2||x+p==19) 
		{ 
		
			/*-----------------v0.12b-----------------------*/ 
			for(k=0;k<10;k++) 
			{ 
				if(kbhit()) 
				{
					d=getch(); 
					switch(d) 
					{
						case 'a':case '4':Move_Left();break; 
						case 'd':case '6':Move_Right();break; 
						//case 'w':case '8':Clean_Block();Change_Block();Display();break; 
						case 'p':Pause();break; 
						case 'q':
							{
								GotoXY(1,24);printf("Game Over"); 
								GotoXY(1,25);printf("Press any key to ESC..."); 
								d=getch(); 
								exit(1);
							};
							break; 
					}
				} 
				Sleep(5);
			} 
			/*-----------------v0.12b-----------------------*/ 
			
			for(i=0;i<3;i++) 
			{
				x=block[r][i][0]; 
				y=block[r][i][1]; 
				b[x+p][5+y+q]=2; 
			} 
			b[p][5+q]=2;
			Check_Line();
			Block_Random();
			p=0;
			q=0;
			Fill_Block();
			Check_Block();
			Display();
		} 
	} 
} 





void Check_Line() 
{
	int i,j,s=0,t=0; 
	for(i=0;i<20;i++) 
	{
		s=0; 
		for(j=0;j<10;j++) 
		s+=b[i][j]; 
		if (s==20) {s=0;Clean_Line(i);t++;} 
	} 
	switch (t) 
	{
		case 1:score++;break; 
		case 2:score+=3;break; 
		case 3:score+=5;break; 
		case 4:score+=8;break; 
	} 
	switch(score/100) 
	{
		case 0:speed=25;break; 
		case 1:speed=20;break; 
		case 2:speed=17;break; 
		case 3:speed=15;break; 
		case 4:speed=12;break; 
		case 5:speed=10;break; 
		case 6:speed=7;break; 
		case 7:speed=5;break; 
		case 8:speed=2;break; 
		case 9:{speed=0;break;} 
	} 
} 





void Clean_Line(int l) 
{
	int i,j; 
	for(i=l-1;i>=0;i--) 
		for(j=0;j<10;j++) 
			b[i+1][j]=b[i][j]; 
	for(i=0;i<10;i++) 
		b[0][j]=0; 
} 




void Change_Block(void) 
{
	int i,yy,x,y; 
	if (r==4) return; 
	/*-----------v0.13----------*/ 
	for(i=0;i<3;i++) 
	{
		x=block[r][i][0]; 
		y=block[r][i][1]; 
		if(b[x+p][5+y+q-1]==2||b[p][5+q+1]==2) 
		return; 
	} 
	/*-----------v0.13----------*/ 
	
	
	for(i=0;i<3;i++) 
	{ 
		if(block[r][i][0]*block[r][i][1]>0)             {block[r][i][1]=(-1)*block[r][i][1];} 
		else if(block[r][i][0]*block[r][i][1]<0)        {block[r][i][0]=(-1)*block[r][i][0];}
		else if(block[r][i][0]==0)                      {Swap(&block[r][i][0],&block[r][i][1]);}
		else if(block[r][i][1]==0)                      {Swap(&block[r][i][0],&block[r][i][1]);block[r][i][1]*=-1;} 
	} 
	for(i=0;i<3;i++) 
	{ 
		yy=block[r][i][1]; 
		if(5+yy+q>9) q--; 
		if(5+yy+q<0) q++; 
		if(5+yy+q>9) q--; 
		if(5+yy+q<0) q++;
	} 

} 



void Swap(int *x,int *y) 
{ 
	int temp; 
	temp=*x; 
	*x=*y; 
	*y=temp; 
} 



void Welcome(void) 
{ 
	printf("◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥\n"); 
	printf("◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥\n"); 
	printf("◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥\n"); 
	printf("■■■■■■■■■■■◥■■■■■◥◥◥◥◥■■◥◥◥◥◥◥◥◥◥■■◥◥◥\n"); 
	printf("■■■■■■■■■■■◥■■■■■■◥◥◥◥◥■■◥◥◥◥◥◥◥■■◥◥◥◥\n"); 
	printf("◥◥◥◥◥◥◥◥■■■◥■■◥◥◥■■◥◥◥◥◥■■◥◥◥◥◥■■◥◥◥◥◥\n"); 
	printf("◥◥◥◥◥◥◥■■■◥◥■■◥◥◥◥■■◥◥◥◥◥■■◥◥◥■■◥◥◥◥◥◥\n"); 
	printf("◥◥◥◥◥◥■■■◥◥◥■■◥◥◥◥◥■■◥◥◥◥◥■■◥■■◥◥◥◥◥◥◥\n"); 
	printf("◥◥◥◥◥■■■◥◥◥◥■■◥◥◥◥◥◥■■◥◥◥◥◥■■◥◥◥◥◥◥◥◥◥\n"); 
	printf("◥◥◥◥■■■◥◥◥◥◥■■◥◥◥◥◥◥■■◥◥◥◥◥◥■■◥◥◥◥◥◥◥◥\n");  
	printf("◥◥◥■■■◥◥◥◥◥◥■■◥◥◥◥◥■■◥◥◥◥◥■■◥■■◥◥◥◥◥◥◥\n"); 
	printf("◥◥■■■◥◥◥◥◥◥◥■■◥◥◥◥◥■■◥◥◥◥■■◥◥◥■■◥◥◥◥◥◥\n"); 
	printf("◥■■■◥◥◥◥◥◥◥◥■■◥◥◥◥■■◥◥◥◥■■◥◥◥◥◥■■◥◥◥◥◥\n"); 
	printf("■■■■■■■■■■■◥■■◥◥◥■■◥◥◥◥■■◥◥◥◥◥◥◥■■◥◥◥◥\n"); 
	printf("■■■■■■■■■■■◥■■■■■■◥◥◥◥■■◥◥◥◥◥◥◥◥◥■■◥◥◥\n"); 
	printf("◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥\n"); 
	printf("◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥\n"); 
	printf("◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥\n"); 
	printf("◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥◥\n"); 
	printf("[旋转：W/8 下落：X/2 左移：A/4 右移：D/6 瞬间下落：S/5 暂停：P 退出：Q]\n"); 
	printf("*平均每提高100分 速度会加快一个级别\n"); 
	printf("*瞬间下落：S/5 为快速下落 按下后直接落到底部\n"); 
	printf("(BUG可能还会有一些 会慢慢改进)\n"); 
	printf("联系作者：zhoudongxu929@gmail.com"); 
	system("pause"); 
	system("cls"); 
} 



void Fast_Down(void) 
{ 
	while(p) 
	Move_Down(); 
	Check_Block(); 
	Move_Down(); 
} 




void Pause(void) 
{
	char c; 
	GotoXY(1,23);printf("Pause! "); 
	do 
		{c=getch();} 
	while(c!='p'); 
} 

 


