int selectorPins[2] = {8,7};
int dataPins[8] = {13,12,27,33,15,32,14,20};
int writePin = 19;
int receiver = 21;
int delayValue = 0;

int xWeight = 0;
int bias = 0;
int learningRate = 1;

struct Sample {
    int x;
    int target;
};

std::vector<Sample> trainingData = {
    {17,0},  {142,1}, {63,0},  {201,1},
    {91,0},  {128,1}, {34,0},  {176,1},
    {119,0}, {225,1}, {48,0},  {153,1},
    {72,0},  {194,1}, {7,0},   {238,1},
    {105,0}, {131,1}, {56,0},  {167,1},
    {123,0}, {215,1}, {28,0},  {149,1},
    {84,0},  {187,1}, {42,0},  {255,1},
    {66,0},  {137,1}, {14,0},  {219,1},
    {99,0},  {160,1}, {37,0},  {202,1},
    {110,0}, {129,1}, {52,0},  {234,1}
};

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
  delay(delayValue);
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
  delay(delayValue);
}

void makeWeight(char value[]){
  setSelectorPins("01");
  pulseWrite();
  setDataPins(value);
  pulseWrite();
  delay(delayValue);
}

void makeTheshold(char value[]){
  setSelectorPins("11");
  pulseWrite();
  setDataPins(value);
  pulseWrite();
  delay(delayValue);
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

char* intToBinary8(int number) {
    static char value[9];

    for (int i = 7; i >= 0; i--) {
        value[7 - i] = ((number >> i) & 1) ? '1' : '0';
    }

    value[8] = '\0';

    return value;
}

void update(){
  makeBias(intToBinary8(bias));
  makeWeight(intToBinary8(xWeight));
}

int neuron(Sample currentSample){
  setSelectorPins("00");
  pulseWrite();
  setDataPins(intToBinary8(currentSample.x));
  return (readReciever());
}

// run the training data
void training()
{
    bool changed;
    int epoch = 0;
    //repeat training until no changes are made
    do
    {
        // start epoch
        epoch++;
        changed = false;
        Serial.println("epoch:" + String(epoch));

        // train across the training set
        for (auto currentSample : trainingData)
        {
            int result = neuron(currentSample);// result of forward propagation
            int error = currentSample.target - result;// error compared to the target

            if (error != 0)
            {
                xWeight += learningRate * error * currentSample.x;// update weight
                bias += learningRate * error;// update offset
                update();
                changed = true;
            }
        }
    }while (changed);
}





void neuralNetwork(){
  Serial.println("------------------------");
  Serial.println("RUNNING TRAINING");
  Serial.println("------------------------");

  training();
  Serial.println("weight:" + String(xWeight));
  Serial.println("Bias:" + String(bias));
 

}


void setup() {
  // put your setup code here, to run once:
  setupPins();
  
  Serial.begin(115200);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char in = Serial.read(); 
    if (in == '\n'){
      makeTheshold(intToBinary8(127));
      neuralNetwork();
    }
  }
}
