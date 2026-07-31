# FPGA-perceptron-
This is an experiment to create an event driven FPGA based perceptron

python version 3.12.0

python testing framework: cocotb

VHDL simulation: NVC

VHDL development environment GOWIN



Eight bit perceptron implementation

Currently the perceptron is made of two parts, a barrel shifter and an adder. These are used to replicate the input weight and neuron offset. The total design so far is as follows:

<img width="1340" height="219" alt="image" src="https://github.com/user-attachments/assets/a0737815-ae69-4cee-9e89-2f07048f70ef" />

barrel shifter design:

The barrel shifter consists of three layers of left bit shifts that allow for the shifting of either 1, 2, or 4 bits individually, which allows for any 3 bit combination of left shift. Design as follows:

<img width="1345" height="285" alt="image" src="https://github.com/user-attachments/assets/b1203870-1193-4855-b2c0-8983451b7ff5" />

Adder design:

The adder design is a standard simple eight bit adder, with the design following the same implementation as the following: 

<img width="1125" height="572" alt="image" src="https://github.com/user-attachments/assets/220c0e3a-9718-4ea7-9706-cc5084739f30" />



