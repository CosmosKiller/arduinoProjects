#include <Servo.h>

Servo myServo;

const int sensor1 = 2; //Obstacule sensor
const int motor1A = 3; //Motor A input 1 (FWD)
const int motor1B = 4; //Motor A input 2 (BWD)
const int motor2A = 5; //Motor B input 1 (FWD)
const int motor2B = 6; //Motor B input 2 (BWD)
const int srv1 = 8; //Servomotor  
const int pwm1 = 10; //PWM output 1
const int pwm2 = 11; //PWM output 2
const int btn1 = 12; //Button to initiate program

int fwdSpeed = 255; // Motor's forward speed
int bwdSpeed = 230; // Motor's backward speed
int rotSpeed = 200; // Motor's rotation speed
int sensor1State = LOW; // LOW if there is an obstacule, HIGH if there's none
int btnState = HIGH;
int btnValue = HIGH;
int srvScanLeft = HIGH;
int srvScanRight = HIGH;

void motion(int m1Fwd, int m2Fwd, int m1Bwd,int m2Bwd) //Function to set the motion direction of the robot
{
	digitalWrite(motor1A, m1Fwd);
  	digitalWrite(motor2A, m2Fwd);
  	digitalWrite(motor1B, m1Bwd);
  	digitalWrite(motor2B, m2Bwd);
}

void motorSpeed(int mSpeed) //Function to set the speed of the motors
{
	analogWrite(pwm1, mSpeed);
    analogWrite(pwm2, mSpeed);
}

void start_stop() //Function to start or stop the evader
{
	if (btnState == LOW)
    {
    	if (btnValue == HIGH)
        {
            btnValue = LOW;
            delay(500);
        }
        else
        {
            btnValue = HIGH;
            delay(500);
        }
    }
}

int servoScanLeft()
{
	myServo.attach(srv1);

	myServo.write(180); //The srv rotates towards left
	if (digitalRead(sensor1) == LOW) //Obsatcle detected
	{
		srvScanLeft = LOW;
	}
	else
	{
		srvScanLeft = HIGH;
	}

	myServo.detach();

	return srvScanLeft;
}

int servoScanRight()
{
	myServo.attach(srv1);

	myServo.write(0); //The srv rotates towards right
	if (digitalRead(sensor1) == LOW) //Obsatcle detected
	{
		srvScanRight = LOW;
	}
	else
	{
		srvScanRight = HIGH;
	}	

	myServo.detach();

	return srvScanLeft;
}

void evasionProtocol()
{
	int srvScanL = servoScanLeft();
	int srvScanR = servoScanRight();
	
	if (srvScanL == LOW && srvScanR == HIGH) //An obstacle is detect in the left side but not in the right side
	{											
		motorSpeed(rotSpeed); //Setting rotation speed
		motion(HIGH, LOW, LOW, HIGH); //Setting right rotation motion
      	delay(500);					
	}
	else if(srvScanL == HIGH && srvScanR == LOW) //An obstacle is detect in the right side but not in the left side
	{
    	motorSpeed(rotSpeed); //Setting rotation speed
      	motion(LOW, HIGH, HIGH, LOW); //Setting left rotation motion
      	delay(500);		
	}
	else if (srvScanL == HIGH && srvScanR == HIGH) //No obstacles are detected in any side
	{
    	motorSpeed(rotSpeed); //Setting rotation speed
    	motion(LOW, HIGH, HIGH, LOW); //As there is no obstacle, you could choose to make the robot rotate either left o right
    	delay(500);					
	}
	else //Obstacles are detect on both sides
	{
		motorSpeed(bwdSpeed); //Setting bwd speed
      	motion(LOW, LOW, HIGH, HIGH); //Setting bwd motion
      	delay(500);
      
      	motion(LOW, LOW, LOW, LOW);//Stoping the robot
      	delay(500);
		
		evasionProtocol();
	}
}

void setup()
{
	//Defining our pins
  	pinMode(sensor1, INPUT);
    pinMode(motor1A, OUTPUT);
	pinMode(motor1B, OUTPUT);
	pinMode(motor2A, OUTPUT);
	pinMode(motor2B, OUTPUT);
	pinMode(srv1, OUTPUT);
	pinMode(btn1, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);

	//Preparing the servo
	myServo.attach(srv1);
	myServo.write(180);
	delay(1000);
	myServo.write(0);
	delay(1000);	
	myServo.write(90);
	delay(1000);
	myServo.detach();
}

void loop()
{
    btnState = digitalRead(btn1); //In order to initialize the program you must press the button
    delay(500);
    start_stop();
  
  	while (btnValue == LOW)
 	{
		sensor1State = digitalRead(sensor1); //Seraching for an obstacle
  	
  		if (sensor1State == HIGH) //No obstacle
    	{
        	digitalWrite(LED_BUILTIN, LOW);
      		motorSpeed(fwdSpeed); //Setting fwd speed 
		    motion(HIGH, HIGH, LOW, LOW); //Setting fwd motion
    	}
  		else
    	{
        	digitalWrite(LED_BUILTIN, HIGH);
			motion(LOW, LOW, LOW, LOW); //Stoping the robot
      		delay(500);

      		/* motorSpeed(bwdSpeed); //Setting bwd speed
      		motion(LOW, LOW, HIGH, HIGH); //Setting bwd motion
      		delay(500);
      
      		motion(LOW, LOW, LOW, LOW);//Stoping the robot
      		delay(500); */

			/* int srvScanL = servoScanLeft();
			int srvScanR = servoScanRight(); */
      		evasionProtocol();
      	
        	motion(LOW, LOW, LOW, LOW);//Stoping the robot
      		delay(500);
    	}
    
    	btnState = digitalRead(btn1); //This time, in order to finalize the program you must press the button
    	start_stop();
	}
}
