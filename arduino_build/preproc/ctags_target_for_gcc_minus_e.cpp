# 1 "C:\\Users\\NourhanMahmoud\\Desktop\\arduino_project\\arduino_project.ino"
# 1 "C:\\Users\\NourhanMahmoud\\Desktop\\arduino_project\\arduino_project.ino"

// Define the analog pin, the TMP36's Vout pin is connected to


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
  pinMode(ENA, 0x1);
  pinMode(IN1, 0x1);
  pinMode(IN2, 0x1);

  pinMode(lumb, 0x1);

  pinMode(PIR, 0x0);


  // Turn off motors - Initial state
  digitalWrite(IN1, 0x0);
  digitalWrite(IN2, 0x0);


}


void loop() {

   State = digitalRead(PIR);

   speedControl(temp());

   if (State == 0x1)
     digitalWrite(lumb, 0x1);

   else if(State == 0x0)
     digitalWrite(lumb, 0x0);

    delay(10);




 speedControl(temp());

}


// This function for controling speed of the motor based on
void speedControl(int tem) {


//maximum speed
  if(tem>40)
  {
    digitalWrite(IN1, 0x1);
    digitalWrite(IN2, 0x0);
    analogWrite(ENA,255);
  }

  ///50%
  else if(tem==20)
  {
    digitalWrite(IN1, 0x1);
    digitalWrite(IN2, 0x0);
    analogWrite(ENA,128);

    pinMode(A2,0x0);//pin tem
  }

  //zero
  else if(tem<20)
  {
      digitalWrite(IN1, 0x0);
      digitalWrite(IN2, 0x0);
  }

  else
  {
    double val = temp();
    val = map(val,21 , 40, 128, 254);

    digitalWrite(IN1, 0x1);
    digitalWrite(IN2, 0x0);
    analogWrite(ENA,val);

  }

}


int temp(void)
{

  // Get the voltage reading from the TMP36
  int reading = analogRead(A2);

  // Convert that reading into voltage
  // Replace 5.0 with 3.3, if you are using a 3.3V Arduino
  float voltage = reading * (5.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;

  // Print the temperature in Celsius

  return temperatureC;

}
