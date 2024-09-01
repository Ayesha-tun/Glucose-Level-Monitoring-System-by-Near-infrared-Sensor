#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int soil = A0;
int ir1state=0;
int ir2state=0;
int ir3state=0;
int ir4state=0;
int ir5state=0;int ir6state=0;int vout=0; int xout=0; int yout=0; 
int zout=0; int zout1=0; int zout2=0; int zout3=0; int zoutT=0;
void setup()
{
pinMode(soil,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
lcd.backlight();
lcd.init();
lcd.clear();
delay(2000);
}
void loop()
{
ir1state=analogRead(soil);
ir2state=(8*10^-5)*ir1state^2;
xout=0.1873*ir1state;
yout=ir2state+xout+46.131;
vout=yout*(-1);
zout1=vout/100;
ir3state=analogRead(soil);
ir4state=(8*10^-5)*ir3state^2;
xout=0.1873*ir3state;
yout=ir4state+xout+46.131;
vout=yout*(-1);
zout2=vout/100;
ir5state=analogRead(soil);
ir6state=(8*10^-5)*ir5state^2;
xout=0.1873*ir5state;
yout=ir6state+xout+46.131;
vout=yout*(-1);
zout3=vout/100;
zout=(zout1+zout2+zout3)/3;
if ((ir1state<=300)&&(ir1state>=20) && (ir3state<=300) && (ir3state>=20) && (ir5state<=300)&& (ir5state>=20) && (zout>0)){
Serial.print("Voltage in mv:");
Serial.println(ir1state);
Serial.print("GLUCOSE LEVEL\n");
Serial.print("GLUCOSE in mg/dl: ");
Serial.println(zoutT);
Serial.print("\n");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("GLUCOSE LEVEL");
lcd.setCursor(0,1);
lcd.print("MONITOR SYSTEM");
delay(800);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("GLUCOSE in mg/dl:");
lcd.setCursor(0,1);
lcd.print(zoutT);
delay(1000);
}
else
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("GLUCOSE LEVEL");
lcd.setCursor(0,1);
lcd.print("MONITOR SYSTEM");
delay(1000);
}}