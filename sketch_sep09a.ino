#include <Bounce2.h>


int incomingByte = 0; // for incoming serial data
int btn_flag = 0;
const int ledPin =  13;      // the number of the LED pin
#define BUTTON_PIN 2
// Instantiate a Bounce object
Bounce debouncer = Bounce(); 

void setup() {
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  pinMode(ledPin, OUTPUT);
  btn_flag = 1;

   // Setup the button with an internal pull-up :
  pinMode(BUTTON_PIN,INPUT_PULLUP);

  // After setting up the button, setup the Bounce instance :
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5); // interval in ms
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:







    
    incomingByte = Serial.read();

    // say what you got:
//    Serial.print("I received: ");
//    Serial.print(incomingByte, DEC);

    if(incomingByte==49)
      digitalWrite(ledPin, HIGH);
    else
      digitalWrite(ledPin, LOW);
 
  }

  debouncer.update();   // Update the Bounce instance
  if (debouncer.read()) {
    if(btn_flag==0){
      Serial.println("call");
      btn_flag = 1;
    }
  }else
    btn_flag = 0;

}
