// The LEDs are connected to these pins
int ForwardRightMotorPin = 5;
int BackRightMotorPin = 4;
int BackLeftMotorPin = 3;
int ForwardLeftMotorPin = 2;

char* Commands[] = {"Forward", "Back", "L_Turn", "R_Turn"};


void setup()
{
    // set up serial at 9600 baud
    Serial.begin(9600);

    // set all four LED pins to output mode
    pinMode(ForwardRightMotorPin, OUTPUT);
    pinMode(BackRightMotorPin, OUTPUT);
    pinMode(BackLeftMotorPin, OUTPUT);
    pinMode(ForwardLeftMotorPin, OUTPUT);
}

void GoForward() {
    digitalWrite(ForwardRightMotorPin, HIGH);
    digitalWrite(BackRightMotorPin, HIGH);
    digitalWrite(BackLeftMotorPin, HIGH);
    digitalWrite(ForwardLeftMotorPin, HIGH);
}

void TurnLeft() {
    digitalWrite(ForwardRightMotorPin, HIGH);
    digitalWrite(BackRightMotorPin, HIGH);
    digitalWrite(BackLeftMotorPin, LOW);
    digitalWrite(ForwardLeftMotorPin, LOW);
}

void TurnRight() {
    digitalWrite(ForwardRightMotorPin, LOW);
    digitalWrite(BackRightMotorPin, LOW);
    digitalWrite(BackLeftMotorPin, HIGH);
    digitalWrite(ForwardLeftMotorPin, HIGH);
}

void GoBackwards() {
    digitalWrite(ForwardRightMotorPin, LOW);
    digitalWrite(BackRightMotorPin, LOW);
    digitalWrite(BackLeftMotorPin, LOW);
    digitalWrite(ForwardLeftMotorPin, LOW);
}

void toggleLED(int LEDPin)
{
    // toggle the LED on the pin passed as an argument
    digitalWrite(LEDPin, !digitalRead(LEDPin));
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
            // if we receive r, y, g, or w
            // toggle the respective LED using our function
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
            default:
                // if we receive any other character turn all
                // the LEDs off
              
                break;
        }
    }
}