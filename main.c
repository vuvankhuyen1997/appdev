#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"
#include "sound.h"

int main(void){
	FILE *fp;
	fp = fopen("test.wav", "r");	// open the wav file in read-only
	WAVheader h = readwavhdr(fp);
	displaywavhdr(h);
	clearscreen();
	wavdata(h, fp);
	fclose(fp);
	getchar();
}

