#include <IRremote.h>      

int RECV_PIN = 34;                                               
int led1=16; int led2=17; int led3=18; int led4=19; 

IRrecv irrecv(RECV_PIN);                                        
decode_results results;                                         

void setup()
{
  Serial.begin(115200);                                           
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT);                                   
  pinMode(led3, OUTPUT);   
  pinMode(led4, OUTPUT);  
  irrecv.enableIRIn();                                           
}

void loop() {
  if (irrecv.decode()) 
{                                
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);

    switch (irrecv.decodedIRData.decodedRawData)  {  // kontrola prijatého kódu
 
      case 0xEF10BF00:      // pri stlačení 1:                                              
        digitalWrite(led1, HIGH);   		
        delay(500);     				
        digitalWrite(led1, LOW); 		
      break;
 
      case 0xEE11BF00:     // pri stlačení 2:                                                                          
        digitalWrite(led2, HIGH);   
        delay(500);     				
        digitalWrite(led2, LOW);    
      break;
      
      case 0xED12BF00:     // pri stlačení 3:                                                                                                                                      
        digitalWrite(led3, HIGH);   
        delay(500);     
        digitalWrite(led3, LOW);  
      break;
      
      case 0xEB14BF00:     // pri stlačení 4:                                                                                                                                  
        digitalWrite(led4, HIGH);   
        delay(500);     
        digitalWrite(led4, LOW); 
      break;
      
      case 0xF50ABF00:     // pri stlačení šípky v pravo:                                                                                                                                                                                                    
        for (int i = 16; i<=19; i++)
          {digitalWrite(i, HIGH);     
          delay(100);     
          digitalWrite(i, LOW);
          delay(100);  }                                         
      break;
     
      case 0xF708BF00:		// pri stlačení šípky v ľavo:                                                                                                                                                                                                                            
        for (int i = 19; i>=16; i--)
          {digitalWrite(i, HIGH);     
          delay(100);     
          digitalWrite(i, LOW);
          delay(100);  }                                            
      break;
      
      case 0xF609BF00:  	// pri stlačení OK:                                                                                                                                  
        for (int i = 16; i<=19; i++)
          {digitalWrite(i, HIGH);     
          delay(50);     
          digitalWrite(i, LOW);
          delay(50);  }                                                                                           
        for (int i = 19; i>=16; i--)
          {digitalWrite(i, HIGH);     
          delay(50);     
          digitalWrite(i, LOW);
          delay(50);  }                                            
      break;
      }
                       
    delay(500);                                                 
    irrecv.resume();   //pokračuje v prijímaní IR signálov                                           
  }
}
