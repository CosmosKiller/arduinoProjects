
const int btn1 = 7; //Button to initiate program
const int sensor1 = 2; //Obstacule sensor
const int pwm1 = 10; //PWM output 1
const int pwm2 = 11; //PWM output 2
const int motor1A = 3; //Motor A input 1 (FWD)
const int motor1B = 4; //Motor A input 2 (BWD)
const int motor2A = 5; //Motor B input 1 (FWD)
const int motor2B = 6; //Motor B input 2 (BWD)

int fwdSpeed = 255; // Motor's forward speed
int bwdSpeed = 230; // Motor's backward speed
int rotSpeed = 200; // Motor's rotation speed
int sensor1State = LOW; // LOW if there is an obstacule, HIGH if there's none
int btnState = HIGH;
int btnValue = HIGH;

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
          	btnValue == LOW;
          	delay(500);
        }
      	else
        {
          	btnValue == HIGH;
          	delay(500);
        }
    }
}


void setup()
{
	  //Defining our pins
  	pinMode(btn1, INPUT_PULLUP);
  	pinMode(sensor1, INPUT);
  
    pinMode(motor1A, OUTPUT);
	  pinMode(motor1B, OUTPUT);
	  pinMode(motor2A, OUTPUT);
	  pinMode(motor2B, OUTPUT);
    pinMode(13, OUTPUT);
}

void loop()
{
  /*	btnState = digitalRead(btn1); //In order to initialize the program you must press the button
    start_stop();
  
  	while (btnValue = LOW)
  	{
  */
		sensor1State = digitalRead(sensor1); //Seraching for an obstacule
  	
  		if (sensor1State == HIGH) //No obstacule
    	{
          digitalWrite(13, LOW);
      		motorSpeed(fwdSpeed); //Setting fwd speed 
		    	motion(HIGH, HIGH, LOW, LOW); //Setting fwd motion
    	}
  		else
    	{
          digitalWrite(13, HIGH);
			    motion(LOW, LOW, LOW, LOW); //Stoping the robot
      		delay(500);
      
      		motorSpeed(bwdSpeed); //Setting bwd speed
      		motion(LOW, LOW, HIGH, HIGH); //Setting bwd motion
      		delay(500);
      
      		motion(LOW, LOW, LOW, LOW);//Stoping the robot
      		delay(500);
      
      		motorSpeed(rotSpeed); //Setting rotation speed
      		motion(HIGH, LOW, LOW, HIGH); //Rotating the robot to the right
      		delay(500);
      	
        	motion(LOW, LOW, LOW, LOW);//Stoping the robot
      		delay(500);
    	}
    
    /*
      btnState = digitalRead(btn1); //This time, in order to finalize the program you must press the button
  		start_stop();
  	}
  	*/ 
}
