#include<graphics.h>

#include<iostream>

// सुयश cha code
using namespace std;

struct point
{
    float x,y;
};
class Shape{
    string name;
    int vertices;
    point coords[100];

public:
    void accept()
    {
        cout<<"Enter number of vertices ";
        cin>>vertices;
        for(int i=0;i<vertices;i++)
        {
            cout<<"Enter points for vertex"<<i+1<<" ";
            cin>>coords[i].x>>coords[i].y;
        }
    }
    void draw()
    {
        
        for(int i=0;i<vertices;i++)
        {
            if(i==vertices-1)
                line(coords[0].x,coords[0].y,coords[i].x,coords[i].y);
            else
                line(coords[i].x,coords[i].y,coords[i+1].x,coords[i+1].y);
        }
        delay(1000);
        
    }
    void operator +(int x)
    {
        int y=0;
        draw();
        delay(150);
        cleardevice();
        for(int i=0;i<vertices;i++)
        {
            if(i==vertices-1)
                line(coords[0].x+x,coords[0].y+y,coords[i].x+x,coords[i].y+y);
            else
                line(coords[i].x+x,coords[i].y+y,coords[i+1].x+x,coords[i+1].y+y);
        }
        delay(1000);
    }
    void operator *(int x)
    {
        draw();
        delay(150);
        cleardevice();
        for(int i=0;i<vertices;i++)
        {
            if(i==vertices-1)
                line(coords[0].x*x,coords[0].y*x,coords[i].x*x,coords[i].y*x);
            else
                line(coords[i].x*x,coords[i].y*x,coords[i+1].x*x,coords[i+1].y*x);
        }
        delay(1000);
    }


};


class transforms
{
	int gd ,gm;
    float x1,y1,x2,y2;
public:
	transforms()
	{
        gd = DETECT;
		initgraph(&gd,&gm,NULL);
	}
	void translate()
	{
        x1=10;
        x2=40;
        y1=50;
        y2=60;
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
        x1=40;
        x2=30;
        y1=40;
        y2=45;
        int deg=0.50;
        line(x1,y1,x2,y2);
        x1=x1*cos(deg)-y1*sin(deg)+100;
        y1=x1*sin(deg)-y1*cos(deg)+100;

        x2=x2*cos(deg)-y2*sin(deg)+100;
        y2=x2*sin(deg)-y2*cos(deg)+100;
      line(x1,y1,x2,y2);
      delay(3000);


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
    int gd ,gm;
    gd = DETECT;   
	Shape s;
    s.accept();
    initgraph(&gd,&gm,NULL);
    s*50;
	
	closegraph();
	return 0;
}


