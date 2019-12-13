# Circuit-Simulator


Suppose a circuit description file named circuit.txt has the description for the circuit OUT1 = IN1.IN2 + IN1.IN3

INPUTVAR 3 IN1 IN2 IN3
OUTPUTVAR 1 OUT1
AND IN1 IN2 temp1
AND IN1 IN3 temp2
OR temp1 temp2 OUT1
Then, on executing the program with the above circuit description file, 
The prograg produces the following output:

./first circuit.txt 0000

0000
0010
0100
0110 
1000
1011 
1101 
1111

The output of the first three columns are INPUTVAR IN1, IN2, and IN3 respectively. And the last column denotes the OUTPUTVAR OUT1.
