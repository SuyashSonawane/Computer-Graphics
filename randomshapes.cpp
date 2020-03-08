#include<graphics.h>

#include<iostream>

// सुयश cha code
using namespace std;


class Circle{
	int x,y,xc,yc,r;
public:
	void draw()
	{
		xc=300;
		yc=300;
		r=141;
		int d;
		x=0;
		y=r;
		d=3-2*r;

		do
		{
			putpixel(x+xc,y+yc,WHITE);
			putpixel(x+xc,-y+yc,WHITE);
			putpixel(-x+xc,y+yc,WHITE);
			putpixel(-x+xc,-y+yc,WHITE);

			putpixel(y+yc,x+xc,WHITE);
			putpixel(y+yc,-x+xc,WHITE);
			putpixel(-y+yc,x+xc,WHITE);
			putpixel(-y+yc,-x+xc,WHITE);

			x++;
			if(d<0)
				d=d+4*x+6;
			else
			{
				y--;
				d=(d+ 4*(x-y)+10);
			}
			delay(10);

		}while(x<=y);
		delay(5000);
	}
};

class Triangle
{
	
public:
	
	void draw()
	{
		drawLine(200,400,400,400);
		drawLine(200,200,200,400);
		drawLine(200,200,400,400);
		// circle(300,300,141);

		
	}
	void drawLine(int x1, int y1,int x2,int y2)
	{
		int dx=abs(x1-x2);
		int dy =abs(y1-y2);

		int l;
		l= dx>=dy ? dx:dy;

		int x,y;
		x=x1;
		y=y1;
		putpixel((int)x,(int)y,WHITE);
		float pk = (2*dy)-dx;

		if(dy>dx)
		{
			while(l--)
			{
				if(pk<=0)
				{
					x+=1;
					y+=1;
				}
				else{
					y+=1;
				}

				putpixel((int)x,(int)y,WHITE);
				pk+=(2*dy)-(2*dx);

				delay(2);
			}
		}
		else
		{
			while(l--)
			{
				if(pk>=0)
				{
					x+=1;
					y+=1;
				}
				else{
					x+=1;
				}

				putpixel((int)x,(int)y,WHITE);
				pk+=(2*dy);
				delay(2);
			}
		}
	}
};

 



int main(int argc, char const *argv[])
{
	int gd,gm;
	initgraph(&gd,&gm,NULL);
	Triangle t;
	t.draw();
	Circle c;
	c.draw();	
	
	closegraph();
	return 0;
}


