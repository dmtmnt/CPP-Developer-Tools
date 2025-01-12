#include "NQueenProblem.h"

void print_board(const std::array<std::array<bool, 4>, 4> &board)
{

    for (size_t i = 0; i < board.size(); ++i)
    {
        for (size_t j = 0; j < board[i].size(); ++j)
        {
            char x = board[i][j] ? 'Q' : '_';
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

bool is_row_clear(int x, int y, const std::array<std::array<bool, 4>, 4> &board)
{
    for (size_t j = 0; j < board[x].size(); ++j)
    {
        if (board[x][j])
            return false;
    }
    return true;
}

bool is_column_clear(int x, int y, const std::array<std::array<bool, 4>, 4> &board)
{
    for (size_t i = 0; i < board.size(); ++i)
    {
        if (board[i][y])
            return false;
    }
    return true;
}

bool is_major_diagonal_clear(int x, int y, const std::array<std::array<bool, 4>, 4> &board)
{
    int new_x = x - 1;
    int new_y = y - 1;
    while (new_x >= 0 && new_y >= 0)
    {
        if (board[new_x][new_y])
            return false;
        --new_x;
        --new_y;
    }
    new_x = x + 1;
    new_y = y + 1;
    while (new_x < board.size() && new_y < board[new_x].size())
    {
        if (board[new_x][new_y])
            return false;
        ++new_x;
        ++new_y;
    }
    return true;
}

bool is_minor_diagonal_clear(int x, int y, const std::array<std::array<bool, 4>, 4> &board)
{
    int new_x = x - 1;
    int new_y = y + 1;
    while (new_x >= 0 && new_y < board[new_x].size())
    {
        if (board[new_x][new_y])
            return false;
        --new_x;
        ++new_y;
    }
    new_x = x + 1;
    new_y = y - 1;
    while (new_x < board.size() && new_y >= 0)
    {
        if (board[new_x][new_y])
            return false;
        ++new_x;
        --new_y;
    }
    return true;
}

bool is_free_from_conflicts(int x, int y, const std::array<std::array<bool, 4>, 4> &board)
{
    return is_row_clear(x, y, board) &&
           is_column_clear(x, y, board) &&
           is_major_diagonal_clear(x, y, board) &&
           is_minor_diagonal_clear(x, y, board);
}

void bkt(int y, size_t queens, std::array<std::array<bool, 4>, 4> &board)
{
    if (queens == 0)
    {
        std::cout << "Solution to the 4x4 N-Queen problem:" << std::endl;
        print_board(board);
        return;
    }
    
    // Exit recursion if we've attempted to place queens beyond the last column
    if (y >= board[0].size())
        return;

     // Attempt to place a queen in each row of the current column
    for (size_t i = 0; i < board.size(); ++i)
    {
        if (is_free_from_conflicts(i, y, board))
        {
            board[i][y] = true; // Place queen
            --queens;
            bkt(y + 1, queens, board);
            board[i][y] = false; // Remove queen (backtrack)
            ++queens;
        }
    }
}

void run_N_Queen_Solver()
{
    std::array<std::array<bool, 4>, 4> board = {false};
    bkt(0, 4, board);
}