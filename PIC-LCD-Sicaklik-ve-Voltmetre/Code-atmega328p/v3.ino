// include the library code:
#include <LiquidCrystal.h>
#include <DHT.h>

int butonPin = 8;
int buton_deger_tutucu = 0;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int analogInput = A0;
float vout = 0.0;
float vin = 0.0;
float R1 = 10000.0; // 10K ohm direnç
float R2 = 5000.0; // 5K ohm direnç
int value = 0;

#define DHTPIN 13
#define DHTTYPE DHT11  // DHT11 modulunu tanimliyoruz
DHT dht(DHTPIN, DHTTYPE);

float sicaklik;
float nem;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  dht.begin();
  pinMode(analogInput, INPUT);
  pinMode(butonPin,INPUT);
 
  lcd.setCursor(0, 0);
  lcd.print("Voltmetre ve");
  lcd.setCursor(0, 1);
  lcd.print("Sicaklik");
  delay(3000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("181202031 ");
  lcd.setCursor(2, 1);
  lcd.print("Fatih Furkan");
  delay(3500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Program ");
  lcd.setCursor(0, 1);
  lcd.print("Baslatılıyor..");
  delay(3000);
  
}

void loop() {
  value = analogRead(analogInput);
  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2/(R1+R2));

  float hum = dht.readHumidity();
  float tem = dht.readTemperature();
  



  if(buton_deger_tutucu==1){
    if (vin<0.09) {
    vin=0.0;
    }
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("VOLTMETRE");
    lcd.setCursor(4, 1);
    lcd.print("V= ");
    lcd.print(vin);
    delay(100);
  }
  else{ 
  sicaklik = dht.readTemperature();
  nem = dht.readHumidity();
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Sicaklik:");
  lcd.print(tem);
  lcd.setCursor(3, 1);
  lcd.print("Nem:");
  lcd.print(hum);
  delay(100);
  }

  
    if(digitalRead(butonPin) == 1){
    delay(150);
    if(buton_deger_tutucu==0){
      buton_deger_tutucu=1;
    }
    else {
      buton_deger_tutucu=0;
    }
  }
  
}
