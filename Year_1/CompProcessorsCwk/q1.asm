// Register[2] is a pointer to the second value in the XOR

//RAM[3] = RAM[RAM[2]]
@R2
D=M
A=D
D=M
@R3
M=D

//RAM[4]=RAM[1] NAND RAM[3]
@1
D=M
@3
D=D&M
@4
M=!D

//RAM[5]=RAM[1] OR RAM[3]
@1
D=M
@3
D=D|M
@5
M=D

//RAM[0] = RAM[4] AND RAM[5]
@4
D=M
@5
D=D&M
@0
M=D

//Stops the program for running forever
@25
0;JMP
