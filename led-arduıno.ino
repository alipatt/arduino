#include <LiquidCrystal_I2C_AvrI2C.h>
#include <virtuabotixRTC.h>
#include <SD.h>
#include <SPI.h>
File myFile;
int pinCS = 53;
int signal1[] = {38, 40, 42};
int signal2[] = {44, 46, 48};
int signal3[] = {39, 41, 43};
int signal4[] = {9 , 10, 11};


int redDelay = 5000;
int yellowDelay = 2000;
// Creation of the Real Time Clock Object
//SCLK -> 5, I/O -> 4, CE -> 3
virtuabotixRTC myRTC(6, 7, 8);
LiquidCrystal_I2C_AvrI2C lcd(0x27,16,2);
 
void setup() {
   for (int i = 0; i < 3; i++) {
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);
    pinMode(signal3[i], OUTPUT);
    pinMode(signal4[i], OUTPUT);
   }
  lcd.begin();
  lcd.backlight();
Serial.begin(9600);
 pinMode(pinCS, OUTPUT);
 
// Dilediðiniz tarihi aþaðýda belirtilen biçimde girebiliyorsunuz. Ben örnek olarak
// bugünün tarihini girdim.
// saniye, dakika, saat, haftanýn günü, ayýn günü, ay, yýl (Not: haftanýn günü 1:pazartesiden baþlýyor
//myRTC.setDS1302Time(40, 27, 21,7, 22, 12, 2019);

  
  // SD Card Initialization
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }


}

void loop() {


myRTC.updateTime();
writetosdcard();
lcd.clear();
 
  lcd.print("Date: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
   

    digitalWrite(signal1[2], HIGH);
  digitalWrite(signal1[0], LOW);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[0], HIGH);
  delay(redDelay);
     

  // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
  digitalWrite(signal1[1], HIGH);
  digitalWrite(signal1[2], LOW);
  myRTC.updateTime();
lcd.clear();
 
  lcd.print("Date: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
  delay(yellowDelay);
  myRTC.updateTime();
    writetosdcard1();
lcd.clear();
 
  lcd.print("Date: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
  
  digitalWrite(signal1[1], LOW);
    

  // Making Green  LED at signal 2 and red LED's at other signal HIGH
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[2], HIGH);
  digitalWrite(signal2[0], LOW);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[0], HIGH);
  myRTC.updateTime();
lcd.clear();
 
  lcd.print("Date: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
  delay(redDelay);
  

  // Making Green LED at signal 2 LOW and making yellow LED at signal 2 HIGH for 2 seconds
  digitalWrite(signal2[1], HIGH);
  digitalWrite(signal2[2], LOW);
  myRTC.updateTime();
lcd.clear();
 
  lcd.print("Date: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
  delay(yellowDelay);

  
  digitalWrite(signal2[1], LOW);
  

  // Making Green  LED at signal 3 and red LED's at other signal HIGH
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[2], HIGH);
  digitalWrite(signal3[0], LOW);
  digitalWrite(signal4[0], HIGH);
  myRTC.updateTime();
    writetosdcard2();
lcd.clear();
 
  lcd.print("Date: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
  delay(redDelay);
  
  // Making Green LED at signal 3 LOW and making yellow LED at signal 3 HIGH for 2 seconds
  digitalWrite(signal3[1], HIGH);
  digitalWrite(signal3[2], LOW);
  myRTC.updateTime();
lcd.clear();
 
  lcd.print("Date: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
  delay(yellowDelay);
  
  digitalWrite(signal3[1], LOW);


  // Making Green  LED at signal 4 and red LED's at other signal HIGH
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[2], HIGH);
  digitalWrite(signal4[0], LOW);
  myRTC.updateTime();
  writetosdcard3();
lcd.clear();
 
  lcd.print("Date: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
  delay(redDelay);
   

  // Making Green LED at signal 4 LOW and making yellow LED at signal 4 HIGH for 2 seconds
  digitalWrite(signal4[1], HIGH);
  digitalWrite(signal4[2], LOW);
  myRTC.updateTime();
lcd.clear();
 
  lcd.print("Date: ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
  delay(yellowDelay);
  digitalWrite(signal4[1], LOW);
   

} 

void writetosdcard(){

myFile = SD.open("kavsak.txt", FILE_WRITE);
 if (myFile) {

myFile.print("The first traffic light turned green at: ");
     myFile.print(myRTC.month);
    myFile.print("/");
    myFile.print(myRTC.dayofmonth);
    myFile.print("/");
    myFile.print(myRTC.year);
    myFile.print("  ");
    myFile.print(myRTC.hours);
    myFile.print(":");
    myFile.print(myRTC.minutes);
    myFile.print(":");
    myFile.print(myRTC.seconds);
    myFile.println("");
 myFile.close();
 }

else {

Serial.println("Error opening text");

}

}

void writetosdcard1(){
myFile = SD.open("kavsak.txt", FILE_WRITE);
 if (myFile) {
  

myFile.print("The second traffic light turned green at: ");
      myFile.print(myRTC.month);
    myFile.print("/");
    myFile.print(myRTC.dayofmonth);
    myFile.print("/");
    myFile.print(myRTC.year);
    myFile.print("  ");
    myFile.print(myRTC.hours);
    myFile.print(":");
    myFile.print(myRTC.minutes);
    myFile.print(":");
    myFile.print(myRTC.seconds);
    myFile.println("");
 myFile.close();
 Serial.println("Done.");
 }

else {

Serial.println("Error saving traffic lights.txt");

}

}

void writetosdcard2(){

myFile = SD.open("kavsak.txt", FILE_WRITE);
 if (myFile) {


myFile.print("The third traffic light turned green at: ");
   myFile.print(myRTC.month);
    myFile.print("/");
    myFile.print(myRTC.dayofmonth);
    myFile.print("/");
    myFile.print(myRTC.year);
    myFile.print("  ");
    myFile.print(myRTC.hours);
    myFile.print(":");
    myFile.print(myRTC.minutes);
    myFile.print(":");
    myFile.print(myRTC.seconds);
    myFile.println("");
 myFile.close();
 Serial.println("Done.");
 }

else {

Serial.println("Error saving traffic lights.txt");

}

}

void writetosdcard3(){
 myFile = SD.open("kavsak.txt", FILE_WRITE);

 if (myFile) {

myFile.print("The forth traffic light turned green at: ");
    myFile.print(myRTC.month);
    myFile.print("/");
    myFile.print(myRTC.dayofmonth);
    myFile.print("/");
    myFile.print(myRTC.year);
    myFile.print("  ");
    myFile.print(myRTC.hours);
    myFile.print(":");
    myFile.print(myRTC.minutes);
    myFile.print(":");
    myFile.print(myRTC.seconds);
    myFile.println("");
 myFile.close();
 Serial.println("Done.");
 }

else {

Serial.println("Error saving traffic lights.txt");

}

}
