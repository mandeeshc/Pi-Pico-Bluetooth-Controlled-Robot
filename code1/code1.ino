#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4,5,6,7,8,9);
char t;

#define M0 18
#define M1 19
#define M2 20
#define M3 21

char incomingByte;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  
  Serial1.begin(9600);
  Serial1.println("System Started"); 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("ANDROID CONTROLD");
  lcd.setCursor(0, 1);    
  lcd.print("     ROBOT      ");
  
  delay(3000);
  lcd.clear();  
  
  pinMode(M0, OUTPUT);  pinMode(M2, OUTPUT);
  pinMode(M1, OUTPUT);  pinMode(M3, OUTPUT);

  digitalWrite(M0, LOW);   digitalWrite(M1, LOW);   
  digitalWrite(M2, LOW);   digitalWrite(M3, LOW);
  
}

void serialFlush(){
  
  while(Serial1.available() > 0) {
    t = Serial1.read();
  }
  t=0;
  
}   

// the loop routine runs over and over again forever:
void loop() 
{
    if (Serial1.available() > 0) 
    {
      incomingByte = Serial1.read();
    
    
    //lcd.setCursor(0, 0);    
    // say what you got:
    //Serial.print("I received: ");
    //Serial.println(incomingByte);
 
    if(incomingByte == 'F')    // FORWARD
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    FORWARD     ");
      
      digitalWrite(M0, LOW);    digitalWrite(M1, HIGH);   
      digitalWrite(M2, HIGH);   digitalWrite(M3, LOW);
      serialFlush();
    }
    else if(incomingByte == 'B')    // BACKWARD
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("   BACKWARD     ");
      digitalWrite(M0, HIGH);  digitalWrite(M1, LOW);   
      digitalWrite(M2, LOW);   digitalWrite(M3, HIGH);
      serialFlush();
    }
    else if(incomingByte == 'R')   // RIGHT
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("     RIGHT      ");
      digitalWrite(M0, LOW);    digitalWrite(M1, HIGH);   
      digitalWrite(M2, LOW);    digitalWrite(M3, HIGH);
 
      serialFlush();
    }
    else if(incomingByte == 'L')   // LEFT
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    LEFT       ");
      digitalWrite(M0, HIGH);  digitalWrite(M1, LOW);   
      digitalWrite(M2, HIGH);  digitalWrite(M3, LOW);
 
      serialFlush();
    }
    else if(incomingByte == 'S')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("     STOP       ");
      digitalWrite(M0, LOW);  digitalWrite(M1, LOW);   
      digitalWrite(M2, LOW);  digitalWrite(M3, LOW);
  
      serialFlush();  
    } 
    }   
 delay(50);  
 
}
