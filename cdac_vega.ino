/*
  @file MOTOR_DRIVER.ino
  @brief Interface L298N and L293D Motor Driver Module with Aries
  @detail To control the speed and spinning direction of a Small gear motor using the L298N & L293D Motor Driver
  
   Reference code: https://www.instructables.com/How-to-use-the-L293D-Motor-Driver-Arduino-Tutorial/ , 
                   https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/
                   https://www.teachmemicro.com/use-l298n-motor-driver/ 
   
   *** L298N Motor Driver ***
   Connections:
   L298N         Aries Board
   12V & 5V  -   5V
   GND       -   GND
   ENB       -   PWM 1
   IN3       -   GPIO 13
   IN4       -   GPIO 15

    Note: L298N motor driver includes a 78M05 On-board 5V Regulator and Jumper that can be enabled or disabled via a jumper.
    If we are giving only 12V supply this regulator will internally produce 5V that is required for the driver module. 
    But here we are giving an external 5V power supply from our board, so remove the cap of 5V Regulator Enable Jumper while connecting.
    
    *** L293D Motor Driver ***
   Connections:
   L293D        Aries Board
   12V & 5V  -   5V
   GND       -   GND
   EN2       -   PWM 1
   C2-A      -   GPIO 13
   C2-B      -   GPIO 15  
*/

//    The direction specifications
//  ENA   IN1   IN2     Description  
//  HIGH  HIGH  HIGH     stop
//  HIGH  HIGH  LOW      clockwise
//  HIGH  LOW   HIGH     anti clockwise
//  HIGH  LOW   LOW      stopped

#include<pwm.h>
#include<esp8266.h>
//#include<UARTClass.h>
ESP8266Class Bluetooth(1);
//UARTClass mySerial(1); 

char receiveBuffer[4096] = {0, };
int count;

//Motor Connections
//Change this if you wish to use another diagram
#define EnA 1       //Connect Enable pin to PWM 1
#define In1 13      //Connect input pin to GPIO-13
#define In2 15      //Connect input pin to GPIO-15
#define EnB 2       //Connect Enable pin to PWM 2
#define In3 14      //Connect input pin to GPIO-14
#define In4 16      //Connect input pin to GPIO-16
char in=0;


void setup()
{
  pinMode(EnA, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  PWM.PWMC_Set_Period(EnA, 800000);
  PWM.PWMC_Set_Period(EnB, 800000);
  Serial.begin(115200);  // UART-0
  Bluetooth.begin(9600); // UART-1
  delay(1000);
}

void forward() 
{
  analogWrite(EnA, 800000);
  digitalWrite(In1,HIGH);
  digitalWrite(In2,LOW);
  analogWrite(EnB, 800000);
  digitalWrite(In4,HIGH);
  digitalWrite(In3,LOW);   
}

void left()
{
  analogWrite(EnA, 800000);
  digitalWrite(In1,LOW);
  digitalWrite(In2,HIGH);
  analogWrite(EnB, 800000);
  digitalWrite(In4,HIGH);
  digitalWrite(In3,LOW); 
}

void right()
{
  analogWrite(EnA, 800000);
  digitalWrite(In1, HIGH);
  digitalWrite(In2,LOW);
  analogWrite(EnB, 800000);
  digitalWrite(In4,LOW);
  digitalWrite(In3,HIGH); 
}

void reverse()
{
  analogWrite(EnA, 800000);
  digitalWrite(In1,LOW);
  digitalWrite(In2,HIGH);
  analogWrite(EnB, 800000);
  digitalWrite(In4,LOW);
  digitalWrite(In3,HIGH); 
}

void brake() 
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);  
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}


void loop()
{  
  count = 0;
  for(;count<=0;count++){
    receiveBuffer[count] = 0;
  }
  Serial.print("Ready");
  while(1){
    count = 0;
    while(Bluetooth.available() > 0){
      receiveBuffer[count++] = Bluetooth.read();
    }
    if(receiveBuffer[count-1] == '\n'){
      receiveBuffer[count-1] = '\0';
      break;
    }
  }

  Serial.println(receiveBuffer);

  if(strcmp(receiveBuffer, "1")==0)
  {
    forward();
    delay(100);
  }
  else if(strcmp(receiveBuffer, "2")==0)
  {
    left();
  }
  else if(strcmp(receiveBuffer, "4")==0)
  {
    right();
  }
  else if(strcmp(receiveBuffer, "3")==0)
  {
    reverse();
  }
  else if(strcmp(receiveBuffer, "0")==0)
  {
    brake();
  }
  else
  {
    brake(); 
  }

}
