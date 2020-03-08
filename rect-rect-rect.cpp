#include<graphics.h>

#include<iostream>

// सुयश cha code
using namespace std;

class RECT
{
	int gd,gm;
public:
	RECT()
	{
		
	}
	void draw()
	{

        int x1=100,y1=100,x2=200,y2=200;
           cout<<"Enter x1,y1\n";
        cin>>x1>>y1;
        cout<<"Enter x2,y2\n";
        cin>>x2>>y2;
        initgraph(&gd,&gm,NULL);
		drawLine(x1,y1,x2,y1);
        drawLine(x1,y2,x2,y2);
        drawLine(x1,y1,x1,y2);
        drawLine(x2,y1,x2,y2);

        // second rect;
        int l=(x1+x2)/2;
        int b =(y1+y2)/2;

        line(l,y1,x2,b);
        line(x1,b,l,y2);
        line(x2,b,l,y2);
        line(l,y1,x1,b);

        // third rect


        line((l+x1)/2,(y1+b)/2,(x1+l)/2,(b+y2)/2);
        line((l+x2)/2,(y1+b)/2,(x2+l)/2,(b+y2)/2);
        line((x1+l)/2,(b+y2)/2,(x2+l)/2,(b+y2)/2);
        line((l+x1)/2,(y1+b)/2,(l+x2)/2,(y1+b)/2);
        

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
	RECT t;
	t.draw();
		
	
	closegraph();
	return 0;
}


