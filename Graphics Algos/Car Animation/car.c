#include <stdio.h>
#include <graphics.h>
 
int main()
{
    int gd = DETECT, gm;
    int i, maxx, midy;
 
    /* initialize graphic mode */
    initgraph(&gd, &gm, "NULL");
    /* maximum pixel in horizontal axis */
    maxx = getmaxx();
    /* mid pixel in vertical axis */
    midy = getmaxy()/2;
 
    for (i=0; i < maxx-150; i=i+5)	/* loop is run for showing the animation */
    {
        /* clears screen */
        cleardevice();
 
        /* draw a white road */
        setcolor(WHITE);	/* color of the road */
        line(0, midy + 37, maxx, midy + 37);
 
        /* Draw Car */
        setcolor(YELLOW);	/* color of the car body */

 	/* car body */
        line(i, midy + 23, i, midy);	/* draws the left most line parallel to y-axis */
        line(i, midy, 40 + i, midy - 20);
        line(40 + i, midy - 20, 80 + i, midy - 20);	/* draws the roof of the car*/
        line(80 + i, midy - 20, 100 + i, midy);		/* draws the front mirror part of the car */
        line(100 + i, midy, 120 + i, midy);
        line(120 + i, midy, 120 + i, midy + 23);
        line(0 + i, midy + 23, 18 + i, midy + 23);
        arc(30 + i, midy + 23, 0, 180, 12);		/* draws the arc to accomodate the wheels */
        line(42 + i, midy + 23, 78 + i, midy + 23);
        arc(90 + i, midy + 23, 0, 180, 12);		/* draws the arc to accomodate the wheels */
        line(102 + i, midy + 23, 120 + i, midy + 23);
	/* car body ends */

	/* Draw Windows */
	/* left window */
        line(28 + i, midy, 43 + i, midy - 15);		/* left part of left window */
        line(43 + i, midy - 15, 57 + i, midy - 15);	/* roof of the left window */
        line(57 + i, midy - 15, 57 + i, midy);		/* right part of left window */
        line(57 + i, midy, 28 + i, midy);		/* bottom part of the left window */
	/* left window ends */

	/* right window */
        line(62 + i, midy - 15, 77 + i, midy - 15);	/* left part of right window */
        line(77 + i, midy - 15, 92 + i, midy);		/* roof of the rightt window */
        line(92 + i, midy, 62 + i, midy);		/* right part of right window */
        line(62 + i, midy, 62 + i, midy - 15);		/* bottom part of the right window */
	/* right window ends */

        floodfill(5 + i, midy + 22, YELLOW);	/* fills the whole car body with yellow color */

        setcolor(BLUE);		/* color of the wheels */
        /*  Draw Wheels */
        circle(30 + i, midy + 25, 9);
        circle(90 + i, midy + 25, 9);
        floodfill(30 + i, midy + 25, BLUE);	/* fills the left wheel with blue color */
        floodfill(90 + i, midy + 25, BLUE);	/* fills the right wheel with blue color */

        /* Add delay of 0.1 milli seconds */
        delay(100);	/* to observe the animation */
    }
 
    getch();
    closegraph();
    return 0;
}
