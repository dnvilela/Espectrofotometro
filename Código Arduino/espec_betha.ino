char buffer[18];
int red, green, blue;
int RedPin = 11;
int GreenPin = 10;
int BluePin = 9;
int LDR_Pin = A0;
float ldr_read = 0;
float light_trans = 0;

void setup() {
Serial.begin(9600);
Serial.flush();
pinMode(RedPin, OUTPUT);
pinMode(GreenPin, OUTPUT);
pinMode(BluePin, OUTPUT);
}

void loop() {
if (Serial.available() > 0) {
int index=0;
delay(100);
int numChar = Serial.available();
if (numChar>15) {
numChar=15;
}
while (numChar--) {
buffer[index++] = Serial.read();
}
splitString(buffer);
}
}

void splitString(char* data) {
Serial.print("Dados de entrada: ");
Serial.println(data);
char* parameter;
parameter = strtok (data, " ,");
while (parameter != NULL) {
setLED(parameter);
parameter = strtok (NULL, " ,");
}
for (int x=0; x<16; x++) {
buffer[x]='\0';
}
Serial.flush();
}

void setLED(char* data) {
if ((data[0] == 'r') || (data[0] == 'R')) {
int Ans = strtol(data+1, NULL, 10);
Ans = constrain(Ans,0,255);
analogWrite(RedPin, Ans);
Serial.print("Vermelho: ");
Serial.println(Ans);
}
if ((data[0] == 'g') || (data[0] == 'G')) {
int Ans = strtol(data+1, NULL, 10);
Ans = constrain(Ans,0,255);
analogWrite(GreenPin, Ans);
Serial.print("Verde: ");
Serial.println(Ans);
}
if ((data[0] == 'b') || (data[0] == 'B')) {
int Ans = strtol(data+1, NULL, 10);
Ans = constrain(Ans,0,255);
analogWrite(BluePin, Ans);
Serial.print("Azul: ");
Serial.println(Ans);
Serial.println("Resultado: ");
delay(5000);

ldr_read = analogRead(LDR_Pin);
Serial.print("Leitura LDR: ");
Serial.println(ldr_read);
light_trans = ((ldr_read * 100)/1023);
light_trans = (100 - light_trans);
Serial.print("Transmitancia: ");
Serial.print(light_trans);
Serial.println("%");
Serial.println();
}
}
