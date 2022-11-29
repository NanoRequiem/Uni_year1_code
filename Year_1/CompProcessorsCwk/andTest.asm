
//RAM[3]=RAM[1] NAND RAM[2]
@1
D=M
@2
D=D&M
@3
M=!D

//RAM[4]=RAM[1] OR RAM[2]
@1
D=M
@2
D=D|M
@4
M=D

//RAM[0] = RAM[3] AND RAM[4]
@3
D=M
@4
D=D&M
@0
M=D
