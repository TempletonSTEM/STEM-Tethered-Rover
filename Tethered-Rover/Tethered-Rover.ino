#include <AFMotor.h>


/* Motor designation throughout script:
2 Letter naming scheme:
First Letter: 
f = 1 of the two forward motors
b = 1 of the two rear motors
Second Letter:
r = motor is on right side of rover
l = motor is on the left side of rover
Change these pins depending on how your motor shield
is configured with M1 port on the shield corresponding 
to the the pin number being 1. 
*/
int frmotorpin = 1;
int flmotorpin = 2;
int blmotorpin = 3;
int brmotorpin = 4;


AF_DCMotor frmotor(frmotorpin, MOTOR12_64KHZ);
AF_DCMotor flmotor(flmotorpin, MOTOR12_64KHZ);
AF_DCMotor blmotor(blmotorpin);
AF_DCMotor brmotor(brmotorpin);

void setup()
{
    // set up serial at 9600 baud
    Serial.begin(9600);
    
    //This sets all the motors to instantly accelerate 
    // to full when they are told to go. 
    frmotor.setSpeed(255);    
    flmotor.setSpeed(255);
    blmotor.setSpeed(255);
    brmotor.setSpeed(255); 
}


void GoForward() {
    frmotor.run(FORWARD);    
    flmotor.run(FORWARD);
    blmotor.run(FORWARD);
    brmotor.run(FORWARD);    

}

void TurnLeft() {    
    frmotor.run(FORWARD);    
    flmotor.run(BACKWARD);
    blmotor.run(BACKWARD);
    brmotor.run(FORWARD);    

}

void TurnRight() {
    frmotor.run(BACKWARD);    
    flmotor.run(FORWARD);
    blmotor.run(FORWARD);
    brmotor.run(BACKWARD);  

}

void GoBackwards() {
    frmotor.run(BACKWARD);    
    flmotor.run(BACKWARD);
    blmotor.run(BACKWARD);
    brmotor.run(BACKWARD);    

}

void Stop() {
    frmotor.run(RELEASE);    
    flmotor.run(RELEASE);
    blmotor.run(RELEASE);
    brmotor.run(RELEASE); 
}

void loop()
{
    if (Serial.available() > 0)
    {
        // read a single character over serial
        int inByte = Serial.read();

        // do something different for each character
        switch (inByte)
        {
            // check what character we got from the computer
            // set the correct motors to go depending on the signal that was received.
            case 'w':
                GoForward();
                break;
            case 'a':
                TurnLeft();
                break;
            case 's':
                GoBackwards();
                break;
            case 'd':
                TurnRight();
                break;
            case 'f':
                Stop();
                break;
        }
    }
}