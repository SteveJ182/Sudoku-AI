# Sudoku-AI
Ai that can solve a pre-generated sudoku matrix.
Sudoku AI Solver

Creator: Steven Jamaica Cervera
Email: StevenJamaicaCervera@my.unt.edu0
ID: 11237663
Program Description:  The program is a c++ program that generates a randomized board of Sudoku and has an Ai function attempt to solve within 10,000 iterations. The reasoning for 10,000 is because I'm assuming if it can't solve in 10,000 iterations it's not worth it.
                      To compile: Just like a regular c++ file, use the linux terminal and enter g++ Sudoku.cpp, then enter ./a.out.

Issues:  The program has some bugs. The Ai likes follow it's own rules and break the game. The initialized function and the Ai function we're built similarly but the Ai likes to insert numbers even if that spot was deemed full. It could be due to a data segmentation error
          because I'm not using a dynamic array. Also that's another thing an error will appear every so often terminating the program, not sure why but it does.
          The initialize function takes some time to run sometimes, and can take up to 2 minutes to run through if conditions aren't good
          The Ai function likes to follow it's own rules and replace some of the numbers that were initially in the original board, but once the numbers where changed it follows the game's rules that we're set prior,
          and thus the program can actually finish the game with the new board it made for itself, if rarely. I don't know why it does it, I've spent over 10 hours trying to figure that out.
          The program will print a statement every 100 iterations showing it's attempts, so sometimes it'll look like the program has repeat numbers, but that's just it's prior guess.



The program was built around the standard Sudoku Rules:
Following Sudoku rules each row and column has to equal 45 and numbers can only range from 1-9 in a 9x9 matrix, then that means all number from 1-9 must be in the row and column and the last rule, just one number per 3x3 matrix in the 9x9 grid area

Sudoku Rules:
To play Sudoku, the player only needs to be familiar with the numbers from 1 to 9 and be able to think logically. The goal of this game is clear: to fill and complete the grid using the numbers from 1 to 9. The challenging part lays on the restrictions imposed on the player to be able to fill the grid.

Rule 1 - Each row must contain the numbers from 1 to 9, without repetitions
The player must focus on filling each row of the grid while ensuring there are no duplicated numbers. The placement order of the digits is irrelevant.

Every puzzle, regardless of the difficulty level, begins with allocated numbers on the grid. The player should use these numbers as clues to find which digits are missing in each row.

Rule 2 - Each column must contain the numbers from 1 to 9, without repetitions
The Sudoku rules for the columns on the grid are exactly the same as for the rows. The player must also fill these with the numbers from 1 to 9, making sure each digit occurs only once per column.

The numbers allocated at the beginning of the puzzle work as clues to find which digits are missing in each column and their position.

Rule 3 - The digits can only occur once per block (nonet)
A regular 9 x 9 grid is divided into 9 smaller blocks of 3 x 3, also known as nonets. The numbers from 1 to 9 can only occur once per nonet.

In practice, this means that the process of filling the rows and columns without duplicated digits finds inside each block another restriction to the numbers’ positioning.

Rule 4 - The sum of every single row, column and nonet must equal 45
To find out which numbers are missing from each row, column or block or if there are any duplicates, the player can simply count or flex their math skills and sum the numbers. When the digits occur only once, the total of each row, column and group must be of 45.

1+2+3+4+5+6+7+8+9= 45
