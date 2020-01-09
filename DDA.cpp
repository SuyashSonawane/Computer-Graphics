#include<graphics.h>

#include<iostream>

using namespace std;


void DDA(int gd,int gm)
{
	int x1,y1,x2,y2;
	cout<<"Enter (x1,y1) ";
	cin>>x1>>y1;
	cout<<"Enter (x2,y2) ";
	cin>>x2>>y2;

	int dx=abs(x1-x2);
	int dy =abs(y1-y2);

	int l;
	l= dx>=dy ? dx:dy;

	dx=dx/l;
	dy=dy/l;

	float x,y;

	if(x2>=x1)
		x=x1+0.5;	
	else
		x=x1-0.5;
	if(y2>=y1)
		y=y1+0.5;
	else
		y=y1-0.5;

	initgraph(&gd,&gm,NULL);
	putpixel((int)x,(int)y,WHITE);

	while(l--)
	{
		x+=dx;
		y+=dy;
		putpixel((int)x,(int)y,WHITE);
	}

	delay(5000);

	closegraph();
}

void BLD(float x1, float y1, float x2, float y2)
{
	float m_new = 2 * (y2 - y1); 
	float slope_error_new = m_new - (x2 - x1); 
	
	int gd = DETECT, gm; 
	
    initgraph (&gd, &gm, NULL); 
    
	for (float x = x1, y = y1; x <= x2; x++) 
	{ 
		putpixel(floor(x), floor(y), WHITE);

		slope_error_new += m_new; 

		if (slope_error_new >= 0) 
		{ 
		 y++; 
		 slope_error_new  -= 2 * (x2 - x1); 
		} 
		delay(100);
	}
	
	delay(2000);
	closegraph();
}

int main(int argc, char const *argv[])
{
	// int gd = DETECT ,gm;
	BLD(10,100,300,300);
	// DDA(gd,gm);
	
}