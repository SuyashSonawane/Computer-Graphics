#include<graphics.h>

#include<iostream>

// सुयश cha code
using namespace std;

class trnsforms
{
	int gd,gm;
    float x1,y1,x2,y2;
public:
	trnsforms()
	{
		initgraph(&gd,&gm,NULL);
	}
	void translate()
	{
        
        float limit=300;
		float dx=1,dy=0;
		while(x2<limit)
        {
            cleardevice();
            x1+=dx;
            x2+=dx;
            y1+=dy;
            y2+=dy;
            
            line(x1,y1,x2,y2);
            delay(30);
        }

		delay(5000);
	}
    void rotate()
    {
        int deg=1;
        x1=x1*cos(deg)-y1*sin(deg);
        y1=x1*sin(deg)-y1*cos(deg);

        x2=x2*cos(deg)-y2*sin(deg);
        y2=x2*sin(deg)-y2*cos(deg);

        line(x1,y1,x2,y2);


    }
	void scale(int sx,int sy)
    {
        x1+=x1*sx;
        y1+=y1*sy;
        x2+=x2*sx;
        y2+=y2*sy;

        line(x1,y1,x2,y2);
    }
};

 



int main(int argc, char const *argv[])
{
	trnsforms t;
	t.scale(1.5,1.5);
		
	
	closegraph();
	return 0;
}


