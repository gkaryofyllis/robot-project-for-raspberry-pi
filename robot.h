#include "pins.h"
#include <time.h>
#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
void setup() {
        wiringPiSetup();
	// Set the ultrasonic
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);

	//Set the motors
	pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
	pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
	pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
	pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
 
        //TRIG pin must start LOW
        digitalWrite(TRIG, LOW);
        delay(30);
}

 
int getCM() {
        //Send trig pulse
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG, LOW);
 
        //Wait for echo start
        while(digitalRead(ECHO) == LOW);
 
        //Wait for echo end
        long startTime = micros();
        while(digitalRead(ECHO) == HIGH);
        long travelTime = micros() - startTime;
 
        //Get distance in cm
        int distance = travelTime / 58;
 
        return distance;
}
 void stop(){
	 // Stop all the motors
	 digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
	 digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
	 digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
	 digitalWrite(LEFT_MOTOR_FORWARD, LOW);
 }
 
 void start(){
	 // Starts to move forward
	 digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
	 digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
 }
 
void turnLeft(){
	digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);delay(400);
	digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
}
void turnRight(){
	digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);delay(400);
	digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void goBack(){
	digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);
	digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);

}
void turn(){
	time_t t;
	srand((unsigned) time(&t));
	int r = rand() % 2;
	switch(r){
		case 0: turnLeft();
		break;
		case 1: turnRight();
		break;
	}
}
