#include<vector>
#include<string>

struct Sample {
    int x;
    int target;
};

std::vector<Sample> trainingData = {
    {5,0}, {8,0}, {10,0}, {12,0}, {15,0},
    {18,0}, {20,0}, {22,0}, {25,0}, {28,0},
    {30,0}, {32,0}, {35,0}, {38,0}, {40,0},
    {42,0}, {45,0}, {48,0},

    {50,1}, {52,1}, {55,1}, {58,1}, {60,1},
    {62,1}, {65,1}, {68,1}, {70,1}, {72,1},
    {75,1}, {78,1}, {80,1}, {82,1}, {85,1},
    {88,1}, {90,1}, {95,1}, {100,1}
};


std::vector<Sample> testData = {
    {6,0},
    {14,0},
    {24,0},
    {34,0},
    {44,0},
    {49,0},

    {51,1},
    {57,1},
    {67,1},
    {77,1},
    {87,1},
    {99,1}
};

int xWeight = 0;
int offset = 0;
int learningRate = 1;

//this is a threshold activation function
int activation(double sum) {
    return (sum >= 0);
}

//this handles the maths within the neuron
int neuron(Sample currentSample)
{
    int total = (currentSample.x * xWeight) + offset;
    return (activation(total));
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
                offset += learningRate * error;// update offset
                changed = true;
            }
        }
    }while (changed);
}

// evaluate the neuron using the testing data set
void test()
{
    int correct = 0;
    for (auto currentSample : testData)
    {
        if (neuron(currentSample) == currentSample.target)
        {
            correct++;
        }
    }
    // output the results
    Serial.println("correct:" + String(correct));
    Serial.println("total:" + String(testData.size()));
}






void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);  
  Serial.println("hello perceptron");

  //perform training on the training data set
  training();
  //output the values for trained neuron
  Serial.println("weight:" + String(xWeight));
  Serial.println("offset:" + String(offset));
  //use the new values to evaluate the network
  test();

}

void loop() {
  // put your main code here, to run repeatedly:

}
