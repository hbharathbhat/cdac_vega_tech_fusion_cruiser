//Bluetooth control car using Arduino
char t;
 
void setup() {
pinMode(13,OUTPUT);   //left motors  forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right  motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(9,OUTPUT);   //Led
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == '2'){            //move  forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == '3'){      //move reverse (all  motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
  
else if(t == '4'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
}
 
else  if(t == '5'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  digitalWrite(13,HIGH);
  digitalWrite(10,HIGH);
}

else if(t ==  'W'){    //turn led on or off)
  digitalWrite(9,HIGH);
}
else if(t == 'w'){
  digitalWrite(9,LOW);
}
 
else if(t == '0'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(100);
}
