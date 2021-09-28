
// Define the analog pin, the TMP36's Vout pin is connected to
#define sensorPin A2

// Motor A connections
int ENA = 9;
int IN1 = 2;
int IN2 = 3;

//lumb
int lumb = 13;

//PIR
int PIR = 5;

int State = 0;


void setup() {
  
  // Set the motor control pins to outputs 
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(lumb, OUTPUT);
  
  pinMode(PIR, INPUT);
  
  
  // Turn off motors - Initial state
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  
}


void loop() {
  
   State = digitalRead(PIR);
  
   speedControl(temp());
  
   if (State == HIGH) 
     digitalWrite(lumb, HIGH);
   
   else if(State == LOW)
     digitalWrite(lumb, LOW);
     
    delay(10);
   
  
  
  
 speedControl(temp());
  
}


// This function for controling speed of the motor based on
void speedControl(int tem) {
  
  
//maximum speed
  if(tem>40)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA,255);
  }
  
  ///50%
  else if(tem==20)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA,128);
    
    pinMode(A2,INPUT);//pin tem
  }
  
  //zero
  else if(tem<20)
  {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
  }
  
  else 
  {
    double val = temp();
    val = map(val,21 , 40, 128, 254);
    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA,val);
     
  }
  
}


int temp(void)
{
  
  // Get the voltage reading from the TMP36
  int reading = analogRead(sensorPin);

  // Convert that reading into voltage
  // Replace 5.0 with 3.3, if you are using a 3.3V Arduino
  float voltage = reading * (5.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;

  // Print the temperature in Celsius
  
  return temperatureC;  
  
}
