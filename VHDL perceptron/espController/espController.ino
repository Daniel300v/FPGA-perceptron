

int selectorPins[2] = {18,17};
int dataPins[8] = {13,12,27,33,15,32,14,20};
int returnPin = 15;

int pinIndex = 0;

void setup() {

  pinMode(dataPins[0], OUTPUT);
  pinMode(dataPins[1], OUTPUT);
  pinMode(dataPins[2], OUTPUT);
  pinMode(dataPins[3], OUTPUT);
  pinMode(dataPins[4], OUTPUT);
  pinMode(dataPins[5], OUTPUT);
  pinMode(dataPins[6], OUTPUT);
  pinMode(dataPins[7], OUTPUT);

  // pinMode(selectorPins[0], OUTPUT);
  // pinMode(selectorPins[1], OUTPUT);

  // pinMode(returnPin, INPUT);

  // ///////////////////////////
  
  digitalWrite(dataPins[0], LOW);
  digitalWrite(dataPins[1], LOW);
  digitalWrite(dataPins[2], LOW);
  digitalWrite(dataPins[3], LOW);
  digitalWrite(dataPins[4], LOW);
  digitalWrite(dataPins[5], LOW);
  digitalWrite(dataPins[6], LOW);
  digitalWrite(dataPins[7], LOW);

  // digitalWrite(selectorPins[0], LOW);
  // digitalWrite(selectorPins[1], LOW);

  Serial.begin(115200);

}

void loop() {

  if (Serial.available()) {
    char in = Serial.read();
    
    

    if (in == '0'){
      digitalWrite(dataPins[pinIndex], LOW);
      Serial.print("0");
      pinIndex++;
    }
    else if (in == '1'){
      digitalWrite(dataPins[pinIndex], HIGH);
      Serial.print("1");
      pinIndex++;
    }
    else{
      pinIndex = 0;
      Serial.println("\n");
    }
    
  }

  //delay(1000);

}
