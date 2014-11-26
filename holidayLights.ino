/*
 */

void setup() 
{
  Serial.begin(57600);
 
  Serial.setTimeout(5);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
 }
 
#define slider1  13
#define slider2  14
#define slider3  15

void loop() {
  char buffer[64];
  size_t length = 64; 
      
  length = Serial.readBytes(buffer, length);    
  
  if ( length > 0 )
  {
    for (int i = 0; i < length - 1; i += 2 )
    {
      if ( buffer[i] == slider1 )
      {
        analogWrite(0,255*(1-buffer[i+1]));
      }
      else if ( buffer[i] == slider2 )
      {
        analogWrite(1,255*(1-buffer[i+1]));
      }
      else if ( buffer[i] == slider3 )
      {
        analogWrite(2,255*(1-buffer[i+1]));
      }
    }
  }
}
