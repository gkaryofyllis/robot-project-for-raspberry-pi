#include <wiringPi.h>
#include <stdio.h>
#include "./robot.h"

int main(void){

	setup();
	int d;
	for(;;){
		while((d = getCM()) > 30){
			start();
			printf("Current distance: %d\n", d);
		}
	stop();
	delay(500);
	goBack();
	delay(300);
	turn();
	stop();
	delay(300);
	}
}
