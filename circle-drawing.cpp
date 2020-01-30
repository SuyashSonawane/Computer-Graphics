#include<graphics.h>

#include<iostream>

// सुयश cha code
using namespace std;

class Circle{
	int x,y,xc,yc,r,gd,gm;
public:
	Circle(){
		int gd = DETECT ,gm;
		initgraph(&gd,&gm,NULL);
		// printf("Enter XC \n");
		// scanf("%d",&xc);
		// printf("Enter YC \n");
		// scanf("%d",&yc);
		// printf("Enter R \n");
		// scanf("%d",&r);
		cout<<"Enter XC \n";
		cin>>xc;
		cout<<"Enter YC \n";
		cin>>yc;
		cout<<"Enter R \n";
		cin>>r;
		// cleardevice();

	}
	void draw()
	{
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
			delay(30);

		}while(x<=y);
		delay(5000);
	}
};

 



int main(int argc, char const *argv[])
{
	Circle c;
	c.draw();
		
	
	closegraph();
	return 0;
}


