float temp;
float vout;//output of temperature sensor
float vout1; //when the tempertaure increases voltage also incraeses
int LED=13;
int gasSensor;//conc of smoke
int buzzer=7;
void setup() 
{
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(LED,OUTPUT);//when the temp is high led or buzzer will give alert as output
pinMode(buzzer,OUTPUT);
Serial.begin(9600);//to activate the serial Monitor
}
//to convert the sensor value to voltage and voltage to tempertaure we use following logic
 void loop()
 {
   vout=analogRead(A1);
   vout1=(vout/1023)*5000;
   temp=(vout1-500)/10;
   gasSensor=analogRead(A0);
   if(temp>=80)
   {
     digitalWrite(LED,HIGH);
   }
   else
   {
     digitalWrite(LED,LOW);
   }
   if(gasSensor>=100)
   {
     digitalWrite(buzzer,HIGH);
   }
   else
   {
     digitalWrite(buzzer,LOW);
   }
   Serial.print("in DegreeC=");
   Serial.print(" ");
   Serial.print(temp);
   Serial.print("\t");
   Serial.print("GasSensor = ");
   Serial.print(" ");
   Serial.print(gasSensor);
   Serial.println();
   delay(1000);
 }

   