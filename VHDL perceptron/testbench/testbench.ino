int selectorPins[2] = {8,7};
int dataPins[8] = {13,12,27,33,15,32,14,20};
int writePin = 21;
int receiver = 19;

void setupPins(){
  pinMode(dataPins[0], OUTPUT);
  pinMode(dataPins[1], OUTPUT);
  pinMode(dataPins[2], OUTPUT);
  pinMode(dataPins[3], OUTPUT);
  pinMode(dataPins[4], OUTPUT);
  pinMode(dataPins[5], OUTPUT);
  pinMode(dataPins[6], OUTPUT);
  pinMode(dataPins[7], OUTPUT);

  pinMode(selectorPins[0], OUTPUT);
  pinMode(selectorPins[1], OUTPUT);

  pinMode(writePin, OUTPUT);

  pinMode(receiver, INPUT);

  digitalWrite(dataPins[0], LOW);
  digitalWrite(dataPins[1], LOW);
  digitalWrite(dataPins[2], LOW);
  digitalWrite(dataPins[3], LOW);
  digitalWrite(dataPins[4], LOW);
  digitalWrite(dataPins[5], LOW);
  digitalWrite(dataPins[6], LOW);
  digitalWrite(dataPins[7], LOW);

  digitalWrite(selectorPins[0], LOW);
  digitalWrite(selectorPins[1], LOW);

  digitalWrite(writePin, LOW);
}

void pulseWrite(){
  Serial.println("WRITE");
  digitalWrite(writePin, HIGH);
  delay(1);
  digitalWrite(writePin, LOW);
}

void setDataPins(char value[]){
  for (int i = 0; i < 8; i++){
    if (value[i] == '0'){
      digitalWrite(dataPins[7- i], LOW);
    }
    else{
      digitalWrite(dataPins[7- i], HIGH);
    }
  }
  Serial.print("Data pins set to: ");
  Serial.println(value);
}

void setSelectorPins(char value[]){
  for (int i = 0; i < 2; i++){
    if (value[i] == '0'){
      digitalWrite(selectorPins[1-i], LOW);
    }
    else{
      digitalWrite(selectorPins[1-i], HIGH);
    }
  }
  Serial.print("Selector pins set to: ");
  Serial.println(value);
}

int readReciever(){
  int val = digitalRead(receiver);
  Serial.print("Receiver pin value: ");
  Serial.println(val);
  return(val);
}

void makeBias(char value[]){
  setSelectorPins("10");
  pulseWrite();
  setDataPins(value);
  pulseWrite();
  delay(500);
}

void makeWeight(char value[]){
  setSelectorPins("01");
  pulseWrite();
  setDataPins(value);
  pulseWrite();
  delay(500);
}

int assurt(int expected){
  int ret = readReciever();
  if (ret == expected){
    Serial.println("VALID");
    return (1);
  }
  else{
    Serial.println("INVALID");
    return (0);
  }
}

void test1(){
  Serial.println("Test 1");
  setSelectorPins("00");
  pulseWrite();
  setDataPins("00010000");
  delay(500);
  int ret = readReciever();
  Serial.println("------------------------");
  if (ret == 1){
    Serial.println("PASSED");
  }
  else{
    Serial.println("FAILED");
  }
  Serial.println("------------------------");
}

void test2(){
  Serial.println("Test 2");
  setSelectorPins("00");
  pulseWrite();
  setDataPins("00000100");
  delay(500);
  int ret = readReciever();
  Serial.println("------------------------");
  if (ret == 0){
    Serial.println("PASSED");
  }
  else{
    Serial.println("FAILED");
  }
  Serial.println("------------------------");
}

void test3(){
  Serial.println("Test 3 - threshold change");
  setSelectorPins("11");
  pulseWrite();
  setDataPins("00000010");
  pulseWrite();
  delay(500);
  int ret = readReciever();
  Serial.println("------------------------");
  Serial.println("Check LED's");
  Serial.println("------------------------");
}

void test4(){
  Serial.println("Test 4 - bias change");
  setSelectorPins("10");
  pulseWrite();
  setDataPins("00000010");
  pulseWrite();
  delay(500);
  int ret = readReciever();
  Serial.println("------------------------");
  Serial.println("Check LED's");
  Serial.println("------------------------");
}

void test5(){
  Serial.println("Test 5 - weight change");
  setSelectorPins("01");
  pulseWrite();
  setDataPins("00000001");
  pulseWrite();
  delay(500);
  int ret = readReciever();
  Serial.println("------------------------");
  Serial.println("Check LED's");
  Serial.println("------------------------");
}

void test6(){
  Serial.println("Test 6 -- forward x4 back forward x4");
  bool passed = true;

  makeWeight("00000010");
  makeBias("00000101");

  setSelectorPins("00");
  pulseWrite();

  setDataPins("00000110");
  delay(500);
  passed = passed & assurt(1);

  setDataPins("00000111");
  delay(500);
  passed = passed & assurt(1);

  setDataPins("00000010");
  delay(500);
  passed = passed & assurt(0);

  setDataPins("00000100");
  delay(500);
  passed = passed & assurt(0);

  makeWeight("00000011");
  makeBias("00000010");

  setSelectorPins("00");
  pulseWrite();
  setDataPins("00000101");
  delay(500);
  passed = passed & assurt(1);

  setDataPins("00000111");
  delay(500);
  passed = passed & assurt(1);

  setDataPins("00000001");
  delay(500);
  passed = passed & assurt(0);

  setDataPins("00000011");
  delay(500);
  passed = passed & assurt(0);

  Serial.println("------------------------");
  if (passed){
    Serial.println("PASSED");
  }
  else{
    Serial.println("FAILED");
  }
  Serial.println("------------------------");

}


void tests(){
  Serial.println("------------------------");
  Serial.println("RUNNING TESTS");
  Serial.println("------------------------");
  //test1();
  test2();
  //test3();
  //test4();
  //test5();
  //test6();
}


void setup() {

  setupPins();
  
  Serial.begin(115200);
  delay(2000);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char in = Serial.read(); 
    if (in == '\n'){
      tests();
    }
  }
}
