
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
