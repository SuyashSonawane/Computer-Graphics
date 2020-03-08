#include<graphics.h>
#include <math.h>  
#include<iostream>
#define PI 3.14159265
// सुयश cha code
using namespace std;

int main(int argc, char const *argv[])
{
	int gd,gm;
	initgraph(&gd,&gm,NULL);

	int xc=300 , yc=300 ,r=100;
	float deg=10;

	while(1)
	{
		if(getpixel(xc+(int)r*sin(deg+1.05),yc+(int)r*cos(deg+1.05))==15)
			cleardevice();		

		fillellipse(xc+(int)r*sin(deg),yc+(int)r*cos(deg),15,15);
		delay(1);
		deg+=0.005;
	}

		
	
	closegraph();
	return 0;
}


