

int selectorPins[2] = {38,39};
int dataPins[8] = {13,12,11,10,9,6,5,4};
int returnPin = 37;


void setup() {
  // put your setup code here, to run once:
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

  pinMode(returnPin, INPUT);

  ///////////////////////////
  
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


}

void loop() {
  // put your main code here, to run repeatedly:

}
