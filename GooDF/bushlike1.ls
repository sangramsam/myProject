# --- L-System Parser/Mutator --- Lj Lapre ----------------------------------
4
45
20
A # for green
A=BCDEGHIJK
B=[~(30)L][;(0.5)CDEGHIJK]
C=[+~(30)L][+;(0.5)CDEGHIJK]
D=[-~(30)L][-;(0.5)CDEGHIJK]
E=[&~(30)L][&;(0.5)CDEGHIJK]
F=F
G=[^~(30)L][&;(0.5)~(10)CDEGHIJK]
H=[>(45)+~(30)L][>(45)+;(0.5)CDEGHIJK]
I=[>(45)-~(30)L][>(45)-;(0.5)CDEGHIJK]
J=[>(45)&~(30)L][>(45)&;(0.5)CDEGHIJK]
K=[>(45)^~(30)L][>(45)^;(0.5)CDEGHIJK]
L=c(7)FM!(0.8)c(10)FM!c(10)(0.8)c(9)FM!(0.8)c(9)FM!(0.8)c(2)FM!(0.8)c(2)FM!(0.8)c(0)FM!(0.8)c(0)FM!(0.8)c(0)FM
@
