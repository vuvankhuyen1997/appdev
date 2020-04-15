#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"

int main(void){
	Position cur = getscreensize();	//get screen size
	char postdata[100];
	sprintf(postdata, "row=%d&col=%d&id=e1900295",cur.row, cur.col);

	sendpost(URL, postdata);
	gotoXY(1,1);
	printf("Screen size: row=%d, col=%d\n", cur.row, cur.col);
	printf("Press any key to continue\n");
	getchar();	//wait for the user to press a key
	getchar();
	int ff, bb;
	float step=(float)cur.col/cur.row;
	for(int i=1; i<=cur.row; i++)
    	{
		ff = (i+1)%8+BLACK;
		bb = (i+2)%8+BLACK;	
		setcolors(ff, bg(bb));
		clearscreen();
		drawrect(10, 10, 5, 30);
		gotoXY(cur.row-i,(i-1)*step+1);
		printf("HELLO\n");
		//sleep(1);
		usleep(500000);
    	}
/*
//	printf("The following message will be BLUE"
	setfgcolor(BLUE);
	gotoXY(14,35);
	printf("e1900295\n");
	getchar();	//wait for the user to press a key
	drawbar(30,30);
	drawbar(50,30);

*/

	getchar();	//after drawing bars,wait for a key
	resetcolors();
	clearscreen();
	printf("this text is displayed in default color \n");
}

