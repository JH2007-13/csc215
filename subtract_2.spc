# Subtract 2 numbers
# Written by Joshua Harris
# CSC 215 : Computer Systems
# 29 September 2025
3a # 00   LDA 30   Loads the accumulator with the specified address (00x30)
30 # 01            Lower address byte
00 # 02            Higher address byte
47 # 03   MOV A,B  Move the contents of the accumulator to register B
3a # 04   LDA 40   Loads the accumulator with the specified address (00x40)
40 # 05            Lower address byte of the second number
00 # 06            Higher address byte of the second number
90 # 07   SUB B,A  Subtracts the contents of register B from register A
32 # 08   STA      Stores the accumulator's contents (with the difference from the previous instruction) into an address
50 # 09            Lower address byte of the difference
00 # 0A            Higher address byte of the difference
76 # 0B   HLT      Halts the program
