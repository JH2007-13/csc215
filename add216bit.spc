#add 2 16-bit numbers
#Written by Joshua Harris
#CSC 215 : Computer Systems
# 29 September 2025
2a # 00   LHLD       Load the first 16-bit number into registers H and L
30 # 01              Lower address byte
0  # 02              Higher address byte
EB # 03   XCHG       Exchange the H and L registers with D and E registers
2a # 04   LHLD       Load the second 16-bit number into registers H and L
40 # 05              Lower address byte for the second number
00 # 06              Higher address byte for the second number
19 # 07   DAD HL,DE  Add 
22 # 08   SHLD       Store the data in the H and L registers in memory
50 # 09              Lower address byte
00 # 10              Higher address byte
76 # 11   HLT        Halts the program
