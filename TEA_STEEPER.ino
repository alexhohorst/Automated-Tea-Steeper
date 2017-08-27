#include <Servo.h>

Servo myservo;

int pos = 160;

int button1 = 2;
int button2 = 3;
int button3 = 5;

void setup() {
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);
  pinMode (button3, INPUT);
  Serial.begin(9600);

  myservo.attach(6);
  myservo.write(pos);
  
  delay(2000);
 
}

void loop() {
  if(digitalRead(button1) == HIGH){
    for (pos = 70; pos >= 30; pos -= 1) { // goes from 70 degress to 30 degrees
      myservo.write(pos);                  // tells servo to go to position in variable 'pos'
      delay(50);                          // waits 50ms for the servo to reach the position  
    }
    delay(180000);                        // this is how long the servo will stay down. For this button, I chose 3 minutes
    
    for (pos = 30; pos <= 70; pos += 1) { // goes from 30 degrees back to 70.
      myservo.write(pos);                  // tell servo to go to position in variable 'pos'
      delay(30);                        // waits for the servo to reach the position
    }
  }
  else if(digitalRead(button2) == HIGH){
    for (pos = 70; pos >= 30; pos -= 1) { 
      myservo.write(pos);              
      delay(50);                       
    }
    delay(300000);                     
    
    for (pos = 30; pos <= 70; pos += 1) { 
      myservo.write(pos);            
      delay(30);                      
  }
  }
  
  else if(digitalRead(button3) == HIGH){
    for (pos = 70; pos >= 30; pos -= 1) { 
      // in steps of 1 degree
      myservo.write(pos);              
      delay(50);                       
    }
    delay(420000);
    
    for (pos = 30; pos <= 70; pos += 1) { 
      myservo.write(pos);              
      delay(30);                       
    }
  }
  delay(100);
}
