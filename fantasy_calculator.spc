# Receives fantasy roster's points per position, and compares it to the scoring leaders for Week 4 2025. If your player turns out to be a scoring leader, a counter is updated, which is totaled at the end of the program
# Written by Joshua Harris
# CSC 215 : Computer Systems
# 03 October 2025
21 # 00   LXI HL,50   Loads the address of the program's starting point into memory
50 # 01               Lower address byte
00 # 02               Higher address byte
11 # 03   LXI DE,50   Loads registers D and E with the starting address for each football position's top fantasy score in this order: QB, RB1, WR1, TE, D/ST, K. As the program continues comparing the input values, a counter is increased so that the positions line up (basically, the counter makes sure that when the fourth input score is loaded, it is matched up with the correct high score (TE)).
06 # 04               Lower address byte
00 # 05               Higher address byte
3e # 06   MVI A,31    Loads the first high score, which is 31 (QB)
1f # 07               Specified data value (31)

3e # 08   MVI A,34    Loads the first second high, which is 34 (RB)
CD # 03   CALL        Begins a subroutine that compares the Scoring Leader's Points to values inputted into memory
23 # 04   INX HL      Increments the address in registers H and L by 1 so that the next roster spot can be compared








