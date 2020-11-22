#include <SoftwareSerial.h>
#include <String.h>
//Współrzędne Piotrków Trybunalski w stopniach dziesiętnych
//Szerokość: 51.4054700°
//Długość: 19.7032100° 
//String lat = "51.4054700";
//String lng = "19.7032100";
SoftwareSerial sim800l(16, 17); // TX, RX, ŻÓŁTY, FIOLETOWY.
int PIR_1 = 7; // CZUJNIK PIR_1
int LED_1 = 8; // LED_1

void setup()
{
 
  sim800l.begin(9600);
  Serial.begin(9600);   
  delay(500);
  pinMode(PIR_1, INPUT);  // CZUJNIK PIR_1 
  pinMode(LED_1, OUTPUT); // LED_1
  digitalWrite(PIR_1, LOW);
}
 
void loop()
{
         if (digitalRead(PIR_1) == HIGH)
          {
            digitalWrite(LED_1, HIGH);
            Serial.println("Motion detected");
            //SendTextMessage(); Wysyłanie SMS
          }
         else
            {
              digitalWrite(LED_1, LOW);  
            }
delay (500);
}
 
void SendTextMessage()
{
  Serial.println("Sending Text...");
  sim800l.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+48*********\"\r"); // Numer telefonu do powiadomień  
  delay(200);
  sim800l.print("Motion detected !"); //the content of the message
  delay(500);
  sim800l.print((char)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(500);

}
 
