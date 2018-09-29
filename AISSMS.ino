#define debug

void setup() 
{
  
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
  Serial.begin(9600);
  
}

void goforward()
 {
  
  analogWrite(10,110);
  analogWrite(11,110);
  
  digitalWrite(4, HIGH);    //rightmotorfd
  digitalWrite(7, LOW);



  
  digitalWrite(8, LOW);     //leftmotorfd
  digitalWrite(9, HIGH);
  Serial.println("\n FORWARD");
}

 /*void gobackward()
{
  analogWrite(10,100);
  analogWrite(11,100);
  
  digitalWrite(4, LOW);    //rightmotorfd
  digitalWrite(7, HIGH);



  
  digitalWrite(8, HIGH);     //leftmotorfd
  digitalWrite(9, LOW);
  Serial.println("\n BACKWAED");
}
*/
void right()
{
  
  analogWrite(10,100);
  analogWrite(11,100);
  
  digitalWrite(4, LOW);    //rightmotorfd
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);     //leftmotorfd
  digitalWrite(9, HIGH);
  Serial.println("\n RIGHT");
}

void left()
{
  analogWrite(10,110);
  analogWrite(11,110);
  
  digitalWrite(4, HIGH);    //rightmotorfd
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);     //leftmotorfd
  digitalWrite(9, LOW);
  Serial.println("\n LEFT");
}


/*
 * 
 * void stop()
{
  
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  Serial.println("\n STOP");
}
*/

void softright()
{
  analogWrite(10,110);
  analogWrite(11,110);
  
  digitalWrite(4, LOW);    //rightmotorfd
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);     //leftmotorfd
  digitalWrite(9, HIGH);
  Serial.println("\n SOFTRIGHT");
}

void softleft()
{
  analogWrite(10,110);
  analogWrite(11,110);
  
  digitalWrite(4, HIGH);    //rightmotorfd
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);     //leftmotorfd
  digitalWrite(9, LOW);
  Serial.println("\n LEFT");
}


void uturn()
{
  analogWrite(10,90);
  analogWrite(11,90);

  
  digitalWrite(4, HIGH);    //rightmotorfd
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);     //leftmotorfd
  digitalWrite(9, LOW);
  
  Serial.println("\n UTURN");
}

void loop()
{
  digitalWrite(12, HIGH);
  int val1, val2, val3, val4, val5;

  val1 = analogRead(A1);
  val2 = analogRead(A2);
  val3 = analogRead(A3);
  val4 = analogRead(A4);
  val5 = analogRead(A5);

  Serial.println(val1);
  Serial.println(val2);
  Serial.println(val3);
  Serial.println(val4);
  Serial.println(val5);
  Serial.println("\n");

if (val1 > 400 && val2 < 400 && val3 < 400 && val4 < 400 && val5 > 400)       //1
  {
    goforward();
  }
  else if (val1 > 400 && val2 < 400 && val3 < 400 && val4 > 400 && val5 > 400)  //2
  {
    softleft();
   // goforward();
  }
else if (val1 > 400 && val2 > 400 && val3 < 400 && val4 < 400 && val5 > 400) //3
  {
    softright();
    
   // goforward();
  }
else if (val1 > 400 && val2 > 400 && val3 < 400 && val4 > 400 && val5 > 400) //4
  {
    goforward();
  }
else if(val1 < 400 && val2 < 400 && val3 < 400 && val4 < 400 && val5 < 400)     //5
  {
  left();
 }
else if(val1 < 400 && val2 < 400 && val3 < 400 && val4 < 400 && val5 > 400)     //7
 {
    left();
 }
else if(val1 < 400 && val2 < 400 && val3 < 400 && val4 > 400 && val5 > 400)     //8
 {
 softleft();
 }
 else if(val1 > 400 && val2 < 400 && val3 < 400 && val4 < 400 && val5 < 400)      //9
 {
 right();
 }
 else if(val1 > 400 && val2 > 400 && val3 < 400 && val4 < 400 && val5 < 400)      //10
 {
 right();
 }
 else if(val1 > 400 && val2 > 400 && val3 > 400 && val4 > 400 && val5 > 400)  
 {
   uturn(); 
  // delay(200);
 }
else if(val1 > 400 && val2 < 400 && val3 > 400 && val4 >400 && val5 > 400)
{
  softleft();  
}
else if(val1 > 400 && val2 > 400 && val3 > 400 && val4 < 400 && val5 > 400)
{
  softright(); 
}
else if(val1 < 400 && val2 < 400 && val3 > 400 && val4 > 400 && val5 > 400)
{
  softleft();
}
else if(val1 > 400 && val2 > 400 && val3 > 400 && val4 < 400 && val5 < 400)         //change 1
{
  right(); 
}

else if(val1 > 400 && val2 > 400 && val3 > 400 && val4 > 400 && val5 < 400)        //ext1
{
 right();// changed from soft
}

else if(val1 < 400 && val2 > 400 && val3 > 400 && val4 > 400 && val5 > 400)
{
  softleft();
}
  else
  {
   left();                                                        //change 2
  }
}

