// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 

Servo esc;  // create servo object to control a servo 

int potpin = A2;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 


int arm = 1000; // defines pulse width of 1000 us
int speedvalue;
int steady = 300;
int initiate = 0;

boolean kprinted=false;

void setup() 
{ 
  // This command sends a pulse train
  // from pin 9 that continues until
  // the pin is called to do something else.
  Serial.begin(9600); 
//  for(int i=0;i<5;i++){
//     Serial.println(10-i);
//     delay(1000);
//  }
  esc.attach(9,1000,2000);
  esc.write(1);
  Serial.println("esc");
} 

//void xloop() 
//{ 
//  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
//  // print the results to the serial monitor:
//  //  Serial.print("sensor = " );                       
//  //  Serial.print(val);      
//
//  int sval = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
//  //  Serial.print("\t output = ");      
//  // Serial.println(sval);    
//
//  myservo.write(sval);                  // sets the servo position according to the scaled value 
//  delay(15);                           // waits for the servo to get there 
//} 


void loop()
{

  /*
Calls a sub to throttle up motor from 0 rpm to a steady running value.
   The if statement is used to run the throttle up once.
   */
  if (initiate < 1){
    throttleUp();
    initiate = 1;
  }

  /*
    run dodoo
   */

  if (initiate < 2){
    if(!kprinted){
      kprinted=true;
      Serial.println("knobmode");
    }
    int aval=analogRead(potpin);     
    int sval = map(aval, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
    if(sval>10){
      esc.write(sval-10);
      delay(100);
    }else{
      esc.write(1);
    }
  }


}


//**************************************************


void throttleUp(){
  Serial.println("throttleup");

  for (int count = 1; count < 10; count++){
    esc.write(count);
    delay(150);
  }
 Serial.println("end throttleup");
}

