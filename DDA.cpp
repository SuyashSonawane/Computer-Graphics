#include<graphics.h>

#include<iostream>

using namespace std;


void DDA()
{
	int gd = DETECT ,gm;
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
		delay(10);
	}

	delay(5000);

	closegraph();
}

void BLD()
{
	int gd = DETECT ,gm;

	float x1,y1,x2,y2;
	cout<<"Enter (x1,y1) ";
	cin>>x1>>y1;
	cout<<"Enter (x2,y2) ";
	cin>>x2>>y2;

	int dx=abs(x1-x2);
	int dy =abs(y1-y2);

	int l;
	l= dx>=dy ? dx:dy;

	int x,y;
	x=x1;
	y=y1;
	initgraph(&gd,&gm,NULL);
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





	delay(2000);
	closegraph();
}

int main(int argc, char const *argv[])
{
	// int gd = DETECT ,gm;
	BLD();
	// DDA();
	
}