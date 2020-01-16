
#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

void drawLine(float x1,float y1,float x2,float y2)
{
	int dist=10;
  int gap=20;
	int k=-10;
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
       { k++;
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
           if(0<=k%gap && k%gap<=dist)
           	putpixel(x,y,WHITE);
           else
            if(k%5==0)
              putpixel(x,y,WHITE);
        
        }
    }
    else
    {
        e=(2*dx)-dy;
        while(y!=y2)
        {
          k++;
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
            if(0<=k%gap && k%gap<=dist)
            putpixel(x,y,WHITE);
           else
            if(k%5==0)
              putpixel(x,y,WHITE);            
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
      delay(0.1);
			drawLine(x1-i,y1,x2-i,y2);
		}
	}
	else
	{
		for(int i = 0;i<wy;i++)
		{
			drawLine(x1,y1+i,x2,y2+i);
      delay(0.1);
			drawLine(x1,y1-i,x2,y2-i);
		}
	}

	delay(5000);
	closegraph();

}

int main()
{
	// float x1,y1,x2,y2;
	// int w;
	
	// printf("Enter values for x1,y1,x2,y2\n");
	// scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	// printf("\nEnter thickness of line: ");
 //    scanf("%d",&w);
    int gd = DETECT ,gm;
	initgraph(&gd,&gm,NULL);
	thickLine(20,20,400,400,2);
}