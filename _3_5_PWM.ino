// Search for the Tail-race Taniwha
// Final Year Project
//
// Transmit board code
// Written by Mark Tolra
// October 2018


#define PWM_IN 10        // the main 150kHz signal
#define PWM_SD  29      // the "pulse" signal to shut down the chip
const int ledPin = 13;

void LED_blink()
{
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(500);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(500);                   // wait for a second
}

void setup() 
{
  pinMode(ledPin, OUTPUT);     // set up onboard LED to make sure it's working

  // arguments: pin, frequency in Hertz
  analogWriteFrequency(PWM_IN, 120000); // 120kHz
//  analogWriteFrequency(PWM_SD, 5);    // To set the enable pin frequency to set
                                        // the secondary pulse
}

void loop() 
{
  LED_blink();                  // Visual indicator that the board is on
  
  // arguments (pin, value) Value: the duty cycle: between 0 (always off) and 255 (always on)
  analogWrite(PWM_IN, 127);     // 0 = 0% duty, 127 = 50% duty, 255 = 100% duty
  analogWrite(PWM_SD, 127);     // 0 = 0% duty, 127 = 50% duty, 255 = 100% duty
}
