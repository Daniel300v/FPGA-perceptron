int selectorPins[2] = {8,7};
int dataPins[8] = {13,12,27,33,15,32,14,20};
int writePin = 19;
int receiver = 21;
int delayValue = 0;

int xWeight = 0;
int bias = 0;
int learningRate = 1;
int threashold = 100;

struct Sample {
    int x;
    int target;
};

//test set for just the bias NO WEIGHT _________

// std::vector<Sample> trainingData = {
//     {10,0},
//     {20,0},
//     {30,0},
//     {40,0},
//     {45,0},
//     {48,0},
//     {49,0},

//     {50,1},
//     {51,1},
//     {55,1},
//     {60,1},
//     {70,1},
//     {80,1},
//     {90,1},
//     {100,1}
// };

// std::vector<Sample> testData = {
//     {5,0},
//     {15,0},
//     {25,0},
//     {35,0},
//     {42,0},
//     {44,0},
//     {47,0},
//     {49,0},

//     {50,1},
//     {52,1},
//     {53,1},
//     {57,1},
//     {65,1},
//     {75,1},
//     {85,1},
//     {95,1},
//     {105,1}
// };

//test set for just the bias NO WEIGHT ^^^^^^^^^^

//test set for just the weight NO BIAS _________

// std::vector<Sample> trainingData = {
//     {10,0},
//     {20,0},
//     {30,0},
//     {40,0},
//     {45,0},
//     {48,0},
//     {49,0},

//     {50,1},
//     {51,1},
//     {55,1},
//     {60,1},
//     {70,1},
//     {80,1},
//     {90,1},
//     {100,1}
// };

// std::vector<Sample> testData = {
//     {5,0},
//     {15,0},
//     {25,0},
//     {35,0},
//     {42,0},
//     {44,0},
//     {47,0},

//     {52,1},
//     {53,1},
//     {57,1},
//     {65,1},
//     {75,1},
//     {85,1},
//     {95,1},
//     {105,1}
// };

//test set for just the weight NO BIAS ^^^^^^^^^^

//test set for both weight and bias _________

std::vector<Sample> trainingData = {
    {10,0},
    {15,0},
    {20,0},
    {25,0},
    {30,0},
    {32,0},
    {35,0},
    {38,0},
    {39,0},

    {40,1},
    {41,1},
    {42,1},
    {45,1},
    {50,1},
    {55,1},
    {60,1},
    {70,1},
    {80,1}
};

std::vector<Sample> testData = {
    {5,0},
    {12,0},
    {18,0},
    {22,0},
    {28,0},
    {33,0},
    {36,0},
    {37,0},

    {43,1},
    {44,1},
    {46,1},
    {48,1},
    {52,1},
    {57,1},
    {65,1},
    {75,1},
    {90,1}
};

//test set for both weight and bias ^^^^^^^^^^

//this allocates the GPIO pins based off of the global variables at the top of the file
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

//this sends a "clock" signal to the fpga
void pulseWrite(){
  digitalWrite(writePin, HIGH);
  digitalWrite(writePin, LOW);
}

//this sets the data pins to be high or low depending on a character string of 1's and 0's
void setDataPins(char value[]){
  for (int i = 0; i < 8; i++){
    if (value[i] == '0'){
      digitalWrite(dataPins[7- i], LOW);
    }
    else{
      digitalWrite(dataPins[7- i], HIGH);
    }
  }
}

//this sets the selector pins to be high or low depending on a character string of 1's and 0's
void setSelectorPins(char value[]){
  for (int i = 0; i < 2; i++){
    if (value[i] == '0'){
      digitalWrite(selectorPins[1-i], LOW);
    }
    else{
      digitalWrite(selectorPins[1-i], HIGH);
    }
  }
}

//this reads the receiver pin as either a 1 or 0
int readReciever(){
  return(digitalRead(receiver));
}

//this sets the bias on the fpga to match a character string of 1's and 0's
void makeBias(char value[]){
  setSelectorPins("10");
  pulseWrite();
  setDataPins(value);
  pulseWrite();
}

//this sets the weight on the fpga to match a character string of 1's and 0's
void makeWeight(char value[]){
  setSelectorPins("01");
  pulseWrite();
  setDataPins(value);
  pulseWrite();
}

//this sets the threshold on the fpga to match a character string of 1's and 0's
void makeTheshold(char value[]){
  setSelectorPins("11");
  pulseWrite();
  setDataPins(value);
  pulseWrite();
}


//this converts an integer to a character string of 1's and 0's
char* intToBinary8(int number) {
  static char value[9];
  for (int i = 7; i >= 0; i--) {
    value[7 - i] = ((number >> i) & 1) ? '1' : '0';
  }
  value[8] = '\0';
  return value;
}

//this updates both the weight and bias of the fpga
void update(){
  makeBias(intToBinary8(bias));
  makeWeight(intToBinary8(xWeight));
}


int trainingNeuron(Sample currentSample){
  setSelectorPins("00");
  pulseWrite();
  setDataPins(intToBinary8(currentSample.x));
  return (readReciever());
}

//this updates the weight and bias on the microccontroller using update rules
void updateValues(int error){
  if (error > 0)
  {
    // Output was too low
    if (xWeight < 7)
      xWeight++;
  }
  else if (error < 0)
  {
    // Output was too high
    if (xWeight > 0)
      xWeight--;
  }
  bias += learningRate * error;// update offset
}



// run the training data
void training(){
  bool changed;
  int maxEpoch = 1000;
  int epoch = 0;
  //repeat training until no changes are made
  do
  {
    // start epoch
    epoch++;
    changed = false;
    //Serial.println("epoch:" + String(epoch));

    // train across the training set
    for (auto currentSample : trainingData)
    {
      int result = trainingNeuron(currentSample);// result of forward propagation
      int error = currentSample.target - result;// error compared to the target

      if (error != 0)
      {
        updateValues(error);
        update();
        changed = true;
      }
    }
  }while (changed && epoch < maxEpoch);
}

//this executes the test set
void test(){
  setSelectorPins("00");
  pulseWrite();
  int correct = 0;
  for (auto currentSample : testData)
  {
    setDataPins(intToBinary8(currentSample.x));
    if (readReciever() == currentSample.target)
    {
      correct++;
    }
  }
  // output the results
  Serial.println("correct:" + String(correct));
  Serial.println("total:" + String(testData.size()));
}

//this performs the training and testing
void neuralNetwork(){
  makeTheshold(intToBinary8(threashold));
  
  Serial.println("------------------------");
  Serial.println("RUNNING TRAINING");
  Serial.println("------------------------");

  training();
  Serial.println("weight:" + String(xWeight));
  Serial.println("Bias:" + String(bias));

  Serial.println("------------------------");
  Serial.println("RUNNING TEST SET");
  Serial.println("------------------------");
  test();
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
      neuralNetwork();
    }
  }
}
