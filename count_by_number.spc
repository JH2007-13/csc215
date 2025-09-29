# Counts upwards by a specified number in the RAM, starting at address 00x50
# Written by Joshua Harris
# CSC 215 : Computer Systems
# 29 September 2025
3a # 00   LDA 40     Loads the contents of address 00x40 into the accumulator
40 # 01              Lower address byte
00 # 02              Higher address byte
47 # 03   MOV A,B    Moves the contents of the accumulator into register B
3e # 04   MVI A,0    Loads the accumulator with a specified value (0)
00 # 05              Specified data value
0e # 06   MVI C,0    Loads register C with a specified value (0)
00 # 07              Specified data value
11 # 08   LXI DE,50  Loads registers D and E with a specified value (memory address 50)
50 # 09              Lower address byte
00 # 0A              Higher address byte
3c # 0B   INR A      Increments the accumulator's contents by 1
0c # 0C   INR C      Increments register C's contents by 1      


