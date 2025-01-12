#ifndef NQUEENPROBLEM_H
#define NQUEENPROBLEM_H

#include <array>
#include <iostream>

// The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.


// Function declarations
void run_N_Queen_Solver();
void print_board(const std::array<std::array<bool, 4>, 4>& board);

bool is_row_clear(int x, int y, const std::array<std::array<bool, 4>, 4>& board);
bool is_column_clear(int x, int y, const std::array<std::array<bool, 4>, 4>& board);
bool is_major_diagonal_clear(int x, int y, const std::array<std::array<bool, 4>, 4>& board);
bool is_minor_diagonal_clear(int x, int y, const std::array<std::array<bool, 4>, 4>& board);

bool is_free_from_conflicts(int x, int y, const std::array<std::array<bool, 4>, 4>& board);

void bkt(int y, size_t queens, std::array<std::array<bool, 4>, 4>& board);

#endif // NQUEENPROBLEM_H
