// Variables which will change
int complexity = -1;   // Complexity counter to change the mode
int buttonState = 0;
int lastButtonState = 0;  

// Constant variables which will not change
const int redLEDPin = 11; 
const int blueLEDPin = 10;
const int greenLEDPin = 6;
const int yellowLEDPin = 5;
const int buttonPin = 12;

void setup() 
{
  // initialize the LEDs as outputs
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  
  // initialize the button pin as a input
  pinMode(buttonPin, INPUT); // pushbutton for changing state

  // initialize serial communication
  Serial.begin(9600);
}

void loop() 
{
  // read the pushbutton input pin
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      complexity++; // increment to change the if statement it will enter

      // checking the remainder operation on variable complexity is 0
      if (complexity % 3 == 0)
      {
        // Create 1, 2, 3, 4 LEDs
        digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);                       // wait for a second
        digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);                       // wait for a second
        digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level
        delay(1000);                       // wait for a second
        digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);                       // wait for a second
        digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);                       // wait for a second    

        Serial.print("STATE0");
        Serial.println();
      }
    
    // checking the remainder operation on variable complexity is 1
    else if (complexity % 3 == 1)
      {
        // Create 1, 3, 2, 4 LEDs
        digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
        delay(1000); 

        digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level
        delay(1000);                       // wait for a second
        digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);

        digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);                       // wait for a second


        digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);                       // wait for a second

        Serial.print("STATE1");
        Serial.println();
      }

      // checking the remainder operation on variable complexity is 2 as else statement
      else
      {
        // Create 4, 2, 1, 3, 2, 3, 1, 4 
        digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);     

        digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);   

        digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);     


        digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);  

        digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);   


        digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);  

        digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);

        digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);     
        
        Serial.print("STATE2");
        Serial.println();
      }
      Serial.println("on");
    } 
    else 
    {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
}
