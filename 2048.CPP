#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
void main();

int gd=DETECT,gm;
char a[21][60]; int b[30][20];
int r1[5]={0,10,16,22,28},r2[5]={0,6,10,14,18},i,j,p,q,r,s;

void put()
{k:
p=rand()%4+1;
 q=rand()%4+1;
 r=rand()%4+1;
 s=rand()%4+1;
 b[r1[p]][r2[q]]=2;
 b[r1[r]][r2[s]]=2;
 if(p==r&&q==s)goto k;
 }


void put1()
 {k:
p=rand()%4+1;
 q=rand()%4+1;
 if( b[r1[p]][r2[q]]==0)
 b[r1[p]][r2[q]]=2;
 else goto k;
 }

void gen()
{
for(i=0;i<151;i+=50)
for(j=0;j<201;j+=60)
{setcolor(7);
rectangle(50+i,60+j,100+i,120+j);
setfillstyle(1,7);
floodfill(75+i,90+j,7);
setcolor(8);
rectangle(50+i,60+j,100+i,120+j);
}

for(i=10;i<29;i=i+6)for(j=6;j<19;j=j+4){gotoxy(i,j);
if(b[i][j]==0)printf(" ");else printf("%d",b[i][j]);}
gotoxy(50,3);printf("TO QUIT THE GAME PRESS Esc"); }

void sortup()
{for(i=10;i<29;i=i+6)
{
for(j=6;j<19;j=j+4)
{
if(b[i][j]!=0)
{for(q=6;q<15;q=q+4){if(b[i][q]==0&&q<j){b[i][q]=b[i][j];b[i][j]=0;}}
}
}
}
}


void sortdown()
{for(i=10;i<29;i=i+6)
{
for(j=18;j>5;j=j-4)
{
if(b[i][j]!=0)
{for(q=18;q>9;q=q-4){if(b[i][q]==0&&q>j){b[i][q]=b[i][j];b[i][j]=0;}}
}
}
}
}

void sortleft()
{for(j=6;j<19;j=j+4)
{
for(i=10;i<29;i=i+6)
{
if(b[i][j]!=0)
{for(q=10;q<23;q=q+6){if(b[q][j]==0&&q<i){b[q][j]=b[i][j];b[i][j]=0;}}
}
}
}
}

void sortright()
{for(j=6;j<19;j=j+4)
{
for(i=28;i>9;i=i-6)
{
if(b[i][j]!=0)
{for(q=28;q>15;q=q-6){if(b[q][j]==0&&q>i){b[q][j]=b[i][j];b[i][j]=0;}}
}
}
}
}

void up()
{for(i=10;i<29;i=i+6)
{
for(j=6;j<19;j=j+4)
{
if(b[i][j]==b[i][j+4]){b[i][j]*=2;b[i][j+4]=0;}
}
}
}

void left()
{ for(j=6;j<19;j=j+4)
{
for(i=10;i<29;i=i+6)
{
if(b[i][j]==b[i+6][j]){b[i][j]*=2;b[i+6][j]=0;}
}
}
}

void down()
{ for(i=10;i<29;i=i+6)
{
for(j=18;j>5;j=j-4)
{
if(b[i][j]==b[i][j-4]){b[i][j]*=2;b[i][j-4]=0;}
}
}
}

void right()
{ for(j=6;j<19;j=j+4)
{
for(i=28;i>9;i=i-6)
{
if(b[i][j]==b[i-6][j]){b[i][j]*=2;b[i-6][j]=0;}
}
}
}


int getkey()
{int ch;
ch=getch();
if(ch==0)
{ch=getch();
return ch;}
return ch;
}

void result()
{
for(i=10;i<29;i=i+6)
{for(j=6;j<19;j=j+4)
if(b[i][j]==0)break;}
if(i==28&&b[28][18]!=0)
{for(p=10;p<29;p=p+6)
for(q=6;q<19;q=q+4)
{if(b[p][q]==2048){printf("YOU WON THE GAME");delay(5000);exit(0);}}
gotoxy(19,12); printf("GAME OVER");delay(5000);exit(0);}}

int navigate(int d)
{
switch(d)
{
case 72: sortup();up();sortup();result(); put1(); break;
case 80: sortdown();down();sortdown();result(); put1(); break;
case 77: sortright();right();sortright();result(); put1(); break;
case 75: sortleft();left();sortleft();result(); put1(); break;
case 27: exit(0);
} return 0;
}



void main()
{int d;
randomize();
//textbackground(YELLOW);
//textcolor(BLACK);
//clrscr();
initgraph(&gd, &gm, "C:\\TC\\bgi");
setbkcolor(8);
put();
v:
clrscr();
gen();
d=getkey();
navigate(d);
goto v;
}