volatile unsigned long cnt = 0;
unsigned long oldcnt = 0;
unsigned long t = 0;
unsigned long last;

void irq1()
{
  cnt++;
}

///////////////////////////////////////////////////////////////////
//
// SETUP
//
void setup() 
{
  Serial.begin(9600);
  Serial.println("START");
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  attachInterrupt(0, irq1, RISING);
}

///////////////////////////////////////////////////////////////////
//
// MAIN LOOP
//
void loop() 
{
  if (millis() - last > 1000)
  {
    last = millis();
    t = cnt;
    unsigned long hz = t - oldcnt;
    Serial.print("FREQ: "); 
    Serial.print(hz);
    Serial.print("\t = "); 
    Serial.print((hz+50)/100);  // +50 == rounding last digit
    Serial.println(" mW/m2");
    oldcnt = t;
  }
}
