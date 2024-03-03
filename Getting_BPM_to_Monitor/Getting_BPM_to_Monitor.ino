#define USE_ARDUINO_INTERRUPTS true    

#include <PulseSensorPlayground.h>    

const int OUTPUT_TYPE = PROCESSING_VISUALIZER;

const int PulseWire = 0;       
const int LED = 13;          
int Threshold = 550;         
                               
PulseSensorPlayground pulseSensor;  

void setup() {   
  Serial.begin(9600);

  pulseSensor.analogInput(PulseWire);  

  pulseSensor.blinkOnPulse(LED);     

  pulseSensor.setThreshold(Threshold);  
  
  if (pulseSensor.begin()) 
  {
  }
}

void loop() {
  if (pulseSensor.sawStartOfBeat()) 
  {      

    int myBPM = pulseSensor.getBeatsPerMinute();  

    Serial.println(myBPM);                    

    digitalWrite(LED, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
    delay(50);

  }
  delay(20);    
                  
}

  
