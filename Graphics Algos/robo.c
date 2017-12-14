#include <graphics.h>

float FX,FY,BX,BY,ax,bx,ay,by;

void DDALine(float x1,float y1,float x2,float y2)
{
  float x,y,dx,dy,step;
  if(x1>x2 || y1>y2)
  {
    x1=x1+x2;x2=x1-x2;x1=x1-x2; //  x1 x2 swap
    y1=y1+y2;y2=y1-y2;y1=y1-y2; //  y1 y2 swap
  }
  dx=abs(x2-x1); //finding the positive difference between x1 and x2
  dy=abs(y2-y1); //finding positive difference between y1 and y2
  if(dx>=dy)
    step=dx;
  else
    step=dy;
  dx/=step;
  dy/=step;
  x=x1;
  y=y1;
  for(int i=0;i<=step;i++)
  {
    putpixel(x,y,WHITE);
    x+=dx;
    y+=dy;
  }
}
void DDARect(float x1,float y1,float x2,float y2) //Creating a rectangle using dda line
{
  DDALine(x1,y1,x2,y1); 
  DDALine(x2,y1,x2,y2);
  DDALine(x2,y2,x1,y2);
  DDALine(x1,y1,x1,y2);
}
void main( )
{
  BX=320; BY=240; FX=BX; FY=BY-60; //BX and BY are some constants to make sure we place the robo somewhere in the centre of screen
  int gd=DETECT,gm;			// FX and FY are translating constants to make sure all parts of the body are drawns
  initgraph(&gd,&gm,"NULL");
  //--Head
  //Cap
  circle(FX,FY-40,5);
  DDARect(FX-2.5,FY-25,FX+2.5,FY-35);
  arc(FX,FY-20,180,360,5);
  //Face
  DDARect(FX-20,FY+20,FX+20,FY-20);//Face Outline
  DDARect(FX-15,FY,FX-5,FY-10);//Left Eye
  DDARect(FX+5,FY,FX+15,FY-10);//Right Eye
  //Mouth
  DDARect(FX-10,FY+15,FX+10,FY+10);
  //TEETH
  DDARect(FX-2,FY+15,FX+2,FY+10);
  DDARect(FX-6,FY+15,FX+6,FY+10);
  //LEFT_EAR
  DDARect(FX-25,FY,FX-20,FY-10);
  DDARect(FX-30,FY-2.5,FX-25,FY-7.5);
  //RIGHT_EAR
  DDARect(FX+25,FY,FX+20,FY-10);
  DDARect(FX+25,FY-2.5,FX+30,FY-7.5);
  DDARect(BX-5,BY-30,BX+5,BY-40);//Neck
  //--BODY
  DDARect(BX-30,BY+30,BX+30,BY-30); // Body Outline
  DDARect(BX-20,BY+15,BX+20,BY-20); // Inner Square
  DDARect(BX-25,BY+70,BX-10,BY+30); //  Left Leg
  arc(BX-17.5,BY+70,180,360,7.5);  // Left Foot
  DDARect(BX+25,BY+70,BX+10,BY+30); //  Right Leg
  arc(BX+17.5,BY+70,180,360,7.5); //  Right Foot
  //Left_Hand
  ax=BX-47,ay=BY-5; //ax and bx become relative points to draw both hands 
  bx=BX-47,by=BY+5;
  for(int i=0;i<10;i++)
  {
        putpixel(ax,ay,WHITE);
	putpixel(bx,by,WHITE);
        ax+=1.7;
	bx+=1.7;
	ay-=1;
	by-=1;
  }
  circle(BX-47,BY,5);
  //Right_Hand
  DDALine(BX+47,BY-5,BX+30,BY-15);
  DDALine(BX+47,BY+5,BX+30,BY-5);
  circle(BX+47,BY,5);
  ax=BX+47,ay=BY-5;
  bx=BX+47,by=BY+5;
  //END
  delay(5000);
  getch();
}
