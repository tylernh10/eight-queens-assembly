### Eight Queens in Assembly

The task of this project was to take code that would solve the Eight Queens problem in C and use it to aid in solving the problem in the RISC-V assembly language.

The Eight Queens problem consists of the following:
Given a normal chess board (8x8 grid), find a way to place eight unique queens on the board at once such that none of the queens are attacking each other.

The solution found here involves placing a queen in the first row as specified by the user running the program. Then, a "brute force" stategy is employed, attempting to find a place in the second row that does not cause the two queens to be attacking each other. Next, a third queen is placed that cannot be attacking the other two. This strategy is used to place all the queens. The program terminates once a single solution is found.

This was the first honors project for CSE 3666 at UConn.
