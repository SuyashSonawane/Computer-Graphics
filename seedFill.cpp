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
    void seedFill(int x,int y,int old,int _new)
    {
    	delay(0.000001);
    	if(getpixel(x,y)==old)
    	{
    		putpixel(x,y,_new);
    		seedFill(x+1,y,old,_new);
    		seedFill(x,y+1,old,_new);
    		seedFill(x-1,y,old,_new);
    		seedFill(x,y-1,old,_new);
    		seedFill(x+1,y+1,old,_new);
    		seedFill(x-1,y+1,old,_new);
    		seedFill(x+1,y-1,old,_new);
    		seedFill(x-1,y-1,old,_new);

    	}
    }
    void boundaryFill(int x,int y,int old,int _new)
    {
    	delay(0.000001);
    	if(getpixel(x,y)==old && getpixel(x,y)!=_new)
    	{
    		putpixel(x,y,_new);
    		boundaryFill(x+1,y,old,_new);
    		boundaryFill(x,y+1,old,_new);
    		boundaryFill(x-1,y,old,_new);
    		boundaryFill(x,y-1,old,_new);
    		boundaryFill(x+1,y+1,old,_new);
    		boundaryFill(x-1,y+1,old,_new);
    		boundaryFill(x+1,y-1,old,_new);
    		boundaryFill(x-1,y-1,old,_new);

    	}
    }
    void fill(int ui)
    {
    	int x_fill=250,y_fill=250;
    	ui == 2 ? 
    		boundaryFill(x_fill,y_fill,BLACK,RED)
    	:	
    		seedFill(x_fill,y_fill,BLACK,RED);
    	delay(100);
    }


};
 



int main(int argc, char const *argv[])
{
    int gd ,gm,m;
    gd = DETECT;   
	Shape s;
    s.accept();
    cout<<"FLOOD[1] or Boundry[2] >>";
    cin>>m;
    initgraph(&gd,&gm,NULL);
    s.draw();
    s.fill(m);
	closegraph();
	return 0;
}


