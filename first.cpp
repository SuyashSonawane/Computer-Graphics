#include<graphics.h>

#include<iostream>

// सुयश cha code
using namespace std;
int HEIGHT = 500;
int WIDTH =600;
int getRandom(int lower, int upper) 
{
	int n=((rand() % 
           (upper - lower + 1)) + lower);
  
        return n;
    
}
class Circle{
	int x,y;
	int dx,dy;
	bool flagx,flagy; 
	int r;
public:
	Circle(){
		x= getRandom(10,200);
		y= getRandom(10,200);
		dx=getRandom(1,10);
		dy=getRandom(1,10);
		r=getRandom(1,40);
		flagx=false,flagy=false;
	}
	void draw()
	{
		if(x>WIDTH-30)
		{
			dx=-dx;
			flagx=true;
		}
		if(x<35 && flagx)
		{
			dx=-dx;
			flagx=false;
		}
		if(y>HEIGHT-30)
		{
			dy=-dy;
			flagy=true;
		}
		if(y<35 && flagy)
		{
			dy=-dy;
			flagy=false;
		}
		x+=dx;
		y+=dy;
		circle(x,y,r);
	}
};

 



int main(int argc, char const *argv[])
{
	int count=400;
	int gd = DETECT ,gm;
	initgraph(&gd,&gm,NULL);
	Circle c[count];
	while(1)
	{
		cleardevice();
		for(int i=0;i<count;i++)
			c[i].draw();
		
		delay(30);

	}


	

	
	getch();
	closegraph();
	return 0;
}