#include<graphics.h>

#include<iostream>

// सुयश cha code
using namespace std;

class Triangle
{
	int gd,gm;
public:
	Triangle()
	{
		initgraph(&gd,&gm,NULL);
	}
	void draw()
	{
		drawLine(200,400,400,400);
		drawLine(200,200,200,400);
		drawLine(200,200,400,400);

		delay(5000);
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
	Triangle t;
	t.draw();
		
	
	closegraph();
	return 0;
}


