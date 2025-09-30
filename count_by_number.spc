# Counts upwards by a specified number in the RAM, starting at address 00x50
# Written by Joshua Harris
# CSC 215 : Computer Systems
# 29 September 2025
3a # 00   LDA 40     Loads the contents of address 00x40 into the accumulator (the value which the program will be counting by)
40 # 01              Lower address byte
00 # 02              Higher address byte
47 # 03   MOV A,B    Moves the contents of the accumulator into register B (this number will be compared to the counter, kind of like a for loop)
3e # 04   MVI A,0    Loads the accumulator with a specified value (0)
00 # 05              Specified data value
0e # 06   MVI C,0    Loads register C with a specified value (0) which will serve as the counter
00 # 07              Specified data value
11 # 08   LXI DE,50  Loads registers D and E with a starting address for the upwards counting (memory address 50)
50 # 09              Lower address byte
00 # 0A              Higher address byte
3c # 0B   INR A      Increments the accumulator's contents by 1 (the number which will go into memory)
0c # 0C   INR C      Increments register C's contents by 1 (increments the counter)
b8 # 0D   CMP B      Compares register B with the accumulator, and sets the Zero Status Bit to 1 if both are equal
c2 # 0E   JNZ        Jumps to a specified spot in the code (Line 16) if the Zero Status Bit is 0 (meaning the code is not equal), otherwise continues
0b # 0F              Lower address byte
00 # 10              Higher address byte
12 # 11   STAX DE    Stores the accumulator in the value specified by registers D and E (which is memory value 50)
13 # 12   INX DE     Increments registers D and E, which moves them to the next spot in memory
12 # 13   STAX DE    Stores the accumulator in the specified next spot in memory, which will be added to the counter
0e # 14   MVI C,0    Resets register C to a specified data value (0), restarting the counter
00 # 15              Specified data value
1a # 16   LDAX DE    Loads the next value into the accumulator to start incrementing
c3 # 17   JMP        Jumps to a specified spot in the code (Line 16) and restarts the incrementation cycle for the next value
==
40:03
