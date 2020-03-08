#include<graphics.h>

#include<iostream>

// सुयश cha code
using namespace std;

void drawLine(float x1, float y1,float x2,float y2)
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

      delay(10);
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
      delay(10);
    }
  }
}




class Circle{
  int x,y,xc,yc,r;
public:
  Circle(){
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

  int x1,y1,l;
  cout<<"Enter X1: ";
  cin>>x1;
  cout<<"Enter Y1: ";
  cin>>y1;
  cout<<"Enter length of the side: ";
  cin>>l;




  int gd = DETECT ,gm;
  initgraph(&gd,&gm,NULL);

  drawLine(x1,y1,x1+l,y1);
  drawLine(x1+l,y1,(y1+1)/2,sqrt(pow(l,2)-))
  // drawLine(100,100,40,40);
  Circle c;
  c.draw();

    
  
  closegraph();
  return 0;
}


