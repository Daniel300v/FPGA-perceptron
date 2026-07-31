# FPGA-perceptron-
This is an experiment to create an event driven FPGA based perceptron

python version 3.12.0

python testing framework: cocotb

VHDL simulation: NVC

VHDL development environment GOWIN


## Eight bit perceptron theory

The current implementation of the perceptron adheres to a few limitations. Firstly, it will only be limited to eight bit unsigned integer values. Secondly, multiplication will be replaced with bit shifting. Thirdly, the activation function used will be a simple threshold funchtion.


## Architecture

```text
          Input
            │
            ▼
     Barrel Shifter
            │
            ▼
       8-bit Adder
            │
            ▼
       Comparator
            │
            ▼
         Output
```


## Eight bit perceptron implementation

Currently the perceptron is made of two parts, a barrel shifter and an adder. These are used to replicate the input weight and neuron offset. The total design so far is as follows:

<img width="1347" height="231" alt="image" src="https://github.com/user-attachments/assets/ba5be571-c020-4066-8154-d535c2d2cd42" />

Currently the weights are hard coded, as well as the static value for the comparator. This will be improved in future entries.

## barrel shifter

The barrel shifter consists of three layers of left bit shifts that allow for the shifting of either 1, 2, or 4 bits individually, which allows for any 3 bit combination of left shift. Design as follows:

<img width="1345" height="285" alt="image" src="https://github.com/user-attachments/assets/b1203870-1193-4855-b2c0-8983451b7ff5" />

## Adder

The adder design is a standard simple eight bit adder, with the design following the same implementation as the following: 

<img width="1125" height="572" alt="image" src="https://github.com/user-attachments/assets/220c0e3a-9718-4ea7-9706-cc5084739f30" />

## Comparitor

The comparator evaluates if the perceptron's value is greater than or equal to a statically defined value. It uses a primitive design that is easily improved to use fewer gates / LUTs.

<img width="1306" height="182" alt="image" src="https://github.com/user-attachments/assets/68c9c94d-165b-43b0-bb88-209763380e40" />





















