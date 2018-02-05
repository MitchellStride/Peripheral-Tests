
const int buzz = 7;

const int keyC = 28;
const int keyD = 27;
const int keyE = 26;
const int keyF = 25;
const int keyG = 24;
const int keyA = 23;
const int keyB = 22;
const int keyH = 29;


int buttonC;
int buttonD;
int buttonE;
int buttonF;
int buttonG;
int buttonA;
int buttonB;
int buttonH;


void setup() {
  pinMode(keyC, INPUT_PULLUP);
  pinMode(keyD, INPUT_PULLUP);
  pinMode(keyE, INPUT_PULLUP);
  pinMode(keyF, INPUT_PULLUP);
  pinMode(keyG, INPUT_PULLUP);
  pinMode(keyA, INPUT_PULLUP);
  pinMode(keyB, INPUT_PULLUP);
  pinMode(keyH, INPUT_PULLUP);
}

void loop() {
buttonC = digitalRead(keyC);
buttonD = digitalRead(keyD);
buttonE = digitalRead(keyE);
buttonF = digitalRead(keyF);
buttonG = digitalRead(keyG);
buttonA = digitalRead(keyA);
buttonB = digitalRead(keyB);
buttonH = digitalRead(keyH);
if((buttonC == LOW)||(buttonD == LOW)||(buttonE == LOW)||(buttonF == LOW)||(buttonG == LOW)||(buttonA == LOW)||(buttonB == LOW)|(buttonH == LOW)){ 
 if(buttonC == LOW)
  tone(buzz, 1047);

 if(buttonD == LOW)
  tone(buzz, 1175);

 if(buttonE == LOW)
  tone(buzz, 1319);

 if(buttonF == LOW)
  tone(buzz, 1397);

 if(buttonG == LOW)
  tone(buzz, 1568);

 if(buttonA == LOW)
  tone(buzz, 1760);

 if(buttonB == LOW)
  tone(buzz, 1976);

 if(buttonH == LOW)
  tone(buzz, 2093);
  
}else{
  noTone(buzz);
}
}
