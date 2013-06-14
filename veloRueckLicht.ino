/*     ---------------------------------------------------------
 ----------------------------------------------------------------
 ----------------------------------------------------------------
 Code fuer Velo Ruecklicht
 
 - Modus 1 = Lauflicht
 - Modus 2 = 5 LED High

ATtiny 85
5 LEDs an 5 Pins mit 220Ohm Widerstand (5V)
Schiebeschalter mit Pulldown Widerstand an Pin 5
----------------------------------------------------------------
----------------------------------------------------------------
Original Code von:
|  Arduino Experimentation Kit Example Code             |
|  CIRC-02 .: 8 LED Fun :. (Multiple LEDs)   |

Code geändert von S.Witschi Juni 2013  
 */
 
//Variables
int ledPins[] = {0,1,2,3,4};    //An array to hold the pin each LED is connected to
int blinkMode;                  // Set Variable for Blink Mode 

void setup()
{
  
  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 4; i++){         //this is a loop and will repeat five times
      pinMode(ledPins[i],OUTPUT); //we use this to set each LED pin except pin5 to output
  }                                   
pinMode(ledPins[4],INPUT); //set pin5 to output
 
 // check position of switch and set blimk mode
 if ((digitalRead(ledPins[4])) == LOW){
 blinkMode = 1;
 } 
 else {
 blinkMode = 2;
 }
 pinMode(ledPins[4],OUTPUT); //set pin5 to input
}
 
 
void loop()                     // run over and over again
{
if (blinkMode == 1){
  oneAfterAnotherLoop();   //does the same as oneAfterAnotherNoLoop but with 
}                             //much less typing
if (blinkMode == 2){
   for(int i = 0; i < 4; i++){         //this is a loop and will repeat eight times
      digitalWrite(ledPins[i],HIGH); //we use this to set each LED pin to output
  }                                   //the code this replaces is below
}
}
 
// Functions 
/*
 * oneAfterAnotherLoop() - Will light one LED then delay for delayTime then light
 * the next LED until all LEDs are on it will then turn them off one after another
 */
void oneAfterAnotherLoop(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower
 
//Turn Each LED on one after another
  for(int i = 0; i <= 4; i++){
    digitalWrite(ledPins[i], HIGH);  //Turns on LED #i each time this runs i
    delay(delayTime);                //gets one added to it so this will repeat 
  }                                  //5 times the first time i will = 0 the final
                                     //time i will equal 4;
  for(int i = 0; i <= 4; i++){
    digitalWrite(ledPins[i], LOW);  //Turns on LED #i each time this runs i
    delay(delayTime);                //gets one added to it so this will repeat 
  }                                  //5 times the first time i will = 0 the final

//Turn Each LED off one after another
  for(int i = 4; i >= 0; i--){  //same as above but rather than starting at 0 and counting up
                                //we start at seven and count down
    digitalWrite(ledPins[i], HIGH);  //Turns off LED #i each time this runs i
    delay(delayTime);                //gets one subtracted from it so this will repeat 
  }                                  //5 times the first time i will = 4 the final
                                    //time it will equal 0
  for(int i = 4; i >= 0; i--){  //same as above but rather than starting at 0 and counting up
                                //we start at seven and count down
    digitalWrite(ledPins[i], LOW);  //Turns off LED #i each time this runs i
    delay(delayTime);                //gets one subtracted from it so this will repeat 
  }                                  //5 times the first time i will = 4 the final
                                     

}
 
