#include <IRremote.h>      
int RECV_PIN = 34;                                               
int led1=16; int led2=17; int led3=18; int led4=19; 

IRrecv irrecv(RECV_PIN);                                        
decode_results results;                                         

void setup()
{
  Serial.begin(115200);                                           

  irrecv.enableIRIn();                                           
}
void loop() {
  if (irrecv.decode()) 
{                                
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);                      
    delay(500);                                                 
    irrecv.resume();                                              
  }
}
