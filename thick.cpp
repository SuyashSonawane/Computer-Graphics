#include<iostream>
#include<graphics.h>
#include<cmath>

// सुयश cha code
using namespace std;

void drawLine(float x1,float y1,float x2,float y2)
{
    float xinc,yinc,x,y;
    float dx,dy,e;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(x1<x2)
        xinc=1;
    else
        xinc=-1;
    if(y1<y2)
        yinc=1;
    else
        yinc=-1;
    x=x1;
    y=y1;
     putpixel(x,y,WHITE);
    if(dx>=dy)
    {
       e=(2*dy)-dx;
       while(x!=x2)
       {
           if(e<0)
           {
               e+=(2*dy);
           }
           else
           {
               e+=(2*(dy-dx));
               y+=yinc;
           }
           x+=xinc;
           putpixel(x,y,WHITE);
        }
    }
    else
    {
        e=(2*dx)-dy;
        while(y!=y2)
        {
            if(e<0)
            {
                e+=(2*dx);
            }
            else
            {
                e+=(2*(dx-dy));
                x+=xinc;
            }
            y+=yinc;
            putpixel(x,y,WHITE);
            delay(10);
        }
    }
}


void thickLine(float x1 ,float y1 , float x2 , float y2,float w)
{
	

	float wx,wy;
	wx = ((w-1)/2)*(sqrt(pow(x2-x1,2)+pow(y2-y1,2))/abs(x2-x1));
	wy = ((w-1)/2)*(sqrt(pow(x2-x1,2)+pow(y2-y1,2))/abs(y2-y1));
	

	float m =(y2-y1)/(x2-x1);

	if(m>1)
	{
		for(int i = 0;i<wx;i++)
		{
			drawLine(x1+i,y1,x2+i,y2);
			drawLine(x1-i,y1,x2-i,y2);
		}
	}
	else
	{
		for(int i = 0;i<wy;i++)
		{
			drawLine(x1,y1+i,x2,y2+i);
			drawLine(x1,y1-i,x2,y2-i);
		}
	}

	delay(5000);
	closegraph();

}

int main()
{
	float x1,y1,x2,y2;
	int w;
	
	printf("Enter values for x1,y1,x2,y2\n");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	printf("\nEnter thickness of line: ");
    scanf("%d",&w);
    int gd = DETECT ,gm;
	initgraph(&gd,&gm,NULL);
	thickLine(x1,y1,x2,y2,w);
}