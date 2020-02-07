volatile unsigned int pulsos = 0;
 
void ContaPulso()
{
   pulsos++;
}
 
void setup()
{
   Serial.begin(9600);
   attachInterrupt(0, ContaPulso, RISING);
}
 
void loop()
{
   volatile unsigned long t=millis();
   int c=0;
   while((millis()-t) >= 1000)
   {
   }
   
   Serial.println(pulsos);
   pulsos=0;
}
