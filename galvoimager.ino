int a=0;
char pixbuf[64];
int xpos = 0;
int ypos = 0;
int xgalvo = A21;
int ygalvo = A22;

void setup() {
pinMode(xgalvo,OUTPUT);
pinMode(ygalvo,OUTPUT);
analogWriteResolution(9);
analogReadResolution(8);
Serial.begin(300);
}

void loop() {
    // wait for serial port to be opened
  while (!Serial);
  //Serial.println("test");
// Génère les signaux pour contrôller les  galvos
analogWrite(xgalvo,xpos+95);
analogWrite(ygalvo,ypos+135);
xpos++;
if (xpos >= 320) {
  xpos = 0;
  ypos++;
}
//if (ypos >=240) ypos = 0;

// Save adc reading to buffer and send it through usb
pixbuf[a] = char(analogRead(A0));
a++;
if (a == 64) {
  String str(pixbuf);
  str.remove(64);//remove the null character the string constructor has added
  Serial.print(str);
  a = 0;
}
//delay(400);
if (ypos >=240) {
  Serial.println("");
  while(1);
}
}
